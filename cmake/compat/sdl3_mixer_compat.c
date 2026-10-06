// SDL3_mixer compatibility shim implementation
// Maps SDL2_mixer API to SDL3_mixer 3.x API

#include "sdl3_mixer_compat.h"
#include <stdlib.h>
#include <string.h>

// Internal state
static MIX_Mixer *g_mixer = NULL;
static MIX_Track *g_channel_tracks[32] = {NULL};  // 32 channels max
static MIX_Track *g_music_track = NULL;
static int g_num_channels = 0;
static void (*g_music_finished_callback)(void) = NULL;
static Mix_Music *g_current_music = NULL;

// Helper: create a track for a channel
static MIX_Track *get_channel_track(int channel) {
    if (channel < 0 || channel >= g_num_channels) return NULL;
    if (!g_channel_tracks[channel]) {
        g_channel_tracks[channel] = MIX_CreateTrack(g_mixer);
    }
    return g_channel_tracks[channel];
}

int Mix_OpenAudio(int devid, const SDL_AudioSpec *spec) {
    (void)devid;
    if (g_mixer) return 0;  // Already open
    
    if (!MIX_Init()) {
        return -1;
    }
    
    g_mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, spec);
    if (!g_mixer) {
        return -1;
    }
    
    // Create music track
    g_music_track = MIX_CreateTrack(g_mixer);
    
    return 0;
}

void Mix_CloseAudio(void) {
    if (g_music_track) {
        MIX_DestroyTrack(g_music_track);
        g_music_track = NULL;
    }
    for (int i = 0; i < 32; i++) {
        if (g_channel_tracks[i]) {
            MIX_DestroyTrack(g_channel_tracks[i]);
            g_channel_tracks[i] = NULL;
        }
    }
    if (g_mixer) {
        MIX_DestroyMixer(g_mixer);
        g_mixer = NULL;
    }
    MIX_Quit();
}

int Mix_AllocateChannels(int n) {
    if (n > 32) n = 32;
    if (n < 0) n = 0;
    g_num_channels = n;
    // Pre-create tracks
    for (int i = 0; i < n; i++) {
        get_channel_track(i);
    }
    return n;
}

Mix_Chunk *Mix_LoadWAV(const char *file) {
    if (!file) return NULL;
    
    MIX_Audio *audio = MIX_LoadAudio(g_mixer, file, false);
    if (!audio) return NULL;
    
    Mix_Chunk *chunk = (Mix_Chunk *)calloc(1, sizeof(Mix_Chunk));
    if (!chunk) {
        MIX_DestroyAudio(audio);
        return NULL;
    }
    chunk->audio = audio;
    chunk->volume = MIX_MAX_VOLUME;
    return chunk;
}

void Mix_FreeChunk(Mix_Chunk *chunk) {
    if (!chunk) return;
    if (chunk->audio) {
        MIX_DestroyAudio(chunk->audio);
    }
    free(chunk);
}

int Mix_VolumeChunk(Mix_Chunk *chunk, int volume) {
    if (!chunk) return -1;
    int old = chunk->volume;
    if (volume >= 0) {
        chunk->volume = volume;
    }
    return old;
}

Mix_Music *Mix_LoadMUS(const char *file) {
    if (!file) return NULL;
    
    MIX_Audio *audio = MIX_LoadAudio(g_mixer, file, false);
    if (!audio) return NULL;
    
    Mix_Music *music = (Mix_Music *)calloc(1, sizeof(Mix_Music));
    if (!music) {
        MIX_DestroyAudio(audio);
        return NULL;
    }
    music->audio = audio;
    music->volume = MIX_MAX_VOLUME;
    return music;
}

void Mix_FreeMusic(Mix_Music *music) {
    if (!music) return;
    if (music->audio) {
        MIX_DestroyAudio(music->audio);
    }
    free(music);
}

int Mix_VolumeMusic(int volume) {
    // TODO: Implement via track gain
    (void)volume;
    return MIX_MAX_VOLUME;
}

int Mix_PlayChannel(int channel, Mix_Chunk *chunk, int loops) {
    if (!chunk || !chunk->audio) return -1;
    
    // Find a free channel if -1 specified
    if (channel == -1) {
        for (int i = 0; i < g_num_channels; i++) {
            MIX_Track *track = get_channel_track(i);
            if (track && !MIX_TrackPlaying(track)) {
                channel = i;
                break;
            }
        }
        if (channel == -1) return -1;  // No free channel
    }
    
    MIX_Track *track = get_channel_track(channel);
    if (!track) return -1;
    
    // Stop current playback on this track
    MIX_StopTrack(track, 0);
    
    // Set the audio and play
    if (!MIX_SetTrackAudio(track, chunk->audio)) {
        return -1;
    }
    
    // Set volume via gain (0.0 to 1.0)
    float gain = (float)chunk->volume / (float)MIX_MAX_VOLUME;
    MIX_SetTrackGain(track, gain);
    
    MIX_PlayTrack(track, loops);
    return channel;
}

int Mix_PlayMusic(Mix_Music *music, int loops) {
    if (!music || !music->audio || !g_music_track) return -1;
    
    MIX_StopTrack(g_music_track, 0);
    
    if (!MIX_SetTrackAudio(g_music_track, music->audio)) {
        return -1;
    }
    
    float gain = (float)music->volume / (float)MIX_MAX_VOLUME;
    MIX_SetTrackGain(g_music_track, gain);
    
    g_current_music = music;
    MIX_PlayTrack(g_music_track, loops);
    return 0;
}

int Mix_HaltChannel(int channel) {
    if (channel == -1) {
        // Halt all channels
        for (int i = 0; i < g_num_channels; i++) {
            MIX_Track *track = get_channel_track(i);
            if (track) MIX_StopTrack(track, 0);
        }
        return 0;
    }
    
    MIX_Track *track = get_channel_track(channel);
    if (!track) return -1;
    MIX_StopTrack(track, 0);
    return 0;
}

int Mix_HaltMusic(void) {
    if (g_music_track) {
        MIX_StopTrack(g_music_track, 0);
    }
    g_current_music = NULL;
    return 0;
}

int Mix_PlayingMusic(void) {
    if (!g_music_track) return 0;
    return MIX_TrackPlaying(g_music_track) ? 1 : 0;
}

int Mix_FadeOutMusic(int ms) {
    if (!g_music_track) return 0;
    // SDL3_mixer uses sample frames, not ms. Approximate.
    // For simplicity, just stop. TODO: implement proper fade.
    (void)ms;
    MIX_StopTrack(g_music_track, 0);
    return 1;
}

int Mix_Volume(int channel, int volume) {
    if (channel == -1) {
        // Set all channels - just return max for now
        return MIX_MAX_VOLUME;
    }
    MIX_Track *track = get_channel_track(channel);
    if (!track) return -1;
    if (volume >= 0) {
        float gain = (float)volume / (float)MIX_MAX_VOLUME;
        MIX_SetTrackGain(track, gain);
    }
    return MIX_MAX_VOLUME;
}

void Mix_HookMusicFinished(void (*callback)(void)) {
    g_music_finished_callback = callback;
    // TODO: Hook into track stopped callback
    // For now, store it. The new API has MIX_SetTrackStoppedCallback
}

int Mix_GetChunk(int channel, Mix_Chunk **chunk) {
    // Not directly supported in new API - return error
    (void)channel;
    (void)chunk;
    return -1;
}
