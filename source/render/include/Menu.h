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
	void Update(EGameStates CurrentState);
	void Draw();
	void DrawWinLabel();
	void DrawGameOverLabel();
	~Menu();
	bool bIsPaused_;
	bool bIsGameShouldClose;
private:
	Texture2D Background_;
	Button* StartButton_;
	Button* ExitButton_;
	Button* RestartButton_;
};
