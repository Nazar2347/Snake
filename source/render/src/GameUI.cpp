#include "GameUI.h"

// Constructor: initializes UI state, loads textures, and creates buttons
GameUI::GameUI()
{
    bIsPaused_ = true;
    bIsGameShouldClose = false;
    Background_ = LoadTexture("Assets/GameBackground.png");
    MenuPanel_ = LoadTexture("Assets/MenuPanel.png");
    GameOverLablel_ = LoadTexture("Assets/GameOver.png");
    YouWonLabel_ = LoadTexture("Assets/YouWon.png");
    ScoreBar_ = LoadTexture("Assets/ScoreBar.png");
    StartButton_ = new Button("Assets/StartButton.png", UI::START_BUTTON::Position_, UI::START_BUTTON::Scale_);
    ExitButton_ = new Button("Assets/ExitButton.png", UI::EXIT_BUTTON::Position_, UI::EXIT_BUTTON::Scale_);
    RestartButton_ = new Button("Assets/RestartButton.png", UI::RESTART_BUTTON::Position_, UI::RESTART_BUTTON::Scale_);
    CurrentState_ = EGameStates::MENU;
    StartScore_ = 0;
    Score_ = nullptr;
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
    DrawTextureEx(MenuPanel_, UI::MENU_PANEL::Position_, 0.0F, UI::MENU_PANEL::Scale, WHITE);
    StartButton_->Draw();
    ExitButton_->Draw();
}

void GameUI::DrawGameUI()
{
    size_t MaxFoodCount = StartScore_;

    size_t FoodEaten = MaxFoodCount - *Score_;
    float progress = 1.0F - ((float)*Score_ / MaxFoodCount);

    // Draw empty bar
    DrawTextureEx(ScoreBar_, UI::SCORE_BAR::Position, 0.0F, UI::SCORE_BAR::Scale, WHITE);

    // Setting a filled part
    auto filledWidth = static_cast<float>(((ScoreBar_.width / 1.5) * progress) - 15);
    Rectangle ScoreBarFillRec = {
        UI::SCORE_BAR::Position.x + 15,
        UI::SCORE_BAR::Position.y + 27,
        filledWidth,
        ScoreBar_.height / UI::SCORE_BAR_SCALE,
    };
    // Draw filled part
    DrawRectangleRounded(ScoreBarFillRec, 0.7F, 30, GOLD);

    // Draw progress text (above bar)
    std::string text = "Food eaten: " + std::to_string(FoodEaten) + " / " + std::to_string(StartScore_);
    DrawText(text.c_str(), static_cast<int>(UI::SCORE_BAR::Position.x),
             static_cast<int>(UI::SCORE_BAR::Position.y - 15.0F), 20, YELLOW);
}

void GameUI::StartCountingGameScore(size_t &GameScore)
{
    Score_ = &GameScore;
    StartScore_ = GameScore;
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
    DrawTextureEx(YouWonLabel_, UI::LARGE_MESSAGE_LABEL::Position, 0.0F, UI::LARGE_MESSAGE_LABEL::Scale, WHITE);
    RestartButton_->Draw();
}

// Draws the game over label and restart button
void GameUI::DrawGameOverLabel()
{
    DrawTextureEx(GameOverLablel_, UI::LARGE_MESSAGE_LABEL::Position, 0.0F, UI::LARGE_MESSAGE_LABEL::Scale, WHITE);
    RestartButton_->Draw();
}

// Draws the UI based on the current game state
void GameUI::Draw()
{

    switch (CurrentState_)
    {
    case EGameStates::MENU:
        DrawMenu();
        break;
    case EGameStates::GAME:
        DrawGameUI();
        break;
    case EGameStates::GAME_OVER:
        DrawGameOverLabel();
        break;
    case EGameStates::WIN:
        DrawWinLabel();
        break;
    default:
        DrawMenu();
        break;
    }
}
// Draws background
void GameUI::DrawBackgorund()
{
    DrawTexture(Background_, 0, 0, WHITE);
}

// Destructor: unloads textures and deletes button objects
GameUI::~GameUI()
{
    UnloadTexture(Background_);
    UnloadTexture(GameOverLablel_);
    UnloadTexture(YouWonLabel_);
    UnloadTexture(MenuPanel_);
    delete StartButton_;
    delete ExitButton_;
    delete RestartButton_;
    Score_ = nullptr;
}
