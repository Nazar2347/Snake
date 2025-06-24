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
		if (TailPosition_.size() >= 1 && TailPosition_.size() < 100)
		{
			Vector2 LastElementOfTail = TailPosition_.back();
			TailPosition_.push_back({ LastElementOfTail.x+1, LastElementOfTail.y });
			printf("TailPosition increased\n");
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

        // Step 1: Compute next cell based on current direction
        switch (HeadDirection_)
        {
        case EDirection::UP:    NextCell = Vector2Add(HeadPosition_, { 0, -1 }); break;
        case EDirection::DOWN:  NextCell = Vector2Add(HeadPosition_, { 0, 1 });  break;
        case EDirection::LEFT:  NextCell = Vector2Add(HeadPosition_, { -1, 0 }); break;
        case EDirection::RIGHT: NextCell = Vector2Add(HeadPosition_, { 1, 0 });  break;
        default: return;
        }

        // Step 2: If reversing into own body, reject the move by computing old direction instead
        if (TailPosition_.size() > 0 && Vector2Equals(NextCell, TailPosition_[0]))
        {
            // Recompute NextCell using the *opposite* of the new direction (assume player tried to go into boyd)
            switch (HeadDirection_)
            {
            case EDirection::UP:    HeadDirection_ = EDirection::DOWN; break;
            case EDirection::DOWN:  HeadDirection_ = EDirection::UP; break;
            case EDirection::LEFT:  HeadDirection_ = EDirection::RIGHT; break;
            case EDirection::RIGHT: HeadDirection_ = EDirection::LEFT; break;
            }

            // Recompute valid direction cell (same as before, but with restored HeadDirection_)
            switch (HeadDirection_)
            {
            case EDirection::UP:    NextCell = Vector2Add(HeadPosition_, { 0, -1 }); break;
            case EDirection::DOWN:  NextCell = Vector2Add(HeadPosition_, { 0, 1 });  break;
            case EDirection::LEFT:  NextCell = Vector2Add(HeadPosition_, { -1, 0 }); break;
            case EDirection::RIGHT: NextCell = Vector2Add(HeadPosition_, { 1, 0 });  break;
            default: return;
            }
        }

        // Step 3: Move the head
        Vector2 OldBodyPos = HeadPosition_;
        HeadPosition_ = NextCell;

        // Step 4: Move the tail
        for (int i = 0; i < TailPosition_.size(); i++)
        {
            Vector2 OldBodyPos2 = TailPosition_[i];
            TailPosition_[i] = OldBodyPos;
            OldBodyPos = OldBodyPos2;
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

