#include <iostream>
#include "RenderSnake.h"
#include "RenderBoard.h"
#include "InputHandler.h"
#include "RenderFood.h"
#include "Game/Game.h"
#include <stack>
#include "GameUI.h"
using namespace std;

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(UI::SCREEN_WIDTH, UI::SCREEN_HEIGHT, "raylib [core] example - basic window");
    GameUI GameUI;
    EGameLevel CurrentLevel = EGameLevel::LEVEL1; // Tracks the current game level
    Game* newGame = nullptr;

    float PreviousTime = static_cast<float>(GetTime());           // Stores the time at the previous frame
    float AccumulatorTime = 0.0f;             // Accumulates elapsed time for fixed time steps
    // Initialize the game window with specified width, height, and title

    while (!WindowShouldClose() && GameUI.bIsGameShouldClose == false)
    {
        switch (GameUI.GetGameState())
        {
        case EGameStates::MENU:
            while (!WindowShouldClose() && GameUI.bIsGameShouldClose == false && GameUI.bIsPaused_ == true)
            {
                GameUI.Update();

                if (GameUI.bIsPaused_ == false)
                { 
                    CurrentLevel = EGameLevel::LEVEL1;
                    if (newGame == nullptr)
                    {
                        newGame = new Game(CurrentLevel);// Create a new game instance for the current level
                    }
                    else
                    {
                        delete newGame;
                        newGame = new Game(CurrentLevel);
                    }
                    GameUI.SetGameScore(newGame->FoodLeft);
                    GameUI.SetGameState(EGameStates::GAME);

                    PreviousTime = static_cast<float>(GetTime()); 
                    AccumulatorTime = 0.0f;// Reset the timer when the game starts
                }
                BeginDrawing();
                ClearBackground(RAYWHITE);
                GameUI.DrawBackgorund();
                GameUI.Draw();
                EndDrawing();
            }
            break;
        case EGameStates::GAME:
        {
            while (!WindowShouldClose() && GameUI.bIsGameShouldClose == false && GameUI.GetGameState() ==EGameStates::GAME)    // Detect window close button or ESC key
            {
                // Update
                //----------------------------------------------------------------------------------
                float CurrentTime = static_cast<float>(GetTime());                // Get the current time
                float DeltaTime = CurrentTime - PreviousTime; // Calculate time since last frame
                PreviousTime = CurrentTime;                   // Update previous time
                AccumulatorTime += DeltaTime;                 // Add to accumulator for fixed updates

                // Only update the game if it's not over and the level is not completed
                if (!newGame->IsGameOver() && newGame->IsLevelCompleted() != true)
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
                GameUI.DrawBackgorund();

                if (newGame->IsGameOver())
                {
                    newGame->Render();
                    GameUI.SetGameState(EGameStates::GAME_OVER);
                    
                }
                else if (newGame->IsLevelCompleted())
                {
                    newGame->Render();    // Render the completed level
                    WaitTime(3);          // Pause before moving to the next level

                    // Handle level progression
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
                        newGame = new Game(EGameLevel::LEVEL1); //change!!!
                        GameUI.SetGameScore(newGame->FoodLeft);
                        PreviousTime = static_cast<float>(GetTime());
                        AccumulatorTime = 0.0f;
                    }
                    else
                    {
                        newGame->Render();
                        GameUI.SetGameState(EGameStates::WIN);
                    }
                }
                else // Render the ongoing game
                {
                    newGame->Render();    
                    GameUI.Update();
                    GameUI.Draw();
                }

                EndDrawing();
                //----------------------------------------------------------------------------------
            }

        } break;
        
        default:
            while (!WindowShouldClose() && GameUI.bIsGameShouldClose == false &&
                (GameUI.GetGameState() == EGameStates::GAME_OVER|| GameUI.GetGameState() == EGameStates::WIN))
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
    


    // Main game loop
    // Wait for the player to press ENTER to start the game

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    delete newGame;
    return 0;
}