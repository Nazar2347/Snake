#include "Board.h"

Board::Board(std::vector<std::vector<bool>> LevelData, Vector2 StartingPos) : 
	LevelData_(LevelData),
	StartingPosition_(StartingPos)
{
	
}

void Board::ChangeLevel(std::vector<std::vector<bool>> LevelData)
{
	LevelData_ = LevelData;
}

bool Board::GetCellInfo(Vector2 Position) const 
{
	size_t X = static_cast<size_t>(Position.x);
	size_t Y = static_cast<size_t>(Position.y);
	if (LevelData_.at(X).at(Y))
	{
		return LevelData_[X][Y];
	}
	return 1;
}

std::vector<std::vector<bool>> Board::getLevelData() const
{
	return LevelData_;
}

Board::~Board()
{
}
