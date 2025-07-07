#pragma once
#include <raylib.h>
#include "GameConstants.h"
#include "Button.h"
class Menu
{
public:
	Menu();
	void Update();
	void Draw();
	~Menu();
	bool bIsPaused_;
private:
	Texture2D Background_;
	Button* StartButton_;
	Button* ExitButton_;
};
