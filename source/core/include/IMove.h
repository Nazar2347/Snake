#pragma once
#include "Utilities.h"

class IMove
{
public:
	IMove();
	virtual void Move() = 0;
	virtual ~IMove();
protected:
	RandomNumberGenerator* NumberGenerator_;
};