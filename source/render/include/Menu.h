#pragma once
#include <raylib.h>
#include "GameConstants.h"
#include "Button.h"

enum class EGameStates
{
	MENU,
	GAME,
	GAME_OVER,
	WIN
};

class Menu
{
public:
	Menu();
	void Update();
	void Draw();
	void SetGameState(EGameStates NewGameState);
	EGameStates GetGameState();
	~Menu();
	bool bIsPaused_;
	bool bIsGameShouldClose;
protected:
	void DrawMenu();
	void DrawWinLabel();
	void DrawGameOverLabel();
private:
	Texture2D Background_;
	EGameStates CurrentState_;
	Button* StartButton_;
	Button* ExitButton_;
	Button* RestartButton_;
};
