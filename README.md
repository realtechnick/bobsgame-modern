# Bob's Game Resurrection — Modern SDL3 Port

A preservation port of Robert Pelloni's cult DS homebrew **Bob's Game** (2003-2009), recovered from the original C++ source.

## About

Bob's Game is a 2D RPG/life-sim by Robert Pelloni. This port migrates the original
SDL2/OpenGL codebase to SDL3 for modern systems. This is preservation work —
Pelloni has passed away, and this may be among the last surviving copies of the source.

**Original source:** `bobsgamed/okClassic` (96 .cpp, 101 .h files, ~5.4MB)
**Supplemental data:** `bobsgame/BobsGameOnline` v8830 (257 maps, 37 more than okClassic)

## Building

### Requirements
- CMake 3.16+
- C++11 compiler (GCC, Clang, MSVC)
- SDL3 (3.2.10+)
- SDL3_ttf (3.2.2+)
- OpenGL

### Linux
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
./bobsgame
```

### Audio
Audio is **disabled by default** (game runs silent). SDL3_mixer doesn't build
against SDL 3.2.10 (requires 3.4+ APIs). To enable:
```bash
cmake -DBOBSGAME_ENABLE_AUDIO=ON ..
```
Requires system SDL3_mixer.

### macOS
```bash
brew install sdl3 sdl3_ttf
mkdir build && cd build
cmake ..
make -j$(sysctl -n hw.ncpu)
./bobsgame
```

## Project Structure

```
src/                    # C++ source (96 .cpp, 99 .h)
  engine/               # Core engine (rendering, game loop, audio)
  gamelogic/            # Game logic (maps, NPCs, dialogue)
  minigame/             # Minigames (tetrid, ramio, ping, etc.)
  shaders/              # GLSL shaders
  GL/                   # Bundled GLEW headers
data/                   # Original game data (68MB, from okClassic)
data_v8830/             # Supplemental v8830 data (242MB, 37 extra maps)
cmake/stubs/            # Stub headers (SDL3_mixer when audio disabled)
web-build/              # Emscripten/WebAssembly build config
```

## Data

The game requires data files at runtime. Two datasets are included:

- **`data/`** (68MB): Original data from okClassic. 225 unique maps.
- **`data_v8830/`** (242MB): Supplemental from BobsGameOnline v8830. 257 maps
  (37 more than okClassic, including ALPHA maps and CITYNorthSide).

The v8830 data is **not yet integrated** into the runtime — it's archived for
future use. The game currently loads from `data/`.

## Status

- ✅ Compiles on Linux (GCC, 1.6MB binary)
- ✅ SDL2 → SDL3 migration complete
- ✅ All 96 source files build
- ❌ Audio disabled (SDL3_mixer stub)
- ❌ Not yet runtime-tested (no display on build server)
- ❌ v8830 data not integrated
- ❌ Web build has issues (see web-build/README.md)

## License

Original code by Robert Pelloni (2003-2009). Treated as freeware/abandonware
for preservation purposes. This port is for personal/preservation use.
