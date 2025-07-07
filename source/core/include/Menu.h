#pragma once
#include <raylib.h>
#include "GameConstants.h"
class Menu
{
public:
	Menu();
	void Update();
	void Draw();
	~Menu();
private:
	bool bIsPaused_;
	Texture2D Background_;
};
