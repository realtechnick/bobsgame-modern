// SDL3_mixer stub for Bob's Game
// Audio is disabled when SDL3_mixer is not available.
// To enable audio: install SDL3_mixer and remove this stub from the include path.
//
// This is a minimal stub providing the SDL_mixer API used by Bob's Game.
// All functions are no-ops returning safe defaults.

#ifndef SDL_MIXER_H
#define SDL_MIXER_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

// Opaque types
typedef struct Mix_Chunk { int dummy; } Mix_Chunk;
typedef struct Mix_Music { int dummy; } Mix_Music;

#define MIX_MAX_VOLUME 128
#define MIX_DEFAULT_FREQUENCY 22050

// Audio device management (no-op)
static inline int Mix_OpenAudio(int devid, const SDL_AudioSpec* spec) { (void)devid; (void)spec; return 0; }
static inline void Mix_CloseAudio(void) {}

// Channel management (no-op)
static inline int Mix_AllocateChannels(int n) { return n; }

// Sample loading (returns dummy pointer)
static inline Mix_Chunk* Mix_LoadWAV(const char* f) { (void)f; return (Mix_Chunk*)1; }
static inline void Mix_FreeChunk(Mix_Chunk* c) { (void)c; }

// Music loading (returns dummy pointer)
static inline Mix_Music* Mix_LoadMUS(const char* f) { (void)f; return (Mix_Music*)1; }
static inline void Mix_FreeMusic(Mix_Music* m) { (void)m; }

// Playback (no-op)
static inline int Mix_PlayChannel(int ch, Mix_Chunk* c, int l) { (void)ch; (void)c; (void)l; return 0; }
static inline int Mix_PlayMusic(Mix_Music* m, int l) { (void)m; (void)l; return 0; }
static inline int Mix_FadeInMusic(Mix_Music* m, int l, int ms) { (void)m; (void)l; (void)ms; return 0; }
static inline int Mix_FadeOutMusic(int ms) { (void)ms; return 0; }
static inline void Mix_HaltMusic(void) {}
static inline void Mix_HaltChannel(int ch) { (void)ch; }
static inline int Mix_PlayingMusic(void) { return 0; }
static inline int Mix_PausedMusic(void) { return 0; }
static inline void Mix_PauseMusic(void) {}
static inline void Mix_ResumeMusic(void) {}

// Volume (no-op, returns input)
static inline int Mix_VolumeMusic(int v) { return v; }
static inline int Mix_Volume(int ch, int v) { (void)ch; return v; }
static inline int Mix_VolumeChunk(Mix_Chunk* c, int v) { (void)c; return v; }

// Callbacks (no-op)
static inline void Mix_HookMusicFinished(void (*f)(void)) { (void)f; }

// Query (returns dummy)
static inline Mix_Chunk* Mix_GetChunk(int ch) { (void)ch; return (Mix_Chunk*)1; }

#ifdef __cplusplus
}
#endif

#endif // SDL_MIXER_H
