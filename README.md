# Pathfinding-Visualizer

# Terminal Pathfinding Visualizer

A terminal-based pathfinding visualizer using **Dijkstra's Algorithm**, built in **C++**.

![Preview Banner](https://img.shields.io/badge/C%2B%2B-Terminal--Visualizer-blue?style=flat-square)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)



## Features

- 🔄 Step-by-step visualization of **Dijkstra's Algorithm**
- 🧱 Random wall generation inside the start-to-end bounding box
- 💻 Cross-platform (Windows + Linux/Mac)
- 🛠 Built using **CMake** and **C++17**



## Demo (Terminal Output)
```plaintext
Final Path: (1,1) (2,1) (3,1) (3,2) (3,3)
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. S . . . . . . . . . . . . . . . . . . . . . . . . . . . .
. * . # . . . . . . . . . . . . . . . . . . . . . . . . . .
. * * D . . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
```

Installation & Build
Requirements
C++17 compatible compiler (like g++, clang++, or MSVC)
CMake ≥ 3.10
```


```
Build Instructions
# Clone the repository
git clone https://github.com/akhilrachhadia31/pathfinding-visualizer.git
cd pathfinding-visualizer
```



```
# Create a build directory
mkdir build
cd build
```


```
# Generate build files using CMake
cmake -G "MinGW Makefiles" ..
```


```
# Build the executable
mingw32-make
cmake ..
cmake --build .
```


```
Run the Program
After building, run:
./pathfinder         
pathfinder.exe 
```


```
Windows Notes
Prefer Windows Terminal or PowerShell over old cmd.
```

```
Project Structure
makefile
pathfinding-visualizer/
├── include/              # Header files
│   ├── grid.hpp
│   ├── utils.hpp
│   └── dijkstra.hpp
├── src/                  # Source files
│   ├── grid.cpp
│   ├── main.cpp
│   ├── utils.cpp
│   └── dijkstra.cpp
├── build/                # Build output (ignored by git)
├── CMakeLists.txt        # CMake configuration
├── .gitignore            # Ignore list for Git
└── README.md             # Project documentation
```

```
Algorithms
This visualizer uses Dijkstra’s algorithm, a greedy algorithm for finding the shortest path in a graph with non-negative weights.
```

```
Pathfinding Logic
Traverses the grid step-by-step from the Start (S) to Destination (D)
Walls (#) are obstacles that the algorithm avoids
Visited cells are marked live with *
The final path is printed in order
```

```
Author
Akhil Rachhadia
GitHub: @akhilrachhadia31
```
