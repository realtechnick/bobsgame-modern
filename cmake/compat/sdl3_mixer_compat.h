// SDL3_mixer compatibility shim for Bob's Game
// Implements the SDL2_mixer API (Mix_*) using SDL3_mixer 3.x (MIX_*)
// 
// This allows Bob's Game audio code (written for SDL2_mixer) to work
// with SDL3_mixer 3.x without rewriting all call sites.

#ifndef SDL3_MIXER_COMPAT_H
#define SDL3_MIXER_COMPAT_H

#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>

#ifdef __cplusplus
extern "C" {
#endif

// Opaque types matching SDL2_mixer API
typedef struct Mix_Chunk {
    MIX_Audio *audio;  // Underlying SDL3_mixer audio object
    int volume;        // 0-128
} Mix_Chunk;

typedef struct Mix_Music {
    MIX_Audio *audio;  // Underlying SDL3_mixer audio object
    int volume;        // 0-128
} Mix_Music;

#define MIX_MAX_VOLUME 128
#define MIX_DEFAULT_FREQUENCY 44100
#define MIX_DEFAULT_FORMAT SDL_AUDIO_S16
#define MIX_DEFAULT_CHANNELS 2

// Mixer device management
int Mix_OpenAudio(int devid, const SDL_AudioSpec *spec);
void Mix_CloseAudio(void);

// Channel management
int Mix_AllocateChannels(int n);
Mix_Chunk *Mix_GetChunk(int channel);

// Chunk operations
Mix_Chunk *Mix_LoadWAV(const char *file);
void Mix_FreeChunk(Mix_Chunk *chunk);
int Mix_VolumeChunk(Mix_Chunk *chunk, int volume);

// Music operations  
Mix_Music *Mix_LoadMUS(const char *file);
void Mix_FreeMusic(Mix_Music *music);
int Mix_VolumeMusic(int volume);

// Playback
int Mix_PlayChannel(int channel, Mix_Chunk *chunk, int loops);
int Mix_PlayMusic(Mix_Music *music, int loops);
int Mix_HaltChannel(int channel);
int Mix_HaltMusic(void);
int Mix_PlayingMusic(void);
int Mix_FadeOutMusic(int ms);

// Volume
int Mix_Volume(int channel, int volume);

// Callbacks
void Mix_HookMusicFinished(void (*callback)(void));

#ifdef __cplusplus
}
#endif

#endif // SDL3_MIXER_COMPAT_H
