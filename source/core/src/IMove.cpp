#include "IMove.h"

IMove::IMove(Board &Board)
{
	Board_ = &Board;
}

ECellType IMove::CheckPosition(Vector2 Position)
{
	return Board_->GetCellInfo(Position);
}
IMove:: ~IMove()
{
	
}