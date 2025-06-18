#pragma once
#include <raylib.h>
#include <vector>

class Snake
{
private:
	std::vector<Vector2> TailPosition_;
	Vector2 HeadPosition_;

public:
	Snake(Vector2 StartingPos);
	std::vector<Vector2> getTailPosition();
	Vector2 getHeadPosition();
	virtual ~Snake();
	
};