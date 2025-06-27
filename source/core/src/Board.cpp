#include "Board.h"

// Constructor: initializes board with level data and starting position
Board::Board(std::vector<std::vector<bool>> LevelData) : 
	LevelData_(LevelData)
{
	LevelXSize_ = LevelData_.size();           // Set board width
	LevelYSize_ = LevelData_.front().size();   // Set board height
	BoardMap_.clear();
	TransformLevelData();
}

// Change the current level data
void Board::ChangeLevel(std::vector<std::vector<bool>> LevelData)
{
	LevelData_ = LevelData;
}
void Board::TransformLevelData()
{
	if (!LevelData_.empty())
	{
		for (size_t x = 0; x < LevelXSize_; x++)
		{
			for (size_t y = 0; y < LevelYSize_; y++)
			{
				if (LevelData_.at(x).at(y) == 0)
				{
					BoardMap_.emplace(Vector2{ (float)x,(float)y }, ECellType::EMPTY);
				}
				else
				{
					BoardMap_.emplace(Vector2{ (float)x,(float)y }, ECellType::WALL);
				}
			}
		}
	}
}

// Get the value of a cell at the given position
ECellType Board::GetCellInfo(Vector2 Position) const 
{
	if (BoardMap_.find(Position) != BoardMap_.end())
	{
		return BoardMap_.at(Position);
	}
	return ECellType::OUT_OF_BORDER;
}
void Board::SetCellType(Vector2 Position,ECellType CellType)
{
	if (BoardMap_.find(Position) != BoardMap_.end())
	{
		BoardMap_.at(Position) = CellType;
	}
	
}

// Return the current level data
std::unordered_map<Vector2, ECellType, Vector2Hash, Vector2Equal> Board::getLevelData() const
{
	return BoardMap_;
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
