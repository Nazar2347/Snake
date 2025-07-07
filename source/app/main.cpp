#include <iostream>
#include "RenderSnake.h"
#include "RenderBoard.h"
#include "InputHandler.h"
#include "RenderFood.h"
#include "Game/Game.h"
#include <stack>
#include "Menu.h"
using namespace std;

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------

    float PreviousTime = GetTime();           // Stores the time at the previous frame
    float AccumulatorTime = 0.0f;             // Accumulates elapsed time for fixed time steps

    // Initialize the game window with specified width, height, and title
    InitWindow(UI::SCREEN_WIDTH, UI::SCREEN_HEIGHT, "raylib [core] example - basic window");

    bool play = false;                        // Indicates if the game is currently being played
    EGameLevel CurrentLevel = EGameLevel::LEVEL1; // Tracks the current game level
    Game* newGame = new Game(CurrentLevel);   // Create a new game instance for the current level

    Menu menu;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Wait for the player to press ENTER to start the game
        while (play != true)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                play = true;
                PreviousTime = GetTime();     // Reset the timer when the game starts
            }
            BeginDrawing();
            ClearBackground(RAYWHITE);
            menu.Draw();
            EndDrawing();
        }

        // Update
        //----------------------------------------------------------------------------------
        float CurrentTime = GetTime();                // Get the current time
        float DeltaTime = CurrentTime - PreviousTime; // Calculate time since last frame
        PreviousTime = CurrentTime;                   // Update previous time
        AccumulatorTime += DeltaTime;                 // Add to accumulator for fixed updates

        // Only update the game if it's not over and the level is not completed
        if (!newGame->IsGameOver() && newGame->IsLevelCompleted() != true )
        {
            newGame->ProcessInput();                  // Handle user input

            // Update the game logic at fixed intervals (GameTick)
            while (AccumulatorTime >= GameConst::GameTick)
            {
                newGame->Update();
                AccumulatorTime -= GameConst::GameTick;
            }
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (newGame->IsGameOver())
        {
            newGame->Render();    // Render the final game state
            DrawRectangleRec(UI::LOSE_LABLEL, WHITE);
            DrawText("Game OVER!", UI::SCREEN_WIDTH / 3, UI::SCREEN_HEIGHT / 2.5, UI::LABLE_FONT_SIZE, RED);
        }
        else if (newGame->IsLevelCompleted())
        {
            newGame->Render();    // Render the completed level
            WaitTime(3);          // Pause before moving to the next level

            // Handle level progression
            if (CurrentLevel == EGameLevel::LEVEL1)
            {
                delete newGame;
                newGame = new Game(EGameLevel::LEVEL2);
                CurrentLevel = EGameLevel::LEVEL2;
                PreviousTime = GetTime();
            }
            else if (CurrentLevel == EGameLevel::LEVEL2)
            {
                delete newGame;
                newGame = new Game(EGameLevel::LEVEL1);
                CurrentLevel = EGameLevel::LEVEL3;
                PreviousTime = GetTime();
            }
            else
            {
                // All levels completed, show game over in green
                DrawRectangleRec(UI::LOSE_LABLEL, WHITE);
                DrawText("Game OVER!", UI::SCREEN_WIDTH / 3, UI::SCREEN_HEIGHT / 2.5, UI::LABLE_FONT_SIZE, GREEN);
            }
        }
        else
        {
            newGame->Render();    // Render the ongoing game
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}