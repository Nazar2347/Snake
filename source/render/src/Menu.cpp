#include "Menu.h"


Menu::Menu()
{
	bIsPaused_ = true;
	bIsGameShouldClose = false;
	Background_ = LoadTexture("Assets/MenuBackground.png");
	StartButton_ = new Button("Assets/StartButton.png", { UI::SCREEN_WIDTH / 2 ,UI::SCREEN_HEIGHT/2},1.0f );
	ExitButton_ = new Button("Assets/ExitButton.png", { UI::SCREEN_WIDTH / 2 ,UI::SCREEN_HEIGHT / 2+ 200 }, 1.0f);
	RestartButton_ = new Button("Assets/RestartButton.png", { UI::LOSE_LABLEL.x+ 300,UI::LOSE_LABLEL.y + 100 }, 0.5f);
}
void Menu::Update(EGameStates CurrentState)
{
	if (CurrentState == EGameStates::MENU)
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
	else if (CurrentState == EGameStates::GAME_OVER)
	{
		if (RestartButton_->isClicked())
		{

		}

	}


}

void Menu::DrawWinLabel()
{
	
	DrawRectangleRec(UI::LOSE_LABLEL, WHITE);
	DrawText("You Won!", UI::SCREEN_WIDTH / 3, UI::SCREEN_HEIGHT / 2.5, UI::LABLE_FONT_SIZE, GREEN);
}

void Menu::DrawGameOverLabel()
{
	DrawRectangleRec(UI::LOSE_LABLEL, WHITE);
	DrawText("Game OVER!", UI::SCREEN_WIDTH / 3, UI::SCREEN_HEIGHT / 2.5, UI::LABLE_FONT_SIZE, RED);
	RestartButton_->Draw();
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
