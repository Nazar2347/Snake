#include "IFood.h"

IFood::IFood(short int Points, Vector2 Position, Board &Board):Points_(Points), Position_(Position), Board_(Board)
{
	FoodType_ = EFoodType::NONE;
}

Vector2 IFood::GetPosition()const 
{
	return Position_;
}

short int IFood::GetPoints()const
{
	return Points_;
}

void IFood::SetPosition(Vector2 Position)
{
	Position_ = Position;
}

EFoodType IFood::GetFoodType()
{
	return FoodType_;
}

IFood::~IFood()
{
}

void IFood::SetBoard(Board& Board)
{
	Board_ = Board;
}

AppleFood::AppleFood(short int Points, Vector2 Position, Board & Board) 
	:IFood(Points, Position, Board)
{
	FoodType_ = EFoodType::APPLE;
}
void AppleFood::DoSomething()
{
	//do nothing as it is an stationary item
}

Frog::Frog(short int Points, Vector2 Position, Board & Board)
	:IFood(Points, Position, Board)
{
	FoodType_ = EFoodType::FROG;
	
}
void Frog::DoSomething()
{
	// jump for over 1 cell
}

Mouse::Mouse(short int Points, Vector2 Position, Board& Board)
	: IFood(Points, Position, Board)
{
	FoodType_ = EFoodType::MOUSE;
	
}

void Mouse::DoSomething()
{
	//Move into 1 cell
	Vector2 NewRandomPos;
	NewRandomPos.x = Position_.x;
	NewRandomPos.y = Position_.y;
	if (Board_.GetCellInfo(NewRandomPos) != 1)
	{
		SetPosition(NewRandomPos);
	}

}

void Frog::Move()
{
}

void Mouse::Move()
{
}
