# Adventurer Roster

**A C++17 roster manager built on a hand-grown dynamic array, with selection sort, insertion sort, linear search, binary search, and an instrumented sort that reports comparison and move counts.**

Texas State University, CS 2308 Foundations of Computer Science II, Program 4 (Fall 2025). The assignment forbids `std::vector`, `std::sort`, `std::find`, and every other pre-made container or algorithm, so all of the data-structure and algorithm code here is written by hand over a raw `Adventurer*` buffer.

```
Main Menu
*****************************
1. Add an adventurer
2. View all adventurers
3. Sort adventurers by level
4. Sort adventurers by hit points
5. Search for an adventurer by name
6. Search for an adventurer by level
7. Sort by level with statistics (Extra Credit)
-1. Exit
*****************************
```

---

## What it does

The program keeps an in-memory roster of `Adventurer` records (name, class, level, HP) and lets the user add, list, sort, and search them from a menu loop. The roster starts with room for two entries and grows itself as records are added. Every algorithm on the menu is implemented from scratch in `src/utils.cpp`.

| Operation | Function | Algorithm | Complexity |
|---|---|---|---|
| Add | `addAdventurer` | Append; reallocate and copy when full | O(1) per insert until full, O(n) on a resize |
| Sort by HP (descending) | `selectionSortByHP` | Selection sort, in-place `std::swap` | Θ(n²) |
| Sort by level (ascending) | `insertionSortByLevel` | Adjacent-swap insertion | Θ(n²) |
| Sort by level, with stats | `insertionSortByLevelWithStats` | Shift-and-place insertion with early exit | O(n) best, O(n²) worst |
| Search by name | `linearSearchByName` | Linear scan, first match | O(n) |
| Search by HP | `binarySearchByHP` | Binary search over a descending array | O(log n) |

## Design notes

**Manual dynamic array.** `addAdventurer` takes the roster as `Adventurer*&` together with `int& size` and `int& capacity`. When size reaches capacity it allocates a new block of `capacity + 10`, copies every element across, frees the old block with `delete[]`, and rebinds the caller's pointer. The driver owns the buffer and releases it once on exit, so the program is leak-free and never double-frees. `Adventurer` follows the rule of zero: its members are `std::string` and `int`, so the compiler-generated copy is correct and is what the copy loop relies on.

**Binary search matched to the sort it depends on.** The HP sort is descending, so the binary search moves its lower bound right when the midpoint is *greater* than the target. Copying a textbook ascending search here would silently return wrong answers.

**Instrumentation.** The extra-credit sort zeroes two `int&` out-parameters on entry and counts every level comparison and every element move (the copy out to `temp`, each shift, and the copy back). Because this version breaks out of the inner loop as soon as the element is in place, running it on already-sorted data shows insertion sort's adaptive best case: `n - 1` comparisons and `2(n - 1)` moves.

**Separation.** The class lives in `include/adventurer.h` and `src/adventurer.cpp`, the algorithms in `src/utils.cpp`, and the menu-driven driver in `src/program4_driver.cpp`. The driver skeleton was supplied by the course; the class implementation and every algorithm are original work.

## Building and running

Requires `g++` with C++17 support and GNU `make`. Valgrind is optional.

```bash
make            # builds ./program4.out
make run        # run the program
make valrun     # run under valgrind to check for leaks
make clean      # remove object files
```

All input is interactive. To add an adventurer, choose `1` and enter a name, a class, a level, and an HP value on successive prompts. Names and classes may contain spaces.

Example session, after adding Aria (Wizard, level 5, 30 HP), Borg (Barbarian, level 2, 45 HP), and Cleo (Cleric, level 9, 12 HP):

```
Enter choice: 4          # sort by HP, descending
Borg (45) -> Aria (30) -> Cleo (12)

Enter choice: 6          # binary search by HP
Enter HP: 30
Adventurer's Information
Name : Aria
Class: Wizard
Level: 5
HP   : 30

Enter choice: 7          # instrumented sort on level-sorted data
Sorting complete!
Comparisons: 2
Swaps: 4
```

## Project structure

```
AdventurerRoster/
├── Makefile                  # g++ -std=c++17 -g, run and valrun targets
├── include/
│   └── adventurer.h          # Adventurer class and algorithm declarations
└── src/
    ├── adventurer.cpp        # accessors, mutators, record display
    ├── utils.cpp             # dynamic array growth, sorts, searches, instrumentation
    └── program4_driver.cpp   # menu loop; owns and frees the roster
```

## Known limitations

These are deliberate scope boundaries of a course assignment, listed so the trade-offs are visible.

- The array grows by a fixed 10 slots rather than doubling, so a long run of inserts costs Θ(n²) in copies. Geometric growth would make appends amortised O(1).
- Only the extra-credit sort is instrumented. The other three algorithms have no counters, so they cannot be compared head to head from inside the program.
- The binary search assumes the roster was sorted by HP first (menu option 4). It does not sort on its own, and the menu label for option 6 says "level" where it means HP. Both come from the supplied driver.
- Menu and record input are not validated. A non-numeric menu choice leaves `std::cin` in a fail state.
