# User Manual: Longest Common Subsequence Evaluator

## Requirements

- **Compiler:** g++ with C++17 support. Just like in the bin packing project, the Makefile forces `-O3` optimization so Part 1 on long strings and Part 2’s all-pairs LCS work do not hit an artificial runtime wall from an unoptimized build.
- **Operating System:** Linux (same assumption as before; build is tested with gcc in the lab image).
- **Input files:** _twoStrings.txt_ and _multiStrings.txt_ must be present in the project root when you use the default paths, or you pass explicit paths on the command line. Part 1 expects two non-empty lines (the two sequences). Part 2 expects a leading integer count on the first non-empty line, then that many non-empty lines, one string per line. Blank lines are skipped while reading. A bad count, missing lines, or an unreadable file is treated as an error and the program exits with a message to stderr.

## Project Structure

```
hughesc/   # Root directory named to match submission requirements
├── src/
│   ├── main.cpp                    # Execution, CLI (part1 / part2), and output
│   ├── FileHandler/
│   │   ├── file_handler.hpp
│   │   └── file_handler.cpp        # File parsing for both assignment input formats
│   └── LCSEvaluator/
│       ├── lcs_evaluator.hpp
│       └── lcs_evaluator.cpp       # Full c-table LCS + traceback (no b); two-row length DP; H/M/L/D table
├── twoStrings.txt                  # Pair of strings for Part 1
├── multiStrings.txt                # String count + data lines for Part 2
├── Makefile                        # Build config
├── UserManual.md
├── UMLDiagram.pdf
└── UMLDiagram.md                   # Mermaid UML; included in case the PDF cannot be viewed in the IDE
```

## Building the Project

### Compile the Code

```bash
make
```

The binary `hughesc` is written next to the Makefile. `make clean` removes object files and the binary.

### Convenience Targets

```bash
make run-part1    # ./hughesc part1 twoStrings.txt
make run-part2    # ./hughesc part2 multiStrings.txt
```

## Running the Program

Run from the directory that contains the input files (or pass absolute paths). Part 1 uses the full dynamic-programming `c` table in one flattened buffer and reconstructs the LCS using **only** `c` (no separate `b` / direction table). Part 2 uses two rows of DP to get LCS **lengths** only, then prints the upper-triangle similarity table (H, M, L, D) from the assignment definition.

```bash
./hughesc part1 [path/to/twoStrings.txt]     # default: twoStrings.txt
./hughesc part2 [path/to/multiStrings.txt]   # default: multiStrings.txt
```

## Similarity Rules (Part 2)

Ratios use `double` arithmetic. Let `shorter` and `longer` be the min and max of the two string lengths, and `L` the LCS length for that pair.

- **H (High):** `shorter / longer ≥ 0.90` and `L / shorter ≥ 0.90`
- **M (Medium):** not H, but `shorter / longer ≥ 0.80` and `L / shorter ≥ 0.80`
- **L (Low):** not M, but `shorter / longer ≥ 0.60` and `L / shorter ≥ 0.50`
- **D (Dissimilar):** none of the above

Tiers are applied in order H → M → L; otherwise the cell is D.

## UML

See `UMLDiagram.pdf` for the module-level diagram. The Mermaid source is in `UMLDiagram.md` (same idea as the prior project: GitHub renders it; the PDF is for submission or offline viewing).
