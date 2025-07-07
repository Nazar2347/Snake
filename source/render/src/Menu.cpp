#include "Menu.h"


Menu::Menu()
{
	bIsPaused_ = true;
	bIsGameShouldClose = false;
	Background_ = LoadTexture("Assets/MenuBackground.png");
	StartButton_ = new Button("Assets/StartButton.png", { UI::SCREEN_WIDTH / 2 ,UI::SCREEN_HEIGHT/2},1.0f );
	ExitButton_ = new Button("Assets/ExitButton.png", { UI::SCREEN_WIDTH / 2 ,UI::SCREEN_HEIGHT / 2+ 200 }, 1.0f);
}
void Menu::Update()
{
	if (StartButton_->isClicked())
	{
		bIsPaused_ = false;
	}
	if (ExitButton_->isClicked())
	{
		bIsGameShouldClose = true;
	}

}

void Menu::Draw()
{
	DrawTexture(Background_, static_cast<int>(UI::BOARD_INITIAL_X_POS), static_cast<int>(UI::BOARD_INITIAL_Y_POS), WHITE);
	StartButton_->Draw();
	ExitButton_->Draw();
}

Menu::~Menu()
{
	UnloadTexture(Background_);
	delete StartButton_;
	delete ExitButton_;
}
