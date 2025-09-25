#include "Command.h"
#include "Snake.h"
// Destructor for the base Command class.
Command::~Command()
{
}

// Executes the "move up" command by setting the snake's direction to UP.
void MoveUPCommand::execute(Snake &SnakeActor)
{
    SnakeActor.SetDirection(EDirection::UP);
}

// Executes the "move right" command by setting the snake's direction to RIGHT.
void MoveRightCommand::execute(Snake &SnakeActor)
{
    SnakeActor.SetDirection(EDirection::RIGHT);
}

// Executes the "move left" command by setting the snake's direction to LEFT.
void MoveLeftCommand::execute(Snake &SnakeActor)
{
    SnakeActor.SetDirection(EDirection::LEFT);
}

// Executes the "move down" command by setting the snake's direction to DOWN.
void MoveDownCommand::execute(Snake &SnakeActor)
{
    SnakeActor.SetDirection(EDirection::DOWN);
}

// Executes the null command; does nothing.
void NullCommand::execute(Snake &SnakeActor) noexcept
{
    // do nothing
}
