#include "GameUI.h"

// Constructor: initializes UI state, loads textures, and creates buttons
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

// Updates the UI based on the current game state and button clicks
void GameUI::Update()
{
	switch (CurrentState_)
	{
	case EGameStates::MENU:
		// Start game if Start button is clicked
		if (StartButton_->isClicked())
		{
			CurrentState_ = EGameStates::GAME;
			bIsPaused_ = false;
		}
		// Set flag to close game if Exit button is clicked
		if (ExitButton_->isClicked())
		{
			bIsGameShouldClose = true;

		}
		break;
	case EGameStates::GAME:
		// No UI update needed during gameplay
		break;
	case EGameStates::GAME_OVER:
		// Return to menu if Restart button is clicked
		if (RestartButton_->isClicked())
		{
			CurrentState_ = EGameStates::MENU;
			bIsPaused_ = true;
		}
		break;
	case EGameStates::WIN:
		// Return to menu if Restart button is clicked
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

// Draws the main menu background and buttons
void GameUI::DrawMenu()
{
	DrawTexture(Background_, static_cast<int>(UI::BOARD_INITIAL_X_POS), static_cast<int>(UI::BOARD_INITIAL_Y_POS), WHITE);
	StartButton_->Draw();
	ExitButton_->Draw();
}

// Sets the current game state
void GameUI::SetGameState(EGameStates NewGameState)
{
	CurrentState_ = NewGameState;
}

// Returns the current game state
EGameStates GameUI::GetGameState()
{
	return CurrentState_;
}

// Draws the win label and restart button
void GameUI::DrawWinLabel()
{
	DrawRectangleRec(UI::LOSE_LABLEL, WHITE);
	DrawText(
		"You Won!", 
		static_cast<int>(UI::SCREEN_WIDTH / 3), 
		static_cast<int>(UI::SCREEN_HEIGHT / 2.5),
		UI::LABLE_FONT_SIZE, GREEN);
	RestartButton_->Draw();
}

// Draws the game over label and restart button
void GameUI::DrawGameOverLabel()
{
	DrawRectangleRec(UI::LOSE_LABLEL, WHITE);
	DrawText(
		"Game OVER!", 
		static_cast<int>(UI::SCREEN_WIDTH / 3), 
		static_cast<int>(UI::SCREEN_HEIGHT / 2.5),
		UI::LABLE_FONT_SIZE, RED);
	RestartButton_->Draw();
}

// Draws the UI based on the current game state
void GameUI::Draw()
{
	switch (CurrentState_)
	{
	case EGameStates::MENU: DrawMenu(); break;
	case EGameStates::GAME: break; //to-do Draw game UI
	case EGameStates::GAME_OVER: DrawGameOverLabel(); break;
	case EGameStates::WIN:DrawWinLabel(); break;
	default: DrawMenu(); break;
	}
}

// Destructor: unloads textures and deletes button objects
GameUI::~GameUI()
{
	UnloadTexture(Background_);
	delete StartButton_;
	delete ExitButton_;
	delete RestartButton_;
}
