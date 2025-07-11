#include "Game.h"
using namespace std;

Vector2 Level1StartingPos = { 6,6 };
Vector2 Level2StartingPos = { 7,7 };

	vector<vector<bool>> Level1Data = {
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

	vector<vector<bool>> Level2Data = {
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
	

Game::Game(EGameLevel CurrentLevel)
{
	//12x12
	
	switch (CurrentLevel)
	{
	case EGameLevel::LEVEL1: InitializeLevel1();
		break;
	case EGameLevel::LEVEL2: InitializeLevel2();
		break;
	case EGameLevel::LEVEL3: InitializeLevel3();
		break;
	default: InitializeLevel1();
	}

}

void Game::ProcessInput()
{	
	
	PlayerCommand_ = InputHandler_.HandleInput();
	if (PlayerCommand_)
	{
		PlayerCommand_->execute(*PlayerSnake_);
	}
	
}

void Game::Update()
{
	
	if (!LevelFoodStack.empty())
	{
		if (PlayerSnake_->GetHeadPosition() == LevelFoodStack.top()->GetPosition()) //collision handling
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
		bIsLevelCompleted_ = true;
	}
	PlayerSnake_->Move();
	
	
}

void Game::Render()
{
	BoardRender_->Draw();
	if (!LevelFoodStack.empty())
	{
		FoodRender_->Draw(*LevelFoodStack.top());
	}
	SnakeRender_->Draw();
}

bool Game::IsGameOver()
{
	if (PlayerSnake_->isAlive())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Game::IsLevelCompleted()
{
	return bIsLevelCompleted_;
}

int Game::GetAmountFoodLeft()
{
	if (LevelFoodStack.empty())
	{
		return 0;
	}
	else
	{
		return LevelFoodStack.size();
	}
}

Game::~Game()
{
	
	Level_.reset();
	PlayerCommand_ = nullptr;
}

void Game::InitializeLevel1()
{
	Level_ = make_shared<Board>(Level1Data);
	PlayerSnake_ = make_unique<Snake>(Level1StartingPos, Level_);

	LevelFoodStack.emplace(new Frog( { 5,3 }, Level_));
	LevelFoodStack.emplace(new Mouse( { 7,2 }, Level_));
	LevelFoodStack.emplace(new Frog( { 2,1 }, Level_));
	

	BoardRender_ = make_unique <RenderBoard>(*Level_);
	SnakeRender_ = make_unique <RenderSnake>(PlayerSnake_.get());
	FoodRender_ = make_unique <FoodRender>();

	PlayerCommand_ = new NullCommand();
	PlayerSnake_->ChangeTailSizeBy(GameRules::INITIAL_SNAKE_SIZE);
	bIsLevelCompleted_ = false;
	FoodLeft = LevelFoodStack.size();
}

void Game::InitializeLevel2()
{
	Level_ = make_shared<Board>(Level2Data);
	PlayerSnake_ = make_unique <Snake>(Level2StartingPos, Level_);

	LevelFoodStack.emplace(new Frog( { 5,3 }, Level_));
	LevelFoodStack.emplace(new Mouse( { 7,2 }, Level_));
	LevelFoodStack.emplace(new Frog( { 2,1 }, Level_));
	//LevelFoodStack.emplace(new Mouse(MousePoints, { 3,3 }, Level_));
	//LevelFoodStack.emplace(new Mouse(MousePoints, { 8,5 }, Level_));
	//LevelFoodStack.emplace(new Frog(FrogPoints, { 6,6 }, Level_));
	//LevelFoodStack.emplace(new Mouse(MousePoints, { 8,3 }, Level_));


	BoardRender_ = make_unique <RenderBoard>(*Level_);
	SnakeRender_ = make_unique <RenderSnake>(PlayerSnake_.get());
	FoodRender_ = make_unique <FoodRender>();

	PlayerCommand_ = new NullCommand();
	PlayerSnake_->ChangeTailSizeBy(2);
	bIsLevelCompleted_ = false;
	FoodLeft = LevelFoodStack.size();
}

void Game::InitializeLevel3()
{
	bIsLevelCompleted_ = false;
}



