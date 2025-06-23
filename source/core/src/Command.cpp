#include "Command.h"

Command::~Command()
{
}

void MoveUPCommand::execute(Snake& SnakeActor) 
{
	SnakeActor.SetDirection(EDirection::UP);
}

void MoveRightCommand::execute(Snake& SnakeActor)
{
	SnakeActor.SetDirection(EDirection::RIGHT);
}
void MoveLeftCommand::execute(Snake& SnakeActor)
{
	SnakeActor.SetDirection(EDirection::LEFT);
}

void MoveDownCommand::execute(Snake& SnakeActor)
{
	SnakeActor.SetDirection(EDirection::DOWN);
}
void NullCommand::execute(Snake& SnakeActor) 
{
	// do nothing
}



