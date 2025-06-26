#include "IMove.h"

IMove::IMove(Board &Board)
{
	Board_ = &Board;
}

bool IMove::CheckPosition(Vector2 Position)
{
	if (Board_->GetCellInfo(Position) == 0)
	{
		return 0;
	}
	return 1;
}
IMove:: ~IMove()
{
	
}