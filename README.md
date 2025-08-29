# Battleship in C++

A console-based implementation of the classic **Battleship** game written in C++.  
It includes ship placement validation, hit/miss/sunken detection, opponent tracking, and a grid-based view.  
The project also comes with unit tests to ensure correctness of core game mechanics.

---

## Features
- **Ship Management**  
  - Supports ship placement with validation (length, alignment, adjacency).  
  - Tracks occupied and blocked grid positions.

- **Game Logic**  
  - Detects hits, misses, and when ships are sunken.  
  - Maintains state of both own grid and opponent grid.  

- **Console View**  
  - Displays own grid and opponent grid side by side.  

- **Unit Tests**  
  - Covers ship placement, shot impacts, blocked areas, and board behavior.

---

## Project Structure
├── src/<br>
│   ├── main.cpp&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Entry point for the game<br>
│   ├── Board.h/.cpp&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Represents the overall game board<br>
│   ├── OwnGrid.h/.cpp&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Player's grid with ships<br>
│   ├── OpponentGrid.h/.cpp&nbsp;# Opponent's grid with shot tracking<br>
│   ├── Ship.h/.cpp&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Ship representation<br>
│   ├── GridPosition.h/.cpp&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Handles row/column positions<br>
│   ├── Shot.h/.cpp&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Represents a shot fired<br>
│   ├── ConsoleView.h/.cpp&nbsp;&nbsp;# Handles board display<br>
<br>
├── tests/<br>
│   ├── part1tests.cpp&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# GridPosition & Ship basic tests<br>
│   ├── part2tests.cpp&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Blocked area & ship placement tests<br>
│   ├── part3tests.cpp&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;# Blow-taking & opponent grid tests<br>
<br>
└── README.md<br>


## How to Play

1. Compile the provided source files with a C++ compiler:  
   [Source Code Link](https://github.com/DheerajSwaroopSaligramaMahesh/Advanced_Programming_Techniques-Battleship/tree/main/Battleship/myCode)

2. Run the generated executable.

3. The program will first run a series of unit tests to validate core functionality.

4. After tests pass, the game will display the own grid and opponent grid in the console.

5. (Work-in-progress) Interactive gameplay logic can be extended — currently, the focus is on grid/ship handling, placement validation, and hit/miss tracking.

