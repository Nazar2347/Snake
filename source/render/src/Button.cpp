#include "Button.h"

Button::Button(const char* FileName, Vector2 Position, float Scale)
	:Position_(Position)
{
	Image ButtonImage = LoadImage(FileName);
	int OriginalHeight = ButtonImage.height;
	int OriginalWidth = ButtonImage.width;

	int NewHeight = static_cast<int>(OriginalHeight * Scale);
	int NewWidth = static_cast<int>(OriginalWidth * Scale);

	ImageResize(&ButtonImage, NewWidth, NewHeight);
	ButtonTexture_ = LoadTextureFromImage(ButtonImage);
	UnloadImage(ButtonImage);
}

void Button::Draw()
{
	DrawTextureEx(ButtonTexture_, Position_, 0.0f, 1.0f, WHITE);
}

Button::~Button()
{
	UnloadTexture(ButtonTexture_);
}
