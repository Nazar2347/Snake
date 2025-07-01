#include "Game.h"
using namespace std;

Vector2 Level1StartingPos = { 6,6 };
int ApplePoints = -3;
int MousePoints = 1;
int FrogPoints = 2;

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
		{1,0,0,0,0,1,1,1,0,0,0,0,1},
		{1,0,0,0,0,0,0,1,0,0,0,0,1},
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
	PlayerCommand_->execute(*PlayerSnake_);
	
}

void Game::Update()
{
	
	PlayerSnake_->Move();
	if (!Level1FoodStack.empty())
	{
		if (PlayerSnake_->getHeadPosition() == Level1FoodStack.top()->GetPosition())
		{
			int FoodPoints = Level1FoodStack.top()->GetPoints();
			PlayerSnake_->ChangeTailSizeBy(FoodPoints);
			Level1FoodStack.pop();

		}
	}
	if (!Level1FoodStack.empty())
	{
		
		Level1FoodStack.top()->DoSomething();
	}
	else
	{
		bIsLevelCompleted_ = true;
	}
}

void Game::Render()
{
	BoardRender_->Draw();
	SnakeRender_->Draw();
	if (!Level1FoodStack.empty())
	{
		FoodRender_->Draw(Level1FoodStack.top());
	}
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



Game::~Game()
{
	delete BoardRender_;
	delete FoodRender_;
	delete SnakeRender_;
	delete Level_;
	PlayerCommand_ = nullptr;
	delete PlayerSnake_;
}

void Game::InitializeLevel1()
{
	Level_ = new Board(Level1Data);
	PlayerSnake_ = new Snake(Level1StartingPos, *Level_);

	Level1FoodStack.emplace(new Frog(FrogPoints, { 5,3 }, *Level_));
	Level1FoodStack.emplace(new Mouse(MousePoints, { 7,2 }, *Level_));
	Level1FoodStack.emplace(new Frog(FrogPoints, { 2,1 }, *Level_));
	Level1FoodStack.emplace(new Mouse(MousePoints, { 3,3 }, *Level_));
	Level1FoodStack.emplace(new Mouse(MousePoints, { 8,5 }, *Level_));
	Level1FoodStack.emplace(new Frog(FrogPoints, { 6,6 }, *Level_));
	Level1FoodStack.emplace(new Mouse(MousePoints, { 8,3 }, *Level_));


	BoardRender_ = new RenderBoard(*Level_);
	SnakeRender_ = new RenderSnake(PlayerSnake_);
	FoodRender_ = new FoodRender();

	PlayerCommand_ = new NullCommand();
	PlayerSnake_->ChangeTailSizeBy(2);
	bIsLevelCompleted_ = false;
}

void Game::InitializeLevel2()
{
	Level_ = new Board(Level2Data);
	PlayerSnake_ = new Snake(Level1StartingPos, *Level_);

	Level1FoodStack.emplace(new Frog(FrogPoints, { 5,3 }, *Level_));
	Level1FoodStack.emplace(new Mouse(MousePoints, { 7,2 }, *Level_));
	Level1FoodStack.emplace(new Frog(FrogPoints, { 2,1 }, *Level_));
	Level1FoodStack.emplace(new Mouse(MousePoints, { 3,3 }, *Level_));
	Level1FoodStack.emplace(new Mouse(MousePoints, { 8,5 }, *Level_));
	Level1FoodStack.emplace(new Frog(FrogPoints, { 6,6 }, *Level_));
	Level1FoodStack.emplace(new Mouse(MousePoints, { 8,3 }, *Level_));


	BoardRender_ = new RenderBoard(*Level_);
	SnakeRender_ = new RenderSnake(PlayerSnake_);
	FoodRender_ = new FoodRender();

	PlayerCommand_ = new NullCommand();
	PlayerSnake_->ChangeTailSizeBy(2);
	bIsLevelCompleted_ = false;
}

void Game::InitializeLevel3()
{
	bIsLevelCompleted_ = false;
}



