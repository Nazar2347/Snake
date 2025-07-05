#include "IObject.h"

IObject::IObject(Vector2 Position, Board &Board):
	Position_(Position), 
	Board_(&Board)
{

	
}

ECellType IObject::CheckPosition(Vector2 Position)
{
	return Board_->GetCellInfo(Position);
}
IObject:: ~IObject()
{
	
}