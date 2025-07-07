#pragma once
#include <raylib.h>
#include "GameConstants.h"

class Button
{
public:
	Button(const char* FileName, Vector2 Position, float size);
	void Draw();
	bool isClicked();
	~Button();
private:
	Texture2D ButtonTexture_;
	Vector2 Position_;
};
