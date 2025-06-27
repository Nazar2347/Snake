#pragma once 
#include <raylib.h>
#include "Board.h"
#include "IMove.h"

enum class EFoodType
{
	APPLE,
	FROG,
	MOUSE,
	NONE
};

class IFood
{
public:
	IFood(short int Points, Vector2 Position, Board &Board);
	virtual Vector2 GetPosition()const;
	virtual short int GetPoints()const;
	virtual void SetPosition(Vector2 Position);
	virtual void DoSomething() = 0;
	EFoodType GetFoodType();
	void SetBoard(Board& board);
	virtual ~IFood();
protected:
	short int Points_;
	Vector2 Position_;
	EFoodType FoodType_;
	Board& FBoard_;

};


class AppleFood : public IFood
{
public:
	AppleFood(short int Points, Vector2 Position, Board &Board);
	void DoSomething() override;
};

class Frog : public IFood, public IMove
{
public:
	Frog(short int Points, Vector2 Position, Board & Board);
	void DoSomething() override;
protected:
	void Move() override;
	
};

class Mouse : public IFood, public IMove
{
public:
	Mouse(short int Points, Vector2 Position, Board & Board);
	void DoSomething() override;
protected:
	void Move() override;
};
