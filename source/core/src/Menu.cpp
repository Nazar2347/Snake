#include "Menu.h"


Menu::Menu()
{
	bIsPaused_ = false;
	Background_ = LoadTexture("Assets/MenuBackground.png");
}
void Menu::Update()
{

}

void Menu::Draw()
{
	DrawTexture(Background_, UI::BOARD_INITIAL_X_POS, UI::BOARD_INITIAL_Y_POS, WHITE);
}

Menu::~Menu()
{
	UnloadTexture(Background_);
}
