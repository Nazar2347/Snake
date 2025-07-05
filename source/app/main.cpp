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

    float PreviousTime = GetTime();
    
    float AccumulatorTime = 0.0f;

    InitWindow(UI::SCREEN_WIDTH, UI::SCREEN_HEIGHT, "raylib [core] example - basic window");
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
            DrawRectangle((UI::SCREEN_WIDTH / 3) - 50, UI::SCREEN_HEIGHT / 3, 100, 100, WHITE);
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
                newGame->Render();
                DrawRectangleRec(UI::LOSE_LABLEL, WHITE);
                DrawText("Game OVER!", UI::SCREEN_WIDTH / 3, UI::SCREEN_HEIGHT / 2.5, UI::LABLE_FONT_SIZE, RED);
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
                    DrawRectangleRec(UI::LOSE_LABLEL, WHITE);
                    DrawText("Game OVER!", UI::SCREEN_WIDTH / 3, UI::SCREEN_HEIGHT / 2.5, UI::LABLE_FONT_SIZE, GREEN);
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