#pragma once
#include "Utilities.h"
#include "Board.h"

class IMove
{
public:
	IMove(Board &Board);
	virtual void Move() = 0;
	virtual ~IMove();
protected:
	RandomNumberGenerator* NumberGenerator_;
	virtual bool CheckPosition(Vector2 Position);
private:
	Board* Board_;
};