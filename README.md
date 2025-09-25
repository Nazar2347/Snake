# Snake Game (C++ / Raylib)
My representaion on the classic Snake game, built in C++ with Raylib library for rendering and CMake for build automation.
Includes core game logic, interactive UI, and robust unit tests using Catch2

# Project Features
- 🎮 W,A,S,D - controls
- 🤖 Movable food for Snake - so it's a bit challeging :)
- 🔰 3 levels with different layout + Level cutomization (incoming feature)
- 🟢 Rendering, UI, visuals with Raylib 
- 🧪 Unit tests with Catch2
- 🧱 Used OOP Game patterns: Command, GameLoop, Game State
- 🧩 Separeted {core logic} from {render} and merging into {game logic} then into game loop 
- 📁 Clean folder structure and CMake build automation
- 📄 DoxyDocumentaion
- 📑 Clang for Code formating
- 📊 Kanban Project Managment methodology using Jira 
    ## Gameplay
  ![Level1](GitVisuals/GameCapture.gif)
  ![Level2](GitVisuals/GameCapture2.gif)

  


  
## How to run the game (Windows) (2.17 MB) 🕹
### 1st Option  You can run game by cloning my project and run those commands:
- cmake -S. -B ./build -DCMAKE_INSTALL_PREFIX=<your folder to get builded game>
- cmake --build ./build --config Release
- cmake --install ./build
And afterwards, you should get executable in your desirable folder


### 2nd Option: 
Download from my [GoogleDisk](https://drive.google.com/drive/folders/1HwZNBpxQ4uty3cCsi8MkHtUCODngYnGe?usp=sharing)
#### OR
###  3rd Option: (⚠️ Not reliable )
Run .exe file in "Install" folder 

##
## How to run the tests 🧪
1. Clone repository, open command console in downloaded repo
2. Run these commands: 
 - cmake -S . -B ./build
 - cmake --build ./build
 - ctests --test-dir ./build/tests --verbose
 ### OR 
You can see tests are always running after succesfull build and compilation of the program! 
##
## Project structure📂:

### Snake/

├── Assets            # Textures for game

├── external          #External libraries source files (RayLib)

├── Install/       # Game Instalation package

### ├── source/

│   ├── Core/         # Game logic (Snake, Board, Food)

│   ├── Render/       # Raylib rendering code

│   └── App/      # Game entry point and logic

### ├── Tests/            # Catch2 unit tests

├── CMakeLists.txt    # Build configuration

└── README.md         # This file

# Kanban Project Managment methology 📊🧐
- Since the beginning till the first release version all the work tasks have been described and managed
  by applying Kanban Project Managment methology in Jira Atlassian to have structured worflow and clear steps inorder to succeed 
![Kanban workflow](GitVisuals/KanbanWorkflow.png)

##
🤓☝️ It's my third small game project, where this time I used newly obtained skills such as:
- Game Patterns (GameLoop, Command,Game State)
- Combination of popular code practices (S.O.L.I.D), and less coupling class architecture
- Smart pointers
- Jira Kanban project managment
- GitHub branch-based workflow

## PROJECT UPDATE NOTE:
    Special thanks to Cherno who made 2 amaizing videos to review my project, 
    and  THANKS to ALL programers who were supporting me and giving an advices/critics which pointed me to my weak points! 
    I achived and got all what I wanted and even more in terms of experience and knowlenge! 🧠⚡️
    THANK YOU ALL VERY MUCH!!! 🙏🏻
    I have learned a lot during this project. It was an greate opportunity to finally pour my knowlege gained 
    from courses and books into practise, especially I finally get familiarized with OOP stuff
    and used my knowlenge in Project Manegment (which I gained in one of named subjects in University: WSB-NLU)
    And as you saw and guessed, I indeed used AI for creating documentation and creating some game assets but not fully used it in code, 
    as after first attempts AI was leading me in completele wrong direction ❌ so.... I abounded using AI after 3-4 days. 
    The rest was my pure code and code-style fix form "Clang Fromat"
    For now.... I want to archive this project put it onto shelf and abondom it, as I want to grow and go further but...
    this time in Unreal Engine 5 and VR which is my dream destination point!
    And AGAIN: THANKS YOU ALL VERY MUCH for Support!💛

    
    
