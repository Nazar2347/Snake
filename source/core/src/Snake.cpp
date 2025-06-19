#include "Snake.h"

Snake::Snake(Vector2 StartingPos) : HeadPosition_(StartingPos),bIsAlive_(true)
{
	TailPosition_.push_back({ StartingPos.x + 1, StartingPos.y });
}

std::vector<Vector2> Snake::getTailPosition()
{
	return TailPosition_;
}

Vector2 Snake::getHeadPosition()
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

void Snake::Move(Vector2 Direction)
{
	if (Vector2Add(Direction, HeadPosition_) != TailPosition_[0]) //If movement is not backwards
	{
		HeadPosition_ = Vector2Add(HeadPosition_, Direction); // Move the head
		for (auto tail : TailPosition_) // Move the tail segments
		{
			tail = Vector2Add(tail, Direction);
		}
	}
	else 
	{

	}
		
}

bool Snake::isAlive()
{
	return bIsAlive_;
}

Snake::~Snake()
{
	
}

