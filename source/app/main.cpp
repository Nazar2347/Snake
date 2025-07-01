#include <iostream>
#include "RenderSnake.h"
#include "RenderBoard.h"
#include "InputHandler.h"
#include "RenderFood.h"
#include "Game/Game.h"
#include <stack>
using namespace std;





int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920;
    const int screenHeight = 960;
    float PreviousTime = GetTime();
    const float Tick = 0.15f;
    float AccumulatorTime = 0.0f;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    bool play = false;
    EGameLevel CurrentLevel = EGameLevel::LEVEL1;
    Game* newGame = new Game(CurrentLevel);
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        while (play != true)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                play = true;
                PreviousTime = GetTime();
               
            }
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle((screenWidth / 3) - 50, screenHeight / 3, 100, 100, WHITE);
            EndDrawing();
            
            
        }
        
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        
            float CurrentTime = GetTime();
            float DeltaTime = CurrentTime - PreviousTime;
            PreviousTime = CurrentTime;
            AccumulatorTime += DeltaTime;
            //----------------------------------------------------------------------------------
            if (!newGame->IsGameOver() && newGame->IsLevelCompleted() != true )
            {
                
                    newGame->ProcessInput();
                while (AccumulatorTime >= Tick)
                {
                    newGame->Update();
                    AccumulatorTime -= Tick;
                    
                }
            }

            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();
            ClearBackground(RAYWHITE);


            if (newGame->IsGameOver())
            {
                newGame->Render();
                DrawRectangle((screenWidth / 3) - 50, screenHeight / 3, 650, 200, WHITE);
                DrawText("Game OVER!", screenWidth / 3, screenHeight / 2.5, 96, RED);
            }
            else if (newGame->IsLevelCompleted())
            {
                newGame->Render();
                WaitTime(3);
                
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
                    DrawRectangle((screenWidth / 3) - 50, screenHeight / 3, 650, 200, WHITE);
                    DrawText("YOU WON!", screenWidth / 3, screenHeight / 2.5, 96, GREEN);
                }
            }
            else
            {
                newGame->Render();
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