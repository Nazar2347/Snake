#include "Board.h"

Board::Board(std::vector<std::vector<bool>> LevelData) : LevelData_(LevelData)
{
	
}

void Board::ChangeLevel(std::vector<std::vector<bool>> LevelData)
{
	LevelData_ = LevelData;
}

bool Board::GetCellInfo(Vector2 Position)
{
	size_t X = static_cast<size_t>(Position.x);
	size_t Y = static_cast<size_t>(Position.y);
	if (LevelData_.at(X).at(Y))
	{
		return LevelData_[X][Y];
	}
	return 1;
}

Board::~Board()
{
}
