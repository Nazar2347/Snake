#include "Game/Game.h"
#include "GameUI.h"
#include "InputHandler.h"
#include "RenderBoard.h"
#include "RenderFood.h"
#include "RenderSnake.h"
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Initialize the game window and UI
    InitWindow(UI::SCREEN_WIDTH, UI::SCREEN_HEIGHT, "raylib [core] example - basic window");
    GameUI GameUI;
    EGameLevel CurrentLevel = EGameLevel::LEVEL1; // Tracks the current game level
    Game *newGame = nullptr;

    float PreviousTime = static_cast<float>(GetTime()); // Stores the time at the previous frame
    float AccumulatorTime = 0.0f;                       // Accumulates elapsed time for fixed time steps

    // Main application loop
    while (!WindowShouldClose() && GameUI.bIsGameShouldClose == false)
    {
        switch (GameUI.GetGameState())
        {
        case EGameStates::MENU:
            // Menu loop: waits for the player to start the game
            while (!WindowShouldClose() && GameUI.bIsGameShouldClose == false && GameUI.bIsPaused_ == true)
            {
                GameUI.Update();

                // Start the game when unpaused
                if (GameUI.bIsPaused_ == false)
                {
                    CurrentLevel = EGameLevel::LEVEL1;
                    if (newGame == nullptr)
                    {
                        newGame = new Game(CurrentLevel); // Create a new game instance for the current level
                    }
                    else
                    {
                        delete newGame;
                        newGame = new Game(CurrentLevel);
                    }
                    GameUI.SetGameScore(newGame->FoodLeft);
                    GameUI.SetGameState(EGameStates::GAME);

                    PreviousTime = static_cast<float>(GetTime());
                    AccumulatorTime = 0.0f; // Reset the timer when the game starts
                }
                BeginDrawing();
                ClearBackground(RAYWHITE);
                GameUI.DrawBackgorund();
                GameUI.Draw();
                EndDrawing();
            }
            break;
        case EGameStates::GAME: {
            // Main game loop: handles gameplay and rendering
            while (!WindowShouldClose() && GameUI.bIsGameShouldClose == false &&
                   GameUI.GetGameState() == EGameStates::GAME)
            {
                // Update timing
                float CurrentTime = static_cast<float>(GetTime()); // Get the current time
                float DeltaTime = CurrentTime - PreviousTime;      // Calculate time since last frame
                PreviousTime = CurrentTime;                        // Update previous time
                AccumulatorTime += DeltaTime;                      // Add to accumulator for fixed updates

                // Update game logic if not over or completed
                if (!newGame->IsGameOver() && newGame->IsLevelCompleted() != true)
                {
                    newGame->ProcessInput(); // Handle user input

                    // Update the game logic at fixed intervals (GameTick)
                    while (AccumulatorTime >= GameConst::GameTick)
                    {
                        newGame->Update();
                        AccumulatorTime -= GameConst::GameTick;
                    }
                    GameUI.Update();
                }

                // Render the game and UI
                BeginDrawing();
                ClearBackground(RAYWHITE);
                GameUI.DrawBackgorund();

                if (newGame->IsGameOver())
                {
                    newGame->Render();
                    GameUI.SetGameState(EGameStates::GAME_OVER);
                }
                else // Render the ongoing game
                {
                    newGame->Render();
                    GameUI.Draw();
                }

                EndDrawing();

                // Handle level completion and progression
                if (newGame->IsLevelCompleted())
                {
                    WaitTime(3); // Pause before moving to the next level

                    if (CurrentLevel == EGameLevel::LEVEL1)
                    {
                        CurrentLevel = EGameLevel::LEVEL2;
                        delete newGame;
                        newGame = new Game(EGameLevel::LEVEL2);
                        GameUI.SetGameScore(newGame->FoodLeft);
                        PreviousTime = static_cast<float>(GetTime());
                        AccumulatorTime = 0.0f;
                    }
                    else if (CurrentLevel == EGameLevel::LEVEL2)
                    {
                        CurrentLevel = EGameLevel::LEVEL3;
                        delete newGame;
                        newGame = new Game(EGameLevel::LEVEL3);
                        GameUI.SetGameScore(newGame->FoodLeft);
                        PreviousTime = static_cast<float>(GetTime());
                        AccumulatorTime = 0.0f;
                    }
                    else
                    {
                        GameUI.SetGameState(EGameStates::WIN);
                    }
                }
            }
        }
        break;

        default:
            // Handles GAME_OVER and WIN states
            while (!WindowShouldClose() && GameUI.bIsGameShouldClose == false &&
                   (GameUI.GetGameState() == EGameStates::GAME_OVER || GameUI.GetGameState() == EGameStates::WIN))
            {
                GameUI.Update();

                BeginDrawing();

                GameUI.DrawBackgorund();
                newGame->Render();
                GameUI.Draw();

                EndDrawing();
            }
            break;
        }
    }

    // Cleanup and exit
    CloseWindow(); // Close window and OpenGL context
    delete newGame;
    return 0;
}