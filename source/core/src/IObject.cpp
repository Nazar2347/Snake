#include "IObject.h"

IObject::IObject(Vector2 Position, std::shared_ptr<Board> Board):
	Position_(Position), 
	Board_(Board)
{

	
}

ECellType IObject::CheckPosition(Vector2 Position)
{
	return Board_.lock()->GetCellInfo(Position);
}
IObject:: ~IObject()
{
	
}