# Bob's Game Web Build (Emscripten)

## Overview
This directory contains the Emscripten/WebAssembly build configuration for Bob's Game.

## Build
```bash
./build_web.sh
```
Output: `../build-web/bobsgame.{html,js,wasm,data}`

## Emscripten-Specific Changes

### 1. GLEW Stub (`stubs/GL/glew.h`)
The game uses GLEW for OpenGL extension loading. WebGL doesn't need GLEW.
- `glewInit()` is a no-op returning 0 (success)
- EXT framebuffer functions are stubbed (see below)
- The real `src/GL/glew.h` is temporarily moved aside during web builds

### 2. SDL_mixer Stub (`stubs/SDL3_mixer/SDL_mixer.h`)
Audio is disabled for web builds (SDL3_mixer doesn't build for Emscripten yet).
All mixer functions are no-ops. The game runs silent.

### 3. Legacy OpenGL Emulation
The game uses legacy OpenGL (glEnableClientState, glVertexPointer, etc.).
Build uses `-s LEGACY_GL_EMULATION=1` to emulate these on WebGL.

### 4. Framebuffer Handling
**KNOWN ISSUE:** The game creates a 1920x1080 framebuffer texture with
GL_RGBA8/GL_BGRA which WebGL rejects. Currently stubbed as no-ops.
This needs a proper shim that converts formats. See:
https://github.com/realtechnick/bobsgame-modern/issues (TBD)

### 5. Shaders
The game loads shaders from `shaders/` directory:
- `shaders/coord.vert`
- `shaders/nothing.frag`
- `shaders/gamma.frag`
- `shaders/hdr.frag`

These are preloaded via `--preload-file ../src/shaders@/shaders`.

### 6. Data Files
Game data from `../data/` is preloaded as `/data/` in the virtual filesystem.
The 67MB `bobsgame.data` file contains all game assets.

## Known Issues (from Claude diagnosis 2026-10-05)
1. **Missing shaders** - FIXED (now preloaded)
2. **Invalid framebuffer texture** - NEEDS SHIM (currently no-op)
3. **Memory-out-of-bounds in sprite loading** - Possibly fallout from #2
4. **Audio not set up** - Expected (mixer stubbed)
5. **glLoadIdentity crash** - FIXED (legacy GL emulation init)

## Files
- `build_web.sh` - Main build script
- `stubs/` - Header stubs for Emscripten
- `README.md` - This file
