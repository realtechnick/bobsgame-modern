#!/bin/bash
# Emscripten web build for Bob's Game
set -e

source ~/workspace/emsdk/emsdk_env.sh > /dev/null 2>&1

cd ~/workspace/bobsgame-modern
mkdir -p build-web
cd build-web

# Collect all source files (excluding glew.c, we use stub)
SOURCES=$(find ../src -name "*.cpp" | tr '\n' ' ')

echo "Compiling $(echo $SOURCES | wc -w) files..."

em++ $SOURCES \
  -o bobsgame.html \
  -std=c++11 -Wno-narrowing \
  -O2 \
  -I../web-build/stubs \
  -I../src \
  -I../web-build/stubs \
  -s USE_SDL=3 \
  -s USE_SDL_TTF=3 \
  -s LEGACY_GL_EMULATION=1 \
  -s ALLOW_MEMORY_GROWTH=1 \
  -s FORCE_FILESYSTEM=1 \
  -fexceptions \
  -stdlib=libc++ \
  --preload-file ../data@/data \
  --preload-file ../src/shaders@/shaders \
  2>&1 | tail -20

echo "Build complete!"
ls -lh bobsgame.* 2>/dev/null || echo "No output files"
