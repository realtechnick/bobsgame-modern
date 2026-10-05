// Stub SDL_mixer.h for SDL3_mixer API (Emscripten build - audio disabled)
#ifndef SDL_MIXER_H
#define SDL_MIXER_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Mix_Chunk { int dummy; } Mix_Chunk;
typedef struct Mix_Music { int dummy; } Mix_Music;

#define MIX_MAX_VOLUME 128

static inline int Mix_OpenAudio(int devid, const SDL_AudioSpec* spec) { return 0; }
static inline void Mix_CloseAudio(void) {}
static inline int Mix_AllocateChannels(int n) { return n; }
static inline Mix_Chunk* Mix_LoadWAV(const char* f) { return (Mix_Chunk*)1; }
static inline Mix_Music* Mix_LoadMUS(const char* f) { return (Mix_Music*)1; }
static inline void Mix_FreeChunk(Mix_Chunk* c) {}
static inline void Mix_FreeMusic(Mix_Music* m) {}
static inline Mix_Chunk* Mix_GetChunk(int ch) { return (Mix_Chunk*)1; }
static inline int Mix_PlayChannel(int ch, Mix_Chunk* c, int l) { return 0; }
static inline int Mix_PlayMusic(Mix_Music* m, int l) { return 0; }
static inline int Mix_FadeOutMusic(int ms) { return 0; }
static inline void Mix_HaltMusic(void) {}
static inline void Mix_HaltChannel(int ch) {}
static inline int Mix_PlayingMusic(void) { return 0; }
static inline void Mix_HookMusicFinished(void (*f)(void)) {}
static inline int Mix_VolumeMusic(int v) { return v; }
static inline int Mix_Volume(int ch, int v) { return v; }
static inline int Mix_VolumeChunk(Mix_Chunk* c, int v) { return v; }

#ifdef __cplusplus
}
#endif

#endif
