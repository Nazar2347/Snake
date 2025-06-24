#include "IEatable.h"

IEatable::IEatable(short int Points, Vector2 Position):Points_(Points), Position_(Position)
{
	FoodType_ = EFoodType::NONE;
}

Vector2 IEatable::GetPosition()const 
{
	return Position_;
}

short int IEatable::GetPoints()const
{
	return Points_;
}

void IEatable::SetPosition(Vector2 Position)
{
	Position_ = Position;
}

EFoodType IEatable::GetFoodType()
{
	return FoodType_;
}

IEatable::~IEatable()
{
}

AppleFood::AppleFood(short int Points, Vector2 Position) :IEatable(Points, Position)
{
	FoodType_ = EFoodType::APPLE;
}

FrogFood::FrogFood(short int Points, Vector2 Position): IEatable(Points, Position)
{
	FoodType_ = EFoodType::FROG;
}

void FrogFood::Jump(const Board & Board)
{
	//to -do 
}

ChocolateFood::ChocolateFood(short int Points, Vector2 Position): IEatable(Points, Position)
{
	FoodType_ = EFoodType::CHOCOLATE;
}
