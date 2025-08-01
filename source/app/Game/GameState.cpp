#include "GameState.h"

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

}

void GameState_Menu::Update()
{
    
}

GameState_Play::GameState_Play(Game &RefGame) : GameState(RefGame)
{
}

void GameState_Play::Render()
{
}

void GameState_Play::Update()
{
}

GameState_Win::GameState_Win(Game &RefGame) : GameState(RefGame)
{
}

void GameState_Win::Render()
{
}

void GameState_Win::Update()
{
}

GameState_Lose::GameState_Lose(Game &RefGame) : GameState(RefGame)
{
}

void GameState_Lose::Render()
{
}

void GameState_Lose::Update()
{
}
