#pragma once 
#include <raylib.h>
#include "Board.h"

enum class EFoodType
{
	APPLE,
	FROG,
	MOUSE,
	NONE
};

class IEatable
{
public:
	IEatable(short int Points, Vector2 Position);
	virtual Vector2 GetPosition()const;
	virtual short int GetPoints()const;
	virtual void SetPosition(Vector2 Position);
	virtual void DoSomething() = 0;
	EFoodType GetFoodType();
	virtual ~IEatable();
protected:
	short int Points_;
	Vector2 Position_;
	EFoodType FoodType_;

};


class AppleFood : public IEatable
{
public:
	AppleFood(short int Points, Vector2 Position);
	void DoSomething() override;
};

class FrogFood : public IEatable
{
public:
	FrogFood(short int Points, Vector2 Position);
	void DoSomething() override;
};
class MouseFood : public IEatable
{
public:
	MouseFood(short int Points, Vector2 Position);
	void DoSomething() override;
};
