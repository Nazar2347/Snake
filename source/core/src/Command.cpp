#include "Command.h"

Command::~Command()
{
}

void MoveCommand::execute()
{
	SnakeActor_.SetDirection()
}

void NullComand::execute()
{
	//Do nothing
}
