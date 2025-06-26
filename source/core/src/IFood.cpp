#include "IFood.h"

IFood::IFood(short int Points, Vector2 Position, Board &Board):
	Points_(Points),
	Position_(Position),
	Board_(Board)
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
	:IFood(Points, Position, Board), 
	 IMove (Board)
{
	FoodType_ = EFoodType::FROG;
	NumberGenerator_ = new RandomNumberGenerator(-2, 2);
}
void Frog::DoSomething()
{
	// jump for over 1 cell
	this->Move();
}

Mouse::Mouse(short int Points, Vector2 Position, Board& Board)
	: IFood(Points, Position, Board), 
	  IMove (Board)
{
	FoodType_ = EFoodType::MOUSE;
	short MinStep = -1;
	short MaxStep = 1;
	NumberGenerator_ = new RandomNumberGenerator(MinStep, MaxStep);
}

void Mouse::DoSomething()
{
	this->Move();
}

void Frog::Move()
{
	Vector2 NewRandomPos;
	NewRandomPos.x = Position_.x + NumberGenerator_->GetRandomValue();
	NewRandomPos.y = Position_.y + NumberGenerator_->GetRandomValue();
	if (CheckPosition(NewRandomPos)==0)
	{
		SetPosition(NewRandomPos);
	} //else do nothing
}

void Mouse::Move()
{
	Vector2 NewRandomPos;
	NewRandomPos.x = Position_.x + NumberGenerator_->GetRandomValue();
	NewRandomPos.y = Position_.y +NumberGenerator_->GetRandomValue();
	
	if (CheckPosition(NewRandomPos)==0)
	{
		SetPosition(NewRandomPos);
	} //else do nothing
}
