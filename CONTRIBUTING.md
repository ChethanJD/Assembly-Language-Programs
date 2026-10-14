# Contributing to Micro_Kiel

Simple guidelines for this 8051 / Keil µVision lab-programs repo.

## How to contribute

1. Fork the repo and create a branch: `git checkout -b add/<program-name>`.
2. Add your program as a single `.asm` or `.c` file in the repo root
   (matching the existing flat layout).
3. If it belongs to a Keil project, add it to the relevant `.uvproj`
   (*Project → Add Existing Files*) and commit the updated `.uvproj`.
4. Verify before submitting:
   - Project **Rebuild all** gives `0 Error(s), 0 Warning(s)`.
   - Program runs correctly in the Keil simulator.
5. Update `README.md`'s program catalog (file name, description, memory map).
6. Open a pull request describing inputs, outputs, and how you tested.

## Code style

- 8051 assembly: `ORG 00H` entry, uppercase mnemonics, `END` terminator
  (follow the existing files).
- Add a short header comment to new files: purpose, inputs, outputs, registers used.
  Example:
  ```asm
  ; LARGST.asm — largest of 5 bytes at 40H-44H, result at 50H
  ```
- Embedded C: target AT89C51/AT89C51RD2, include the matching device header.
- Filenames: keep existing names (including the `BLCK_TANF` typo) unless the PR
  explicitly renames — renames break `.uvproj` references and history.

## What not to commit

- `Objects/`, `Listings/`, `*.obj`, `*.lst`, `*.hex`, `*.m51` (build outputs).
- `*.uvopt`, `*.uvgui.*` (per-user IDE state) — see `.gitignore`.
- No secrets, credentials, personal IDs, or student registration numbers.

## Reporting issues

Include: file name, Keil version, target device selected, input memory contents,
expected vs. actual output, and the build log excerpt.
