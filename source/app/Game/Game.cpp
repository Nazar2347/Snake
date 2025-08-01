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
Game::Game(EGameLevel CurrentLevel)
{
    // 12x12

    switch (CurrentLevel)
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
    }
}

// Handles player input and executes commands
void Game::ProcessInput()
{

    PlayerCommand_ = InputHandler_.HandleInput(); // Get current input
    if (PlayerCommand_ != nullptr)
    {
        PlayerCommand_->execute(*PlayerSnake_); // Apply command to snake
    }
}

// Updates game logic: snake movement, food interaction, and level state
void Game::Update()
{

    if (!LevelFoodStack.empty())
    {
        PlayerSnake_->Move();
        if (PlayerSnake_->GetHeadPosition() == LevelFoodStack.top()->GetPosition()) // collision handling
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
    }
}

// Renders all game components
void Game::Render()
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

// === Level Initialization ===

void Game::InitializeLevel1()
{
    Level_ = make_shared<Board>(Level1Data);
    PlayerSnake_ = make_unique<Snake>(Level1StartingPos, Level_);

    LevelFoodStack.emplace(new Frog({5, 3}, Level_)); //make smart
    LevelFoodStack.emplace(new Mouse({7, 2}, Level_)); //make smart
    LevelFoodStack.emplace(new Frog({2, 1}, Level_)); //make smart

    // Set up renderers
    BoardRender_ = std::make_unique<RenderBoard>(*Level_);
    SnakeRender_ = std::make_unique<RenderSnake>(PlayerSnake_.get());
    FoodRender_ = std::make_unique<FoodRender>();

    PlayerCommand_ = new NullCommand(); // make smart
    PlayerSnake_->ChangeTailSizeBy(GameRules::INITIAL_SNAKE_SIZE);
    bIsLevelCompleted_ = false;
    FoodLeft = LevelFoodStack.size();
}

void Game::InitializeLevel2()
{
    Level_ = make_shared<Board>(Level2Data);
    PlayerSnake_ = make_unique<Snake>(Level2StartingPos, Level_);

    LevelFoodStack.emplace(new Frog({5, 3}, Level_)); //make smart
    LevelFoodStack.emplace(new Mouse({7, 2}, Level_)); //make smart
    LevelFoodStack.emplace(new Mouse({3, 3}, Level_)); // make smart
    LevelFoodStack.emplace(new Frog({2, 1}, Level_)); // make smart
    LevelFoodStack.emplace(new Mouse({8, 5}, Level_)); //make smart

    BoardRender_ = std::make_unique<RenderBoard>(*Level_);
    SnakeRender_ = std::make_unique<RenderSnake>(PlayerSnake_.get());
    FoodRender_ = std::make_unique<FoodRender>();

    PlayerCommand_ = new NullCommand();
    PlayerSnake_->ChangeTailSizeBy(2);
    bIsLevelCompleted_ = false;
    FoodLeft = LevelFoodStack.size();
}

void Game::InitializeLevel3()
{
    Level_ = make_shared<Board>(Level3Data);
    PlayerSnake_ = make_unique<Snake>(Level3StartingPos, Level_);

    LevelFoodStack.emplace(new Frog({5, 3}, Level_)); //make smart
    LevelFoodStack.emplace(new Mouse({7, 2}, Level_)); //make smart
    LevelFoodStack.emplace(new Mouse({3, 3}, Level_));//make smart
    LevelFoodStack.emplace(new Frog({2, 1}, Level_));//make smart
    LevelFoodStack.emplace(new Mouse({8, 5}, Level_));//make smart

    BoardRender_ = std::make_unique<RenderBoard>(*Level_);
    SnakeRender_ = std::make_unique<RenderSnake>(PlayerSnake_.get());
    FoodRender_ = std::make_unique<FoodRender>();

    PlayerCommand_ = new NullCommand(); //make smart
    PlayerSnake_->ChangeTailSizeBy(2);
    bIsLevelCompleted_ = false;
    FoodLeft = LevelFoodStack.size();
}
