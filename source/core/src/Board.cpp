#include "Board.h"

Board::Board(std::vector<std::vector<bool>> LevelData, Vector2 StartingPos) : 
	LevelData_(LevelData),
	StartingPosition_(StartingPos)
{
	LevelXSize_ = LevelData_.size();
	LevelYSize_ = LevelData_.front().size();
}

void Board::ChangeLevel(std::vector<std::vector<bool>> LevelData)
{
	LevelData_ = LevelData;
}

bool Board::GetCellInfo(Vector2 Position) const 
{
	size_t X = static_cast<size_t>(Position.x);
	size_t Y = static_cast<size_t>(Position.y);
	
	return LevelData_.at(X).at(Y);
}

std::vector<std::vector<bool>> Board::getLevelData() const
{
	return LevelData_;
}

Vector2 Board::getStartingPos() const
{
	return StartingPosition_;
}

size_t Board::GetLevelXSize()const
{
	return LevelXSize_;
}
size_t Board::GetLevelYSize()const
{
	return LevelYSize_;
}

Vector2 Board::getStartingPos() const
{
	return StartingPosition_;
}

size_t Board::GetLevelXSize()const
{
	return LevelXSize_;
}
size_t Board::GetLevelYSize()const
{
	return LevelYSize_;
}

Board::~Board()
{
}
