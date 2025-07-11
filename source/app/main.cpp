#include "Game/Game.h"
#include "GameUI.h"
#include "InputHandler.h"
#include "RenderBoard.h"
#include "RenderFood.h"
#include "RenderSnake.h"
#include <iostream>
#include <stack>
using namespace std;

void HandleMenuState(GameUI &GameUI, Game *&newGame, EGameLevel &CurrentLevel, float &PreviousTime, float &AccumulatorTime)
{
    while (!WindowShouldClose() && !GameUI.bIsGameShouldClose && GameUI.bIsPaused_)
    {
        GameUI.Update();

        if (!GameUI.bIsPaused_)
        {
            CurrentLevel = EGameLevel::LEVEL1;
            if (newGame == nullptr)
            {
                newGame = new Game(CurrentLevel);
            }
            else
            {
                delete newGame;
                newGame = new Game(CurrentLevel);
            }
            GameUI.StartCountingGameScore(newGame->FoodLeft);
            GameUI.SetGameState(EGameStates::GAME);

            PreviousTime = static_cast<float>(GetTime());
            AccumulatorTime = 0.0F;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        GameUI.DrawBackgorund();
        GameUI.Draw();
        EndDrawing();
    }
}

void HandleGameState(GameUI &GameUI, Game *&newGame, EGameLevel &CurrentLevel, float &PreviousTime, float &AccumulatorTime)
{
    while (!WindowShouldClose() && !GameUI.bIsGameShouldClose && GameUI.GetGameState() == EGameStates::GAME)
    {
        auto CurrentTime = static_cast<float>(GetTime());
        float DeltaTime = CurrentTime - PreviousTime;
        PreviousTime = CurrentTime;
        AccumulatorTime += DeltaTime;

        if (!newGame->IsGameOver() && !newGame->IsLevelCompleted())
        {
            newGame->ProcessInput();

            while (AccumulatorTime >= GameConst::GameTick)
            {
                newGame->Update();
                AccumulatorTime -= GameConst::GameTick;
            }
            GameUI.Update();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        GameUI.DrawBackgorund();

        if (newGame->IsGameOver())
        {
            newGame->Render();
            GameUI.SetGameState(EGameStates::GAME_OVER);
        }
        else
        {
            newGame->Render();
            GameUI.Draw();
        }

        EndDrawing();

        if (newGame->IsLevelCompleted())
        {
            WaitTime(3);

            if (CurrentLevel == EGameLevel::LEVEL1)
            {
                CurrentLevel = EGameLevel::LEVEL2;
                delete newGame;
                newGame = new Game(EGameLevel::LEVEL2);
                GameUI.StartCountingGameScore(newGame->FoodLeft);
                PreviousTime = static_cast<float>(GetTime());
                AccumulatorTime = 0.0F;
            }
            else if (CurrentLevel == EGameLevel::LEVEL2)
            {
                CurrentLevel = EGameLevel::LEVEL3;
                delete newGame;
                newGame = new Game(EGameLevel::LEVEL3);
                GameUI.StartCountingGameScore(newGame->FoodLeft);
                PreviousTime = static_cast<float>(GetTime());
                AccumulatorTime = 0.0F;
            }
            else
            {
                GameUI.SetGameState(EGameStates::WIN);
            }
        }
    }
}

void HandleEndState(GameUI &GameUI, Game *&newGame)
{
    while (!WindowShouldClose() && !GameUI.bIsGameShouldClose &&
           (GameUI.GetGameState() == EGameStates::GAME_OVER || GameUI.GetGameState() == EGameStates::WIN))
    {
        GameUI.Update();

        BeginDrawing();
        GameUI.DrawBackgorund();
        newGame->Render();
        GameUI.Draw();
        EndDrawing();
    }
}

int main()
{
    InitWindow(UI::SCREEN_WIDTH, UI::SCREEN_HEIGHT, "raylib [core] example - basic window");
    GameUI GameUI;
    EGameLevel CurrentLevel = EGameLevel::LEVEL1;
    Game *newGame = nullptr;

    auto PreviousTime = static_cast<float>(GetTime());
    float AccumulatorTime = 0.0F;

    while (!WindowShouldClose() && !GameUI.bIsGameShouldClose)
    {
        switch (GameUI.GetGameState())
        {
        case EGameStates::MENU:
            HandleMenuState(GameUI, newGame, CurrentLevel, PreviousTime, AccumulatorTime);
            break;
        case EGameStates::GAME:
            HandleGameState(GameUI, newGame, CurrentLevel, PreviousTime, AccumulatorTime);
            break;
        default:
            HandleEndState(GameUI, newGame);
            break;
        }
    }

    CloseWindow();
    delete newGame;
    return 0;
}