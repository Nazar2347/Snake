#pragma once
#include <vector>
#include <raylib.h>
enum class ELevelType
{
	FOREST,
	SPURCE_FOREST,
	WINTER_FOREST
}; 


class Board
{
public:
	Board(std::vector<std::vector<bool>> LevelData);
	void ChangeLevel(std::vector<std::vector<bool>> LevelData);
	bool GetCellInfo(Vector2 Position);
	virtual ~Board();
private:
	std::vector<std::vector<bool>> LevelData_;
	Vector2 StartingPosition_;
};
