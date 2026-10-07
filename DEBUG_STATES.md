# Debug Game States

Quick-jump states for testing specific game sections without full playthroughs.
Set `int GAMESTATE` in `src/engine/game.cpp` (line 8), then `bgrun`.

## Bob's Original States

These were in the recovered source:

| Value | Name | Description |
|-------|------|-------------|
| 0 | INTRO | Normal game start (intro sequence) |
| 1 | TOWN | Jump to town |
| 3 | GAMETOY | Jump to GameToy (Tetrid via intro dialogue) |

## Our Debug States

Added for systematic testing. **Remove before public release.**

| Value | Name | Description |
|-------|------|-------------|
| 4 | BOBAPT | Jump directly to Bob's apartment (post-Tetrid cutscene) |
| 5 | PINGDBG | Jump downstairs at 6:31 AM Monday (Ping TV available) |

## Usage

```c
// src/engine/game.cpp, line 8
int GAMESTATE= 5;  // Change this number
```

Then run `bgrun` (pulls, builds, runs).

## Notes

- `easymode` in `src/main.cpp` enables Demo 2 easy mode for Tetrid (lowers level thresholds). Set to 1 for testing, revert to 0 before release.
- Debug states are scaffolding, not part of Bob's design. They let us crawl through the game moment-by-moment to find and fix bugs systematically.
