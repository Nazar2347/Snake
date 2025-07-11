#pragma once
#include "Board.h"
#include "RenderBoard.h"
#include "RenderFood.h"
#include "RenderSnake.h"
#include "InputHandler.h"
#include <stack>
#include <memory>

enum class EGameLevel
{
	LEVEL1,
	LEVEL2,
	LEVEL3
};

class Game
{
public:
	Game(EGameLevel);
	void ProcessInput();
	void Update();
	void Render();
	bool IsGameOver();
	bool IsLevelCompleted();
	int GetAmountFoodLeft();
	virtual ~Game();
	size_t FoodLeft;
protected:
	void InitializeLevel1();
	void InitializeLevel2();
	void InitializeLevel3();
private:
	std::shared_ptr<Board> Level_;
	std::unique_ptr<Snake> PlayerSnake_;
	std::unique_ptr<RenderBoard> BoardRender_;
	std::unique_ptr<RenderSnake> SnakeRender_;
	std::unique_ptr<FoodRender> FoodRender_;
	std::stack<std::unique_ptr<IFood>> LevelFoodStack;
	InputHandler InputHandler_;
	 Command* PlayerCommand_;
	bool bIsLevelCompleted_;
};
