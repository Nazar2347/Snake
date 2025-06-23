#include "Snake.h"

Snake::Snake(Vector2 StartingPos) : HeadPosition_(StartingPos), bIsAlive_(true), HeadDirection_(EDirection::UP)
{
	TailPosition_.push_back({ StartingPos.x + 1, StartingPos.y });
}

std::vector<Vector2> Snake::getTailPosition()const
{
	return TailPosition_;
}

Vector2 Snake::getHeadPosition()const
{
	return HeadPosition_;
}

void Snake::ExtendTailBy(size_t Size)
{
	for (int i = 0; i < Size; i++)
	{
		if (TailPosition_.size() > 1 && TailPosition_.size() < 100)
		{
			Vector2 LastElementOfTail = TailPosition_.back();
			TailPosition_.push_back({ LastElementOfTail.x++, LastElementOfTail.y });
		}
	}
}

void Snake::ShortTailBy(size_t Size)
{
	for (int i = 0; i < Size; i++)
	{
		if (TailPosition_.size() < 1)
		{
			bIsAlive_ = false;
		}
		else
		{
			TailPosition_.pop_back();
		}
	}
}

void Snake::Move()
{
	Vector2 NextCell;
	
	switch (HeadDirection_)
	{
	case EDirection::UP:
	{
		NextCell = Vector2Add(HeadPosition_, { 0,-1 });
		break;
	}
	case EDirection::RIGHT:
	{
		NextCell = Vector2Add(HeadPosition_, { 1,0 });
		break;
	}
		
	case EDirection::LEFT:
	{
		NextCell = Vector2Add(HeadPosition_, { -1,0 });
		break;
	}
	case EDirection::DOWN:
	{
		NextCell = Vector2Add(HeadPosition_, { 0,1 });
		break;
	}
	default:
		break;
	}
	if (NextCell != TailPosition_[0]) //If movement is not backwards
	{
		Vector2 OldBodyPos = HeadPosition_;
		HeadPosition_ = NextCell; // Move the head
		for (int i = 0; i < TailPosition_.size(); i++) // Move the tail segments
		{
				TailPosition_[i] = OldBodyPos;	
				OldBodyPos = TailPosition_[i];
		}
	}
	else 
	{

	}
		
}

void Snake::SetDirection(EDirection Direction)
{
	HeadDirection_ = Direction;
}
EDirection Snake::GetDirection()
{
	return HeadDirection_;
}

bool Snake::isAlive()
{
	return bIsAlive_;
}

Snake::~Snake()
{
	
}

