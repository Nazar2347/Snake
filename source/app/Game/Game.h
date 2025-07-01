#pragma once
#include "Board.h"
#include "RenderBoard.h"
#include "RenderFood.h"
#include "RenderSnake.h"
#include "InputHandler.h"
#include <stack>

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
	virtual ~Game();
protected:
	void InitializeLevel1();
	void InitializeLevel2();
	void InitializeLevel3();
private:
	Board* Level_;
	Snake* PlayerSnake_;
	RenderBoard* BoardRender_;
	RenderSnake* SnakeRender_;
	FoodRender* FoodRender_;
	std::stack<IFood*> Level1FoodStack;
	InputHandler InputHandler_;
	Command* PlayerCommand_;
	bool bIsLevelCompleted_;
};
