# Snake Game (C++ / Raylib)
My representation of the classic Snake game, built in C++ with the Raylib library for rendering and CMake for build automation.
Includes core game logic, interactive UI, and robust unit tests using Catch2.

# Project Features
- 🎮 W, A, S, D - controls
- 🤖 Movable food for Snake - so it's a bit challenging :)
- 🔰 3 levels with different layouts + Level customization (incoming feature)
- 🟢 Rendering, UI, visuals with Raylib 
- 🧪 Unit tests with Catch2
- 🧱 Used OOP game patterns: Command, GameLoop
- 🧩 Separated {core logic} from {render} and merged into {game logic}, then into the game loop 
- 📁 Clean folder structure and CMake build automation
- 📄 DoxyDocumentation
- 📑 Clang for code formatting
- 📊 Kanban project management methodology using Jira 

## Gameplay
![Level1](GitVisuals/GameCapture.gif)
![Level2](GitVisuals/GameCapture2.gif)

## How to run the game (Windows) (2.17 MB) 🕹
1) You can run the game by simply launching: Install->SnakeMain.exe 

#### OR
2) Download from my [GoogleDrive](https://drive.google.com/drive/folders/1HwZNBpxQ4uty3cCsi8MkHtUCODngYnGe?usp=sharing)

## 
## How to run the tests 🧪
1. Clone the repository, open a command console in the downloaded repo
2. Run these commands: 
 - cmake -S . -B ./build
 - cmake --build ./build
 - ctest --test-dir ./build/tests --verbose
### OR 
You can see tests are always running after a successful build and compilation of the program! 

## 
## Project structure 📂:

### Snake/

├── Assets            # Textures for game  
├── external          # External libraries source files (RayLib)  
├── Install/          # Game installation package  

### ├── source/

│   ├── core/         # Game logic (Snake, Board, Food)  
│   ├── render/       # Raylib rendering code  
│   └── app/          # Game entry point and logic  

### ├── tests/         # Catch2 unit tests  

├── CMakeLists.txt    # Build configuration  
└── README.md         # This file  

# Kanban Project Management Methodology 📊🧐
- From the beginning to the first release version, all the work tasks have been described and managed
  by applying the Kanban project management methodology in Jira Atlassian to have a structured workflow and clear steps in order to succeed.  

![Kanban workflow](GitVisuals/KanbanWorkflow.png)

##  
🤓☝️ It's my third small game project, where this time I used newly obtained skills such as:
- Game patterns (GameLoop, Command)
- Combination of popular code practices (S.O.L.I.D), and less coupled class architecture
- Smart pointers
- Jira Kanban project management
- GitHub branch-based workflow
