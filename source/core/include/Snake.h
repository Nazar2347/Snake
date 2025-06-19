#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>

class Snake
{
public:
	Snake(Vector2 StartingPos);
	std::vector<Vector2> getTailPosition();
	Vector2 getHeadPosition();
	void ExtendTailBy(size_t Size);
	void ShortTailBy(size_t Size);
	void Move(Vector2 Direction);
	bool isAlive();
	virtual ~Snake();
private:
	std::vector<Vector2> TailPosition_;
	Vector2 HeadPosition_;
	bool bIsAlive_;
	
};