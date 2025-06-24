#pragma once 
#include <raylib.h>
#include "Board.h"

class IEatable
{
public:
	IEatable(short int Points, Vector2 Position);
	virtual Vector2 GetPosition()const;
	virtual short int GetPoints()const;
	virtual void SetPosition(Vector2 Position);
	virtual ~IEatable();
protected:
	short int Points_;
	Vector2 Position_;

};


class AppleFood : public IEatable
{
public:
	AppleFood(short int Points, Vector2 Position);
	
};

class FrogFood : public IEatable
{
public:
	FrogFood(short int Points, Vector2 Position);
	void Jump(const Board& Board);

};
class ChocolateFood : public IEatable
{
public:
	ChocolateFood(short int Points, Vector2 Position);
};
