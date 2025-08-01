#include "GameState.h"
#include "Game.h"

GameState::GameState(Game &RefGame) : Game_(RefGame)
{
}
GameState::~GameState()
{
}

GameState_Menu::GameState_Menu(Game &RefGame) : GameState(RefGame)
{
}

void GameState_Menu::Render()
{
    GameUI &UI = Game_.GetGameUI();
    UI.DrawBackgorund();
    UI.DrawMenu();
}

void GameState_Menu::Update()
{
}

void GameState_Menu::ProcessInput()
{
    GameUI &UI = Game_.GetGameUI();
    if (UI.IsStartButtonClicked())
    {
        Game_.InitializeLevel();
        Game_.SetCurrentState(std::make_unique<GameState_Play>(Game_));
    }
    if (UI.IsExitButtonClicked())
    {
        Game_.bIsGameShouldClose_ = true;
    }
}

GameState_Play::GameState_Play(Game &RefGame) : GameState(RefGame)
{
}

void GameState_Play::Render()
{
    GameUI &UI = Game_.GetGameUI();
    UI.DrawBackgorund();
    Game_.RenderOnPlay();
    UI.DrawGameUI();
}

void GameState_Play::Update()
{
    Game_.UpdateOnPlay();
    if (Game_.IsGameOver())
    {
        Game_.SetCurrentState(std::make_unique<GameState_Lose>(Game_));
    }
    else
    {
        if (Game_.IsGameWin())
        {
            Game_.SetCurrentState(std::make_unique<GameState_Win>(Game_));
        }
        else if (Game_.IsLevelCompleted())
        {
            Game_.InitializeLevel();
        }
    }
}

void GameState_Play::ProcessInput()
{
    Game_.ProcessInputOnGame();
}

GameState_Win::GameState_Win(Game &RefGame) : GameState(RefGame)
{
}

void GameState_Win::Render()
{
    GameUI &UI = Game_.GetGameUI();
    UI.DrawBackgorund();
    Game_.RenderOnPlay();
    UI.DrawGameUI();
    UI.DrawWinLabel();
}

void GameState_Win::Update()
{
}

void GameState_Win::ProcessInput()
{
    GameUI &UI = Game_.GetGameUI();
    if (UI.IsRestartButtonClicked())
    {
        Game_.SetCurrentState(std::make_unique<GameState_Menu>(Game_));
    }
}

GameState_Lose::GameState_Lose(Game &RefGame) : GameState(RefGame)
{
}

void GameState_Lose::Render()
{
    GameUI &UI = Game_.GetGameUI();
    UI.DrawBackgorund();
    Game_.RenderOnPlay();
    UI.DrawGameUI();
    UI.DrawGameOverLabel();
}

void GameState_Lose::Update()
{
}

void GameState_Lose::ProcessInput()
{
    GameUI &UI = Game_.GetGameUI();
    if (UI.IsRestartButtonClicked())
    {
        Game_.SetCurrentState(std::make_unique<GameState_Menu>(Game_));
    }
}
