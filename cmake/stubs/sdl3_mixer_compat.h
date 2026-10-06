// Audio-OFF counterpart to cmake/compat/sdl3_mixer_compat.h.
//
// Game sources include <sdl3_mixer_compat.h> unconditionally. When audio is
// disabled, cmake/stubs is on the include path, so this resolves the include
// to the no-op stub header below and the game builds silent.

#ifndef BOBSGAME_SDL3_MIXER_COMPAT_H
#define BOBSGAME_SDL3_MIXER_COMPAT_H

#include <SDL3_mixer/SDL_mixer.h>

#endif // BOBSGAME_SDL3_MIXER_COMPAT_H
