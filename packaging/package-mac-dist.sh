#!/bin/bash
# package-mac-dist.sh — Build a self-contained distributable for sharing
#
# Usage: ./packaging/package-mac-dist.sh
# Run from the repo root on your Mac after building (bgrun).
#
# Creates: Bobsgame-dist.zip containing:
#   - Bob's Game.app (self-contained, with data inside)
#   - README.txt (simple instructions for the recipient)
#
# The recipient just unzips and double-clicks. No repo, no build, no brew needed
# (except they need SDL3 libraries — see below).
#
# REQUIREMENTS for the recipient:
#   - Apple Silicon Mac (or Intel, if you build on Intel)
#   - SDL3, SDL3_ttf, SDL3_mixer installed via Homebrew:
#       brew install sdl3 sdl3_ttf sdl3_mixer
#
# For a truly dependency-free build, we'd need to bundle the .dylibs.
# That's a future improvement.

set -e

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
APP_NAME="Bob's Game"
DIST_DIR="$(mktemp -d)"
APP_DIR="$DIST_DIR/$APP_NAME.app"
BUILD_BIN="$REPO_ROOT/build/bobsgame"
DATA_DIR="$REPO_ROOT/data"

if [ ! -f "$BUILD_BIN" ]; then
    echo "Error: $BUILD_BIN not found. Build first (bgrun)."
    exit 1
fi

if [ ! -d "$DATA_DIR" ]; then
    echo "Error: $DATA_DIR not found. The game needs its data files."
    exit 1
fi

echo "Building self-contained $APP_NAME.app..."

mkdir -p "$APP_DIR/Contents/MacOS"
mkdir -p "$APP_DIR/Contents/Resources"

# --- Info.plist ---
cat > "$APP_DIR/Contents/Info.plist" << 'PLIST'
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleExecutable</key>
    <string>Bobsgame</string>
    <key>CFBundleIconFile</key>
    <string>icon</string>
    <key>CFBundleIdentifier</key>
    <string>com.realtechnick.bobsgame</string>
    <key>CFBundleName</key>
    <string>Bob's Game</string>
    <key>CFBundleDisplayName</key>
    <string>Bob's Game</string>
    <key>CFBundlePackageType</key>
    <string>APPL</string>
    <key>CFBundleShortVersionString</key>
    <string>1.0</string>
    <key>CFBundleVersion</key>
    <string>1</string>
    <key>LSMinimumSystemVersion</key>
    <string>13.0</string>
    <key>NSHighResolutionCapable</key>
    <true/>
    <key>NSHumanReadableCopyright</key>
    <string>Robert Pelloni — recovered source port</string>
</dict>
</plist>
PLIST

# --- Copy binary ---
cp "$BUILD_BIN" "$APP_DIR/Contents/MacOS/Bobsgame"
chmod +x "$APP_DIR/Contents/MacOS/Bobsgame"

# --- Copy data inside the app bundle ---
echo "Copying game data (this may take a moment)..."
cp -R "$DATA_DIR" "$APP_DIR/Contents/Resources/data"

# --- Launcher wrapper ---
# The game expects to run from a directory containing data/.
# We cd to Resources (where data/ lives) before launching.
cat > "$APP_DIR/Contents/MacOS/launcher.sh" << 'LAUNCHER'
#!/bin/bash
APP_RESOURCES="$(cd "$(dirname "$0")/../Resources" && pwd)"
cd "$APP_RESOURCES" || exit 1
exec ./../MacOS/Bobsgame
LAUNCHER
chmod +x "$APP_DIR/Contents/MacOS/launcher.sh"

# Point the bundle executable to the launcher
# (We keep Bobsgame as the actual binary, launcher.sh cds correctly)
mv "$APP_DIR/Contents/MacOS/Bobsgame" "$APP_DIR/Contents/MacOS/Bobsgame.bin"
cat > "$APP_DIR/Contents/MacOS/Bobsgame" << 'WRAPPER'
#!/bin/bash
DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$DIR/../Resources" || exit 1
exec "$DIR/Bobsgame.bin"
WRAPPER
chmod +x "$APP_DIR/Contents/MacOS/Bobsgame"

# --- Icon (if available) ---
ICON_SRC="$REPO_ROOT/packaging/bobsgame-icon.png"
if [ -f "$ICON_SRC" ]; then
    echo "Building icon..."
    ICONSET="$(mktemp -d)/icon.iconset"
    mkdir -p "$ICONSET"
    for size in 16 32 64 128 256 512; do
        sips -z $size $size "$ICON_SRC" --out "$ICONSET/icon_${size}x${size}.png" > /dev/null 2>&1
        sips -z $((size*2)) $((size*2)) "$ICON_SRC" --out "$ICONSET/icon_${size}x${size}@2x.png" > /dev/null 2>&1
    done
    iconutil -c icns "$ICONSET" -o "$APP_DIR/Contents/Resources/icon.icns" 2>/dev/null
    rm -rf "$(dirname "$ICONSET")"
fi

# Ad-hoc sign
codesign --force --deep --sign - "$APP_DIR" 2>/dev/null || true

# --- README for recipient ---
cat > "$DIST_DIR/README.txt" << 'README'
Bob's Game — Mac Test Build
============================

This is a preservation port of Robert Pelloni's Bob's Game (DS homebrew RPG).

TO PLAY:
1. Double-click "Bob's Game.app"
2. If macOS says it's from an unidentified developer:
   Right-click → Open → Open

REQUIREMENTS:
- Apple Silicon Mac (M1/M2/M3/M4/M5)
- macOS 13.0 or later
- SDL3 libraries (install via Homebrew):
    brew install sdl3 sdl3_ttf sdl3_mixer

CONTROLS:
- Arrow keys / WASD: Move
- Z / Enter: Action button
- X / Shift: Cancel button

This is a test build — expect bugs! Report them to Nick.

Built from: https://github.com/realtechnick/bobsgame-modern
README

# --- Zip it ---
cd "$DIST_DIR"
zip -qr "$REPO_ROOT/Bobsgame-dist.zip" "Bob's Game.app" README.txt
cd "$REPO_ROOT"

echo ""
echo "Done! Created: $REPO_ROOT/Bobsgame-dist.zip"
echo ""
echo "Share this zip with your tester. They unzip and double-click."
echo "They'll need: brew install sdl3 sdl3_ttf sdl3_mixer"
