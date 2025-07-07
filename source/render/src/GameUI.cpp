#include "GameUI.h"


GameUI::GameUI()
{
	bIsPaused_ = true;
	bIsGameShouldClose = false;
	Background_ = LoadTexture("Assets/MenuBackground.png");
	StartButton_ = new Button("Assets/StartButton.png", { UI::SCREEN_WIDTH / 2 ,UI::SCREEN_HEIGHT/2},1.0f );
	ExitButton_ = new Button("Assets/ExitButton.png", { UI::SCREEN_WIDTH / 2 ,UI::SCREEN_HEIGHT / 2+ 200 }, 1.0f);
	RestartButton_ = new Button("Assets/RestartButton.png", { UI::LOSE_LABLEL.x+ 300,UI::LOSE_LABLEL.y + 100 }, 0.5f);
	CurrentState_ = EGameStates::MENU;
}
void GameUI::Update()
{
	switch (CurrentState_)
	{
	case EGameStates::MENU:
		if (StartButton_->isClicked())
		{
			CurrentState_ = EGameStates::GAME;
			bIsPaused_ = false;
		}
		if (ExitButton_->isClicked())
		{
			bIsGameShouldClose = true;

		}
		break;
	case EGameStates::GAME:
		break;
	case EGameStates::GAME_OVER:
		if (RestartButton_->isClicked())
		{
			CurrentState_ = EGameStates::MENU;
			bIsPaused_ = true;
		}
		break;
	case EGameStates::WIN:
		if (RestartButton_->isClicked())
		{
			CurrentState_ = EGameStates::MENU;
			bIsPaused_ = true;
		}
		break;
	default:
		break;
	}
	
}

void GameUI::DrawMenu()
{
	DrawTexture(Background_, static_cast<int>(UI::BOARD_INITIAL_X_POS), static_cast<int>(UI::BOARD_INITIAL_Y_POS), WHITE);
	StartButton_->Draw();
	ExitButton_->Draw();
}


void GameUI::SetGameState(EGameStates NewGameState)
{
	CurrentState_ = NewGameState;
}

EGameStates GameUI::GetGameState()
{
	return CurrentState_;
}
void GameUI::DrawWinLabel()
{
	DrawRectangleRec(UI::LOSE_LABLEL, WHITE);
	DrawText("You Won!", UI::SCREEN_WIDTH / 3, UI::SCREEN_HEIGHT / 2.5, UI::LABLE_FONT_SIZE, GREEN);
	RestartButton_->Draw();
}

void GameUI::DrawGameOverLabel()
{
	DrawRectangleRec(UI::LOSE_LABLEL, WHITE);
	DrawText("Game OVER!", UI::SCREEN_WIDTH / 3, UI::SCREEN_HEIGHT / 2.5, UI::LABLE_FONT_SIZE, RED);
	RestartButton_->Draw();
}

void GameUI::Draw()
{
	switch (CurrentState_)
	{
	case EGameStates::MENU: DrawMenu(); break;
	case EGameStates::GAME: break;
	case EGameStates::GAME_OVER: DrawGameOverLabel(); break;
	case EGameStates::WIN:DrawWinLabel(); break;
	default: DrawMenu(); break;
	}
}

GameUI::~GameUI()
{
	UnloadTexture(Background_);
	delete StartButton_;
	delete ExitButton_;
	delete RestartButton_;
}
