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
	Board(std::vector<std::vector<bool>> LevelData, Vector2 StartingPos);
	void ChangeLevel(std::vector<std::vector<bool>> LevelData);
	bool GetCellInfo(Vector2 Position) const;
	std::vector<std::vector<bool>> getLevelData() const;
	virtual ~Board();
private:
	std::vector<std::vector<bool>> LevelData_;
	Vector2 StartingPosition_;
};
