#!/bin/bash
# setup-gbev.command — One-click Mac setup for Bob's Game tester
#
# Double-click this file. It will:
#   1. Install Homebrew (if missing)
#   2. Install SDL3 libraries
#   3. Clone the bobsgame-modern repo
#   4. Set up the `bgrun` command
#   5. Open a new Terminal ready to play
#
# After setup, just type `bgrun` in any new Terminal to pull, build, and play.

set -e

echo "=========================================="
echo " Bob's Game — Mac Setup"
echo "=========================================="
echo ""

# --- 1. Homebrew ---
if ! command -v brew &> /dev/null; then
    echo "Installing Homebrew (this takes a few minutes)..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    
    # Add brew to PATH for Apple Silicon
    if [ -f "/opt/homebrew/bin/brew" ]; then
        eval "$(/opt/homebrew/bin/brew shellenv)"
        echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zprofile
    fi
else
    echo "✓ Homebrew already installed"
fi

# --- 2. SDL3 libraries ---
echo ""
echo "Installing SDL3 libraries..."
brew install sdl3 sdl3_ttf sdl3_mixer 2>&1 | tail -5
echo "✓ SDL3 libraries installed"

# --- 3. Clone repo ---
REPO_DIR="$HOME/bobsgame-modern"
if [ ! -d "$REPO_DIR" ]; then
    echo ""
    echo "Cloning bobsgame-modern..."
    git clone https://github.com/realtechnick/bobsgame-modern.git "$REPO_DIR"
    echo "✓ Repo cloned to $REPO_DIR"
else
    echo "✓ Repo already exists at $REPO_DIR"
fi

# --- 4. Set up bgrun ---
# bgrun: pull latest, build, and run the game
BGRUN_FUNC='
bgrun() {
    cd ~/bobsgame-modern || return 1
    echo "Pulling latest..."
    git pull
    echo "Building..."
    mkdir -p build && cd build
    cmake -DBOBSGAME_ENABLE_AUDIO=ON .. > /dev/null
    make -j$(sysctl -n hw.ncpu)
    echo "Running..."
    ./bobsgame 2>&1 | pbcopy
    echo "Done! (output copied to clipboard)"
}
'

# Add to .zshrc if not already there
if ! grep -q "bgrun()" ~/.zshrc 2>/dev/null; then
    echo "$BGRUN_FUNC" >> ~/.zshrc
    echo "✓ bgrun command installed (restart Terminal or run: source ~/.zshrc)"
else
    echo "✓ bgrun already set up"
fi

# --- 5. Data ---
# Game data/ is in the git repo, cloned automatically above.
echo "✓ Game data included via git"

echo ""
echo "=========================================="
echo " Setup complete!"
echo "=========================================="
echo ""
echo "Open a new Terminal window and type:"
echo ""
echo "    bgrun"
echo ""
echo "This pulls the latest code, builds, and runs the game."
echo ""
echo "Press Enter to open a new Terminal..."
read

open -a Terminal
