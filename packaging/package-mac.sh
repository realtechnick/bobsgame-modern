#!/bin/bash
# package-mac.sh — Build a double-clickable macOS .app bundle for Bob's Game
#
# Usage: ./packaging/package-mac.sh
# Run from the repo root after `bgrun` (so build/bobsgame exists).
#
# Creates Bobsgame.app in the repo root. Drag it to the Dock.
# The launcher cds to the repo root so the game finds its data/ directory.
#
# Requirements: macOS with iconutil and sips (both ship with macOS).

set -e

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
APP_NAME="Bobsgame"
APP_DIR="$REPO_ROOT/$APP_NAME.app"
BUILD_BIN="$REPO_ROOT/build/bobsgame"
ICON_SRC="$REPO_ROOT/packaging/bobsgame-icon.png"

if [ ! -f "$BUILD_BIN" ]; then
    echo "Error: $BUILD_BIN not found. Run bgrun first."
    exit 1
fi

if [ ! -d "$REPO_ROOT/data" ]; then
    echo "Warning: $REPO_ROOT/data not found. The game needs it to run."
fi

echo "Creating $APP_NAME.app..."

# Clean previous build
rm -rf "$APP_DIR"
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

# --- Launcher ---
# cds to the repo root (where data/ lives) then runs the real binary.
cat > "$APP_DIR/Contents/MacOS/Bobsgame" << 'LAUNCHER'
#!/bin/bash
# Resolve repo root: .app is expected to sit in the repo root.
APP_MACOS="$(cd "$(dirname "$0")" && pwd)"
REPO_ROOT="$(cd "$APP_MACOS/../../.." && pwd)"
cd "$REPO_ROOT" || exit 1
exec ./build/bobsgame
LAUNCHER
chmod +x "$APP_DIR/Contents/MacOS/Bobsgame"

# --- Icon ---
if [ -f "$ICON_SRC" ]; then
    echo "Building icon.icns..."
    ICONSET="$(mktemp -d)/icon.iconset"
    mkdir -p "$ICONSET"
    for size in 16 32 64 128 256 512; do
        sips -z $size $size "$ICON_SRC" --out "$ICONSET/icon_${size}x${size}.png" > /dev/null
        sips -z $((size*2)) $((size*2)) "$ICON_SRC" --out "$ICONSET/icon_${size}x${size}@2x.png" > /dev/null
    done
    iconutil -c icns "$ICONSET" -o "$APP_DIR/Contents/Resources/icon.icns"
    rm -rf "$(dirname "$ICONSET")"
else
    echo "Warning: $ICON_SRC not found, skipping icon."
fi

# Ad-hoc sign so it runs on Apple Silicon without Gatekeeper complaints
codesign --force --deep --sign - "$APP_DIR" 2>/dev/null || echo "Note: codesign skipped."

echo ""
echo "Done! $APP_DIR"
echo "Drag it to your Dock. Double-click to play."
