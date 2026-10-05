# Building Bob's Game on macOS

## Prerequisites

Install dependencies via Homebrew:
```bash
brew install cmake sdl3 sdl3_ttf
```

Note: SDL3_mixer is optional. The game builds without audio by default
(uses a stub header). To enable audio, install sdl3_mixer separately
and build with `-DBOBSGAME_ENABLE_AUDIO=ON`.

## Build Steps

```bash
# Clone the repo
git clone https://github.com/realtechnick/bobsgame-modern.git
cd bobsgame-modern

# Configure
mkdir build && cd build
cmake ..

# Build (use all CPU cores)
make -j$(sysctl -n hw.ncpu)

# Run
./bobsgame
```

The game expects the `data/` directory to be in the working directory.
Run from the `build/` folder, or copy the binary to the project root.

## Troubleshooting

**"SDL3 not found"**: Make sure `brew install sdl3` succeeded and
`/opt/homebrew/include/SDL3/` exists (Apple Silicon) or
`/usr/local/include/SDL3/` (Intel).

**"Audio disabled"**: This is normal. The game runs silent by default.
See README.md for audio setup.

**Window doesn't appear**: The game needs a display. Make sure you're
not SSH'd without X forwarding.

## What to Test

1. Does the window open? (Should be 960x640)
2. Do you see the title screen?
3. Can you navigate with keyboard? (Arrow keys, Enter, Esc)
4. Does the game load maps? (Try starting a new game)
5. Any crashes? (Note what you were doing)

Report any issues with:
- What you did
- What happened vs what you expected
- Any error messages in Terminal
