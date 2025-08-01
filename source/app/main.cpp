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
    InitWindow(UI::SCREEN_WIDTH, UI::SCREEN_HEIGHT, "raylib [core] example - basic window");

    Game newGame;

    auto PreviousTime = static_cast<float>(GetTime());
    float AccumulatorTime = 0.0F;

    while (!WindowShouldClose() && !newGame.bIsGameShouldClose_)
    {
        auto CurrentTime = static_cast<float>(GetTime());
        float DeltaTime = CurrentTime - PreviousTime;
        PreviousTime = CurrentTime;
        AccumulatorTime += DeltaTime;

        newGame.ProcessInput();
        while (AccumulatorTime >= GameConst::GameTick)
        {
            newGame.Update();
            AccumulatorTime -= GameConst::GameTick;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        newGame.Render();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}