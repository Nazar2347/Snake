#include "Board.h"

// Constructor: initializes board with level data and starting position
Board::Board(std::vector<std::vector<bool>> LevelData, Vector2 StartingPos) : 
	LevelData_(LevelData),
	StartingPosition_(StartingPos)
{
	LevelXSize_ = LevelData_.size();           // Set board width
	LevelYSize_ = LevelData_.front().size();   // Set board height
}

// Change the current level data
void Board::ChangeLevel(std::vector<std::vector<bool>> LevelData)
{
	LevelData_ = LevelData;
}

// Get the value of a cell at the given position
bool Board::GetCellInfo(Vector2 Position) const 
{
	size_t X = static_cast<size_t>(Position.x);
	size_t Y = static_cast<size_t>(Position.y);
	if (X <= 0 || Y <= 0)
	{
		return 1;
	}
	else if (X > this->GetLevelXSize()-1 || Y > this->GetLevelYSize()-1)
	{
		return 1;
	}
	return LevelData_.at(X).at(Y);
}

// Return the current level data
std::vector<std::vector<bool>> Board::getLevelData() const
{
	return LevelData_;
}

// Return the starting position
Vector2 Board::getStartingPos() const
{
	return StartingPosition_;
}

// Get the width of the level (number of columns)
size_t Board::GetLevelXSize()const
{
	return LevelXSize_;
}

// Get the height of the level (number of rows)
size_t Board::GetLevelYSize()const
{
	return LevelYSize_;
}


// Destructor
Board::~Board()
{
}
