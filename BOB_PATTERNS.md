# Bob's Code Patterns — Restoration Field Guide

*Living document of Robert Pelloni's coding habits, architecture decisions, and bug patterns discovered during the SDL3 port (Oct 2026). Read this before touching game logic.*

## Data Formats (The Core Insight)

Bob packed everything tight — he was thinking like a DS developer with 4MB RAM.

| Asset | Format | Notes |
|-------|--------|-------|
| Sprite pixels | `unsigned char` (1 byte/pixel) | Indexed color, not RGBA |
| Tileset pixels | `unsigned char` (1 byte/pixel) | Indexed color |
| Font pixels | `unsigned char` (1 byte/pixel) | Indexed color |
| Map visual layers | `unsigned short` (2 bytes/tile) | |
| Hit/collision layer | `unsigned char` (1 byte/tile) | 0=walkable, 1=blocked |
| FX/camera-boundary layer | `unsigned short` (2 bytes/tile) | Camera stops = value 4 |
| Palettes | `unsigned short` (2 bytes/color) | |
| Metatile clipmap | `unsigned short` | Was `int*`, caused vertical black bars |

**Rule:** If you see vertical lines or garbled pixels, check the data type first. It's almost always a 1/2/4-byte mismatch. The `.bin` files are packed, not padded.

**Critical distinction:** Hit layer (1-byte) and FX layer (2-byte) are DIFFERENT. Reading FX as bytes produces alternating `4,0,4,0` which makes camera boundaries jump violently.

## Memory Management

- **Static arrays everywhere.** Bob didn't do dynamic allocation for game entities. NPC arrays, sprite slots, etc. are all fixed-size statics.
- **Manual lifecycle.** NPCs are created/deleted via `NPC_create_*` / `NPC_delete_npc`. The delete function sets the pointer to NULL.
- **Map-load clearing required.** Static arrays MUST be cleared when `MAP_just_loaded==1`, otherwise they hold dangling pointers to deleted NPCs. This bug hit all 4 school hallways identically.
- **Pointer refresh after creation.** After `NPC_create_npc(npcpp,...)`, any local `NPC* npc = *npcpp` captured BEFORE is stale (still NULL). Must do `npc = *npcpp` after creation. This bug was in both car and bicycle creation.

## The Camera (Don't Touch)

Bob's camera is **intentional and elaborate**. Key lessons:

- Original code moves camera in 1-pixel steps toward target. This is NOT a bug — it's the "flow" Boss remembers.
- The camera reads the FX layer for boundaries and points of interest (doors!). When FX was misread as 1-byte, boundaries jumped and the camera shook violently.
- **Do NOT replace with lerp or instant follow.** Tried both, both were wrong. Bob knew what he was doing.
- During cutscenes, camera bounces between Yuu and NPCs during dialogue (per Boss's recollection, not yet verified in port).

## Debug Code Fossils

- `ERROR_set_error("FunctionName()")` calls are **Bob's printf-debugging**, not real errors. He left them in.
- Many "errors" are normal game states: `*npcpp==NULL` in vehicle creation means "doesn't exist yet, should create if in range" — NOT an error.
- **Do not spam-fix by silencing.** Understand whether it's a real bug or debug leftover. The vehicle functions had BOTH: debug spam AND real logic bugs underneath.

## NPC AI Patterns

- NPCs use `->AI` field as state machine. Values are magic numbers specific to each map function.
- Common pattern: `if(npc->AI==N) if(WalkFunction(&npc,...)) npc->AI=M;`
- **After `NPC_delete_npc(&arr[c])`, subsequent `if(arr[c]->AI==...)` checks WILL crash.** Must NULL-guard each check in the chain, not just the first.
- `NPC_walk_to_xy_intelligenthit_avoidothers_pushmain` takes `NPC**` (pointer to pointer) and can modify the pointer. Always re-check NULL after calling.

## Text System

- Text buffers are `unsigned char*` (1 byte/char). Writing via `int*` corrupts 4 pixels per write.
- `txt.cpp` contains Windows-1252 single-byte literals. **Must use byte-safe edits.** A Python UTF-8 rewrite mangled them and broke compilation.
- Dialogue tags like `<1>`, `<0>`, `<PURPLE>`, `<WHITE>` control speaker/portrait and colors.
- Caption buffers had the same int-vs-byte bug as text.

## Palette / Lighting

- **Dark interior bug** (fixed 2026-10-06): Yuu's house loaded too dark. Root cause was map-load ordering — `load_bg_pals_based_on_time()` runs *before* `MAP_current_map_load_function()`, and nothing reset the palette to a sane baseline for interior maps. Fix: force brightness-0 palette restore in each house map's load function. For the very first map loaded (Yuu's room), also patch the Run function's `MAP_just_loaded` block — the load function may run before the palette is ready on boot.
- Time-of-day still works after this fix: clock refreshes palettes every 15 game-minutes and on map change, so interiors go dark at night normally.
- Historical note: this exact bug plagued Demo 2 PC testing. Bob never cracked it.

## What "Finished" Means

Per Boss (2026-10-06): The game is "fully playable start to finish" but not "finished." There are rooms that feel like sketches, systems that trail off. The restoration goal is to understand Bob's intent well enough to finish it *his* way, not ours.

**Critical historical context** (Boss, 2026-10-06): What we have is Bob's *PC port attempt* of the original DS game. The DS version had a working bottom screen — the "?????" tab was the nD/game console, a major feature. Bob was frustrated to lose the bottom screen in the PC port. The placeholders we see (hardcoded status stats, unimplemented third tab) aren't just unfinished — they're *casualties of the port*. The DS original is lost; this PC codebase is all that survives.

## Trust Hierarchy

1. **Bob's original logic** — especially camera, game feel. Don't "improve" it.
2. **Data format correctness** — get the types right, the rendering follows.
3. **Null safety** — Bob was sloppy with pointers. Guard everything.
4. **Our inventions** — last resort. If we're writing new logic, we're probably misunderstanding his.

## AUX Layer Positioning

- **AUX draw multiplies by ZOOM**: `draw_texture(..., ZOOM*AUX_bg_x, ...)` — positions must account for this.
- Title logo empiric: x=32 centers the 256px logo on 640px screen (not the calculated 192). The ZOOM interaction is non-obvious; when in doubt, test positions empirically.
- The AUX system itself works fine — "invisible" graphics are usually positioning bugs, not texture/data issues.

---
*Last updated: 2026-10-06. Add patterns as discovered.*
