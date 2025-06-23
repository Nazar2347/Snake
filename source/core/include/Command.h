#pragma once
#include "Snake.h"

class Command
{
public:
	virtual void execute(Snake& SnakeActor) = 0;
	virtual ~Command();
protected:
};

class MoveUPCommand :public Command
{
public:
	void execute(Snake& SnakeActor) override;
};
class MoveDownCommand : public Command
{
public:
	void execute(Snake& SnakeActor) override;
};
class MoveRightCommand : public Command
{
public:
	void execute(Snake& SnakeActor) override;
};
class MoveLeftCommand :public Command
{
public:
	void execute(Snake& SnakeActor) override;
};

class NullCommand : public Command
{
public:
	void execute(Snake & SnakeActor) override;
};
