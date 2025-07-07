#include "Menu.h"


Menu::Menu()
{
	bIsPaused_ = true;
	Background_ = LoadTexture("Assets/MenuBackground.png");
	StartButton_ = new Button("Assets/StartButton.png", { UI::SCREEN_WIDTH / 2 ,UI::SCREEN_HEIGHT/2},1.0f );
	ExitButton_ = new Button("Assets/ExitButton.png", { UI::SCREEN_WIDTH / 2 ,UI::SCREEN_HEIGHT / 2+ 200 }, 1.0f);
}
void Menu::Update()
{

}

void Menu::Draw()
{
	DrawTexture(Background_, UI::BOARD_INITIAL_X_POS, UI::BOARD_INITIAL_Y_POS, WHITE);
	StartButton_->Draw();
	ExitButton_->Draw();
}

Menu::~Menu()
{
	UnloadTexture(Background_);
	delete StartButton_;
	delete ExitButton_;
}
