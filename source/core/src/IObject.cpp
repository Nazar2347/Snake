#include "IObject.h"

IObject::IObject(Board &Board)
{
	Board_ = &Board;
}

ECellType IObject::CheckPosition(Vector2 Position)
{
	return Board_->GetCellInfo(Position);
}
IObject:: ~IObject()
{
	
}