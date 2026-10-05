# SDL2 → SDL3 Migration Summary

## Date
2026-10-05

## Files Modified (10 files)

### src/main.h
- `#include "SDL.h"` → `#include <SDL3/SDL.h>`
- `#include "SDL_opengl.h"` → `#include <SDL3/SDL_opengl.h>`
- `#include "SDL_mixer.h"` → `#include <SDL3_mixer/SDL_mixer.h>`
- `#include "SDL_ttf.h"` → `#include <SDL3_ttf/SDL_ttf.h>`
- `LARGE_INTEGER` → `Uint64` (hires_ticks_per_second, newvbltimer, lastvbltimer)
- `#include "GL/wglew.h"` wrapped in `#ifdef _WIN32` (Windows-only)

### src/main.cpp
- `SDL_Init(SDL_INIT_EVERYTHING)` → `SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK | SDL_INIT_EVENTS)`
- `SDL_CreateWindow(title, x, y, w, h, flags)` → `SDL_CreateWindow(title, w, h, flags)` (x,y removed)
- `SDL_ShowCursor(1)` → `SDL_ShowCursor()` (no args in SDL3)
- `SDL_NumJoysticks()` / `SDL_JoystickOpen(0)` → `SDL_GetJoysticks(&count)` / `SDL_OpenJoystick(id)`
- `SDL_JoystickClose(stick)` → `SDL_CloseJoystick(stick)`
- `Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)` → `Mix_OpenAudio(0, &spec)` with SDL_AudioSpec
- `QueryPerformanceCounter/Frequency` → `SDL_GetPerformanceCounter()` / `SDL_GetPerformanceFrequency()`
- `LARGE_INTEGER` → `Uint64` for all timer variables
- `Sleep(2)` → `SDL_Delay(2)` (Windows API → SDL)
- `int ticks = SDL_GetTicks()` → `Uint64 ticks` (SDL3 returns Uint64)
- `wglSwapIntervalEXT` wrapped in `#ifdef _WIN32`, SDL_GL_SetSwapInterval(1) for Linux

### src/engine/main/controls.cpp
- `SDL_JoystickUpdate()` → `SDL_UpdateJoysticks()`
- `SDL_JoystickGetAxis()` → `SDL_GetJoystickAxis()`
- `SDL_JoystickGetHat()` → `SDL_GetJoystickHat()`
- `SDL_JoystickGetButton()` → `SDL_GetJoystickButton()`
- `event.key.keysym.sym` → `event.key.key`
- `SDL_QUIT` → `SDL_EVENT_QUIT`
- `SDL_KEYDOWN` → `SDL_EVENT_KEY_DOWN`
- `SDL_KEYUP` → `SDL_EVENT_KEY_UP`
- `SDL_MOUSEBUTTONDOWN` → `SDL_EVENT_MOUSE_BUTTON_DOWN`
- `SDL_JOYBUTTONDOWN/UP` → `SDL_EVENT_JOYSTICK_BUTTON_DOWN/UP`
- `SDLK_w/a/s/d/q/e/z/x/f` → `SDLK_W/A/S/D/Q/E/Z/X/F` (uppercase in SDL3)
- `SDLK_BACKQUOTE` → `SDLK_GRAVE`

### src/engine/main/error.cpp
- `SDL_CreateRGBSurface(...)` → `SDL_CreateSurface(w, h, SDL_PIXELFORMAT_RGBA32)`
- `SDL_FreeSurface()` → `SDL_DestroySurface()` (3 occurrences)

### src/engine/main/tilemaps.cpp
- `SDL_CreateRGBSurface(...)` → `SDL_CreateSurface(8, 8, SDL_PIXELFORMAT_RGBA32)`
- `SDL_FreeSurface()` → `SDL_DestroySurface()`

### src/engine/main/sound.cpp
- `#include "SDL_mixer.h"` → `#include <SDL3_mixer/SDL_mixer.h>`
- (Mix_* API calls unchanged - compatible with SDL3_mixer)

### src/engine/main/types.h
- Uncommented `typedef bool BOOL;` (was provided by SDL2, removed in SDL3)

### src/engine/main/debug.cpp, render.cpp, sprites.cpp
- No SDL API changes needed (only types or SDL_GetTicks which is compatible)

## Files NOT Modified (no SDL2-only APIs)
- src/engine/main/controls.h (uses SDL_Event, SDL_Joystick types - unchanged in SDL3)
- src/engine/main/render.h (uses SDL_Surface* type - unchanged)
- src/engine/main/error.h (no SDL usage)
- src/engine/main/misc.h (only `#define SDL 2` constant, not SDL library)

## Build Status
- All 96 .cpp files pass syntax check with SDL3 headers
- CMakeLists.txt created for SDL3 build

## Missing Dependencies (NOT YET AVAILABLE)
- **SDL3_mixer**: Required for audio. Not installed. Code uses `Mix_*` API.
- **SDL3_ttf**: Required for fonts. Not installed. Code uses `TTF_*` API.

These need to be built from source before full compilation/linking.

## Testing
Syntax check passed for all files using:
```
g++ -std=c++11 -fsyntax-only -I ~/workspace/SDL/include -I src <file>
```
(with stub headers for SDL3_mixer/SDL3_ttf in /tmp/sdl3_stubs for testing only)
