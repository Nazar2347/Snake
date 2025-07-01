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
    
    const float Tick = 0.19f;
    float AccumulatorTime = 0.0f;
    float PreviousTime = GetTime();

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
   

    Game newGame(EGameLevel::LEVEL2);
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        float CurrentTime = GetTime();
        float DeltaTime = CurrentTime - PreviousTime;
        PreviousTime = CurrentTime;
        AccumulatorTime += DeltaTime;
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (newGame.IsGameOver() != false)
        {
            newGame.ProcessInput();

            while (AccumulatorTime >= Tick)
            {
                newGame.Update();
                AccumulatorTime -= Tick;
            }
        }

            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();

            ClearBackground(RAYWHITE);


            if (newGame.IsGameOver() != false)
            {
                newGame.Render();
            }
            else
            {
                newGame.Render();
                DrawRectangle((screenWidth / 3) - 50, screenHeight / 3, 650, 200, WHITE);
                DrawText("Game OVER!", screenWidth/3, screenHeight/2.5, 96, RED);
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