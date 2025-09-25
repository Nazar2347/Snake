#include "Game/Game.h"
#include "GameUI.h"
Image GameIcon = LoadImage("Assets/GameIcon.png"); /* or LoadImage("Assets/Images/myimage.png"); */

int main()
{
    InitWindow(UI::SCREEN_WIDTH, UI::SCREEN_HEIGHT, "Snake Game");
    SetWindowIcon(GameIcon);

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
    UnloadImage(GameIcon);
    return 0;
}