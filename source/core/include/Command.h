#pragma once
#include "Snake.h"

class Command
{
public:
	virtual void execute() = 0;
	virtual ~Command();
protected:
	Snake& SnakeActor_;
};

class MoveCommand :public Command
{
public:
	void execute() override;
};

class NullComand
{
public:
	void execute() override;
};
