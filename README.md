# Micro_Kiel — 8051 Microcontroller Lab Programs (Keil µVision)

A collection of Intel 8051 / AT89C51 assembly (`.asm`) and embedded-C (`.c`) lab programs
developed and simulated in **Keil µVision (MCS-51 toolchain)**. Covers arithmetic,
code conversions, block operations, sorting, searching, counters, and waveform generation.

> Target devices: `AT89C51` and `AT89C51RD2`. No package manager, no runtime
> dependencies, no environment variables — just Keil µVision and an 8051 simulator.

## Problem Statement & Objectives

Learning and demonstrating core 8051 concepts:

- Data transfer, arithmetic (`ADD`, `SUBB`, `MUL`, `DIV`), and logical instructions.
- Code conversions (hex / decimal / BCD / ASCII).
- Block move / exchange, largest / smallest search, bubble sort (ascending / descending).
- Bit counting, BCD counters, timer-free delay loops.
- Embedded-C I/O: square-wave and staircase (triangle) waveform output on port pins.

## Features / Program Catalog

### 8-bit & 16-bit arithmetic

| File | Description | I/O (memory) |
|---|---|---|
| `add.asm` | 8-bit addition demo | `A←12H`, `B←12H`, `A←A+B` |
| `ADD16BIT.asm` | 16-bit addition with carry | `40H:41H + 50H:51H → 60H:61H`, carry → `62H` |
| `SUB16.asm` | 16-bit subtraction with borrow | `40H:41H − 50H:51H → 60H:61H`, borrow → `62H (=FFH)` |
| `mul.asm` | 16×16-bit multiply → 32-bit result | `20H:21H × 40H:41H → 60H–63H` |
| `DIV.asm` | 8-bit division using external memory | `XRAM 2000H ÷ 2001H → quot @2010H, rem @2011H` |
| `CUBE.asm` | Cube of an 8-bit number (24-bit result) | `byte @20H → 60H–62H` |
| `avrg.asm` | Average of 5 bytes (quotient + remainder) | `50H–54H → quot @60H, rem @61H` |
| `DES.asm` | Average of 5 bytes (variant, result at 50H) | `40H–44H → quot @50H, rem @51H` |

### Code conversions

| File | Description | I/O |
|---|---|---|
| `hex-deci.asm` | Hex byte → 3 BCD digits (hundreds/tens/ones) | `40H → 41H, 42H, 43H` |
| `deci-hex.asm` | Packed-decimal-style → hex conversion | `40H → 41H` |
| `bcd-ascii.asm` | Packed BCD byte → 2 ASCII characters | `40H → 41H, 42H` |
| `ascii-bcd.asm` | 2 ASCII nibbles → packed BCD byte | `40H, 41H → 42H` |

### Block, search, sort, bit operations

| File | Description | I/O |
|---|---|---|
| `BLCK_TANF.asm` | Block transfer, 4 bytes | `40H–43H → 50H–53H` |
| `BLCK_EXCH.asm` | Block exchange, 4 bytes | `40H–43H ↔ 50H–53H` |
| `LARGST.asm` | Largest of 5 bytes | `40H–44H → 50H` |
| `SMLST.asm` | Smallest of 5 bytes | `40H–44H → 50H` |
| `ASCNDG.asm` | Bubble sort, ascending | 4 bytes @ `40H–43H` sorted in place |
| `DESCND.asm` | Bubble sort, descending | 4 bytes @ `40H–43H` sorted in place |
| `count_ones_zeros.asm` | Count 1s and 0s in a byte | `byte @40H → zeros R2, ones R3` |
| `binary-logical.asm` | Bit-addressable logical ops demo (`ANL`/`ORL` on `C`) | result @ `18H` |
| `practise.asm` | Boolean expression on bits `00H/01H/20H` | result @ `08H` |
| `dsimple.asm` (`dsimple` is an identical copy) | Indirect-addressing move demo | `@40H → @41H` |

### Counters (with `DA A` BCD correction, output on P1)

| File | Description |
|---|---|
| `UP_COUNT.asm` | BCD up-counter from `40H` to `41H` on `P1` with delay subroutine |
| `DOWN_COUNT.asm` | BCD down-counter from `40H` to `41H` on `P1` with delay subroutine |

### Embedded C (AT89C51RD2, `at89c51xd2.h`)

| File | Description |
|---|---|
| `practise.c` / `squarewave.c` | Square wave on `P0` (toggle `0x00`/`0xFF` with delay loop) |
| `triangle_wave.c` | Staircase triangle wave on `P0` (`0x00→0x7F→0x00`) |

### Keil project files

| File | Device | Contains |
|---|---|---|
| `cjd.uvproj` | AT89C51 | 12 assembly files (`BLCK_EXCH`, `BLCK_TANF`, `LARGST`, `SMLST`, `DESCND`, `ADD16BIT`, `SUB16`, `mul`, `DIV`, `UP_COUNT`, `DOWN_COUNT`, `CUBE`) |
| `simple.uvproj` | AT89C51RD2 | `practise.asm` |
| `STARTUP.A51` | — | Standard Keil C51 startup code (unmodified) |
| `mul.a51` | — | Empty (0-byte) placeholder file |

> Note: `ex.uvopt` / `ex.uvgui.cheth` exist without a matching `ex.uvproj`
> (orphaned Keil session files). `dsimple` (no extension) is a byte-identical
> duplicate of `dsimple.asm`. Both are left untouched; see § Folder Structure.

## Technologies Used

- **Assembly:** Intel 8051 assembly (Keil A51 assembler)
- **C:** Embedded C, Keil C51 compiler (`at89c51xd2.h` / `REGX51.H` device headers)
- **IDE / toolchain:** Keil µVision 4/5, MCS-51 toolset (`A51`, `C51`, `LX51`/`BL51`, `OH51`)
- **Simulation:** Keil debugger simulator (`S8051.DLL`, `DP51.DLL`); no external hardware required
- **No third-party libraries, no package manager.**

## Project Architecture / Folder Structure

```text
Micro_Kiel/
├── *.asm                  # 8051 assembly lab programs (see catalog above)
├── *.c                    # Embedded-C programs (square / triangle wave)
├── STARTUP.A51            # Keil standard 8051 startup code
├── mul.a51                # Empty placeholder (0 bytes)
├── dsimple                # Duplicate of dsimple.asm (no extension)
├── cjd.uvproj             # Keil project: AT89C51, 12 asm files
├── simple.uvproj          # Keil project: AT89C51RD2, practise.asm
├── *.uvopt / *.uvgui.*    # Keil per-user session/window state (ignored by git)
├── Objects/               # Keil build output: .obj, .hex, .lnp, .m51 (ignored by git)
├── Listings/              # Keil listings: .lst, .m51 (ignored by git)
├── README.md
├── CONTRIBUTING.md
└── .gitignore
```

`Objects/` and `Listings/` are **regenerated on every build** and are intentionally
not tracked (see `.gitignore`).

## Prerequisites

1. **Windows** PC (Keil µVision is Windows-only).
2. **Keil µVision 4 or 5** with **C51 / MCS-51 support** installed
   (evaluation version suffices for these small programs).
   Download from the Keil website; C51 support may require the separate PK51 package.
3. No additional SDKs, toolchains, or hardware needed — all programs run in the
   built-in simulator. Optional: an AT89C51/AT89C51RD2 board + programmer to run on hardware.

## Installation

No installation step — this repo is source-only.

```bat
git clone <your-repo-url>.git
cd Micro_Kiel
```

Then open `cjd.uvproj` or `simple.uvproj` in Keil µVision.

> Other `.asm`/`.c` files not referenced by a `.uvproj` can be added to a project
> via *Project → Add Existing Files*, or opened standalone for simulation.

## How to Run Locally

### Option A — open an existing project (recommended)

1. Open Keil µVision.
2. `Project → Open Project` → select `cjd.uvproj` (AT89C51) or `simple.uvproj` (AT89C51RD2).
3. `Project → Build Target` (F7) — check `Objects/` for `.hex`/`.lst` output.
4. `Debug → Start/Stop Debug Session` (Ctrl+F5) — runs the simulator.
5. Preload test data in the simulator as needed, e.g. in the *Memory* window
   (`40H–44H` for sort/search/average programs), then `Debug → Run` (F5).
6. Observe results in the *Memory / Watch / Registers* windows (assembly) or
   *Port 0/1* windows (counters, waveforms).

### Option B — run a single standalone file

1. Create a new µVision project for device `AT89C51` (or `AT89C51RD2` for the `.c` files).
2. Add any single `.asm` or `.c` file to *Source Group 1*.
3. Build (F7) → Debug (Ctrl+F5) → Run (F5).

### Device / memory notes

- `DIV.asm` uses **external data memory** (`MOVX` @ `2000H/2001H/2010H/2011H`) —
  verify XRAM is enabled in *Options for Target → Target* if simulating.
- `UP_COUNT` / `DOWN_COUNT` output on **P1**; `squarewave` / `triangle_wave` output on **P0**.
- `*.c` files include `<at89c51xd2.h>` — they require the AT89C51RD2 device headers
  shipped with Keil; use an AT89C51RD2 target (like `simple.uvproj`).

Example commands (no shell commands needed — everything is done inside µVision):

```text
Build:   Project → Build Target (F7)
Rebuild: Project → Rebuild all target files
Simulate: Debug → Start/Stop Debug Session (Ctrl+F5), then Run (F5)
```

## Usage Instructions

Each assembly program documents its memory map in the table above. General workflow:

1. Load the program in the simulator.
2. Before running, write input bytes to the documented addresses
   (e.g. `40H–43H` for `ASCNDG.asm` / `DESCND.asm`, `50H–54H` for `avrg.asm`).
3. Run to `END` (or to the infinite loop for counters / waveform programs).
4. Read outputs from the documented addresses, registers (`A`, `B`, `R2/R3`), or port windows.

## Screenshots

Screenshots are not yet included. Suggested additions:

- `docs/screenshots/build-output.png` — successful build output window
- `docs/screenshots/debug-memory.png` — Memory window showing sort/search results
- `docs/screenshots/port-waveform.png` — Logic Analyzer showing P0 square/triangle wave

(Placeholder paths — create `docs/screenshots/` and drop images there, then link them here.)

## Configuration & Environment Variables

None. This project uses **no environment variables, no `.env` files, and no
external configuration**. All device/clock/memory settings live inside the
`.uvproj` files (*Options for Target*). That is why there is intentionally
**no `.env.example`** in this repo.

## API Documentation

Not applicable — bare-metal 8051 firmware with no APIs or network interfaces.

## Testing Instructions

There is no automated test suite (standard for Keil 8051 coursework). Verification is manual via the simulator:

1. Build each project with **Rebuild all** — expect `0 Error(s), 0 Warning(s)`.
2. For data-processing programs, load known inputs, run, and compare memory outputs
   against hand-computed values (e.g. sort `{4,1,3,2}` → `{1,2,3,4}` for `ASCNDG.asm`).
3. For counters/waveforms, use the **Logic Analyzer** on `P0`/`P1` to confirm toggling.

> These steps were **not** executed here because Keil µVision is not installed in
> this environment — please verify on a machine with Keil before publishing results.

## Future Enhancements

- [ ] Fix the `BLCK_TANF.asm` filename typo (`TANF` → `TRANSF`) — or keep as-is for history.
- [ ] Remove or merge the duplicate `dsimple` / `dsimple.asm`.
- [ ] Recreate the missing `ex.uvproj` or drop the orphaned `ex.uvopt` / `ex.uvgui.cheth`.
- [ ] Add per-program header comments (inputs/outputs/registers used) inside each `.asm`.
- [ ] Add `docs/` with simulator screenshots and sample memory dumps.
- [ ] Add hardware wiring notes for running counters/waveforms on a real AT89C51 board.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md).

## License

No license file is included yet. The maintainer has **not** selected a license —
see the license-options note in the final preparation summary. Until a license is
chosen and added as `LICENSE`, all rights remain reserved by default.
