#pragma once


class IMove
{
public:
	IMove();
	virtual void Move() = 0;
	virtual ~IMove();
};