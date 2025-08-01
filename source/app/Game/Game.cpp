#include "Game.h"

// Starting positions for each level
Vector2 Level1StartingPos = {6, 6};
Vector2 Level2StartingPos = {7, 6};
Vector2 Level3StartingPos = {7, 7};

// Level 1 layout (walls = 1, empty = 0)
	std::vector<std::vector<bool>> Level1Data = 
	{
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1},
};

	std::vector<std::vector<bool>> Level2Data =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,0,1},
		{1,0,0,0,0,1,1,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1},

};
	std::vector<std::vector<bool>> Level3Data = 
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,0,0,1,1,0,0,0,0,1,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,0,1,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,1,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,0,0,0,0,1,0,0,1},
		{1,0,0,1,0,0,0,0,1,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
};

// Constructor: initializes level based on enum
Game::Game()
{
    CurrentLevel_ = EGameLevel::LEVEL1;
    bIsGameShouldClose_ = false;
    CurrentState_ = std::make_unique<GameState_Menu>(*this);
}

void Game::InitializeLevel()
{
    PlayerCommand_ = new NullCommand();
    Level_.reset();
    PlayerSnake_.reset();
    while (!LevelFoodStack.empty())
    {
        LevelFoodStack.pop();
    }
    BoardRender_.reset();
    SnakeRender_.reset();
    FoodRender_.reset();

    switch (CurrentLevel_)
    {
    case EGameLevel::LEVEL1:
        InitializeLevel1();
        break;
    case EGameLevel::LEVEL2:
        InitializeLevel2();
        break;
    case EGameLevel::LEVEL3:
        InitializeLevel3();
        break;
    default:
        InitializeLevel1();
        CurrentLevel_ = EGameLevel::LEVEL1;
    }
}

void Game::ProcessInput()
{
    CurrentState_->ProcessInput();
}

// Handles player input and executes commands
void Game::ProcessInputOnGame()
{
    PlayerCommand_ = InputHandler_.HandleInput(); // Get current input
    if (PlayerCommand_ != nullptr)
    {
        PlayerCommand_->execute(*PlayerSnake_); // Apply command to snake
    }
}

void Game::Update()
{
    CurrentState_->Update();
}
// Updates game logic: snake movement, food interaction, and level state
void Game::UpdateOnPlay()
{
    if (!LevelFoodStack.empty())
    {
        PlayerSnake_->Move();
        if (PlayerSnake_->GetHeadPosition() == LevelFoodStack.top()->GetPosition()) // food collision handling
        {
            int FoodPoints = LevelFoodStack.top()->GetPoints();
            PlayerSnake_->ChangeTailSizeBy(FoodPoints);
            LevelFoodStack.pop();
            FoodLeft = LevelFoodStack.size();
        }
    }
    if (!LevelFoodStack.empty())
    {
        LevelFoodStack.top()->DoSomething();
    }
    else
    {
        bIsLevelCompleted_ = true; // No food left

        switch (CurrentLevel_) // itterate to next level
        {
        case EGameLevel::LEVEL1:
            CurrentLevel_ = EGameLevel::LEVEL2;
            break;
        case EGameLevel::LEVEL2:
            CurrentLevel_ = EGameLevel::LEVEL3;
            break;
        case EGameLevel::LEVEL3:
            CurrentLevel_ = EGameLevel::GAME_WIN;
            break;
        }
    }
}

void Game::Render()
{
    CurrentState_->Render();
}

// Renders all game components
void Game::RenderOnPlay()
{
    BoardRender_->Draw();
    if (!LevelFoodStack.empty())
    {
        FoodRender_->Draw(*LevelFoodStack.top());
    }
    SnakeRender_->Draw();
}

// Returns true if the snake is dead
bool Game::IsGameOver() const
{
    if (PlayerSnake_->isAlive())
    {
        return false;
    }
    return true;
}

// Returns true if all food has been consumed
bool Game::IsLevelCompleted() const
{
    return bIsLevelCompleted_;
}

// Returns how many food items are left on the level
size_t Game::GetAmountFoodLeft()
{
    if (LevelFoodStack.empty())
    {
        return 0;
    }
    return LevelFoodStack.size();
}

Game::~Game()
{
    Level_.reset(); // Free level memory
    PlayerCommand_ = nullptr;
}

GameUI &Game::GetGameUI()
{
    return GameUI_;
}

void Game::SetCurrentState(std::unique_ptr<GameState> State)
{
    CurrentState_ = std::move(State);
}

bool Game::IsGameWin()
{
    if (CurrentLevel_ == EGameLevel::GAME_WIN)
    {
        return true;
    }
    return false;
}
// === Level Initialization ===


void Game::InitializeLevel1()
{
    Level_ = make_shared<Board>(Level1Data);
    PlayerSnake_ = make_unique<Snake>(Level1StartingPos, Level_);

    LevelFoodStack.emplace(std::make_unique<Frog>(Vector2{5, 3}, Level_));
    LevelFoodStack.emplace(std::make_unique<Mouse>(Vector2{7, 2}, Level_));
    LevelFoodStack.emplace(std::make_unique<Frog>(Vector2{2, 1}, Level_));

    // Set up renderers
    BoardRender_ = std::make_unique<RenderBoard>(*Level_);
    SnakeRender_ = std::make_unique<RenderSnake>(PlayerSnake_.get());
    FoodRender_ = std::make_unique<FoodRender>();

    PlayerCommand_ = new NullCommand(); // make smart
    PlayerSnake_->ChangeTailSizeBy(GameRules::INITIAL_SNAKE_SIZE);
    bIsLevelCompleted_ = false;
    FoodLeft = LevelFoodStack.size();
    GameUI_.StartCountingGameScore(FoodLeft);
}

void Game::InitializeLevel2()
{
    Level_ = make_shared<Board>(Level2Data);
    PlayerSnake_ = make_unique<Snake>(Level2StartingPos, Level_);

    LevelFoodStack.emplace(std::make_unique<Frog>(Vector2{5, 3}, Level_));
    LevelFoodStack.emplace(std::make_unique<Mouse>(Vector2{7, 2}, Level_));
    LevelFoodStack.emplace(std::make_unique<Mouse>(Vector2{3, 3}, Level_));
    LevelFoodStack.emplace(std::make_unique<Frog>(Vector2{2, 1}, Level_));
    LevelFoodStack.emplace(std::make_unique<Mouse>(Vector2{8, 5}, Level_));

    BoardRender_ = std::make_unique<RenderBoard>(*Level_);
    SnakeRender_ = std::make_unique<RenderSnake>(PlayerSnake_.get());
    FoodRender_ = std::make_unique<FoodRender>();

    PlayerCommand_ = new NullCommand();
    PlayerSnake_->ChangeTailSizeBy(2);
    bIsLevelCompleted_ = false;
    FoodLeft = LevelFoodStack.size();
    GameUI_.StartCountingGameScore(FoodLeft);
}

void Game::InitializeLevel3()
{
    Level_ = make_shared<Board>(Level3Data);
    PlayerSnake_ = make_unique<Snake>(Level3StartingPos, Level_);

    LevelFoodStack.emplace(std::make_unique<Frog>(Vector2{5, 3}, Level_));
    LevelFoodStack.emplace(std::make_unique<Mouse>(Vector2{7, 2}, Level_));
    LevelFoodStack.emplace(std::make_unique<Mouse>(Vector2{3, 3}, Level_));
    LevelFoodStack.emplace(std::make_unique<Frog>(Vector2{2, 1}, Level_));
    LevelFoodStack.emplace(std::make_unique<Mouse>(Vector2{8, 5}, Level_));

    BoardRender_ = std::make_unique<RenderBoard>(*Level_);
    SnakeRender_ = std::make_unique<RenderSnake>(PlayerSnake_.get());
    FoodRender_ = std::make_unique<FoodRender>();

    PlayerCommand_ = new NullCommand(); 
    PlayerSnake_->ChangeTailSizeBy(2);
    bIsLevelCompleted_ = false;
    FoodLeft = LevelFoodStack.size();
    GameUI_.StartCountingGameScore(FoodLeft);
}
