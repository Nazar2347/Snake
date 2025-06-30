#include "Board.h"

// Vector2Equal: Functor for comparing two Vector2 objects for equality in unordered_map.
// Compares the integer values of x and y to avoid floating-point precision issues.
bool Vector2Equal::operator()(const Vector2& a, const Vector2& b) const noexcept
{
    return static_cast<int>(a.x) == static_cast<int>(b.x) &&
           static_cast<int>(a.y) == static_cast<int>(b.y);
}

// Vector2Hash: Functor for hashing a Vector2 object for use in unordered_map.
// Hashes the integer values of x and y, combining them to produce a unique hash.
size_t Vector2Hash::operator()(const Vector2& v) const noexcept
{
    int x = static_cast<int>(v.x); 
    int y = static_cast<int>(v.y);
    return std::hash<int>()(x) ^ (std::hash<int>()(y) << 1);
}

// Constructor: Initializes the board with the given level data
Board::Board(std::vector<std::vector<bool>> LevelData) : 
	LevelData_(LevelData)
{
	LevelXSize_ = LevelData_.size();           // Set board width
	LevelYSize_ = LevelData_.front().size();   // Set board height
	BoardMap_.clear();                         // Clear any existing board data
	TransformLevelData();                      // Convert level data to board map
}

// Converts the 2D level data into the BoardMap_ structure
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

// Returns the cell type at the given position, or OUT_OF_BORDER if not found
ECellType Board::GetCellInfo(Vector2 Position) const 
{
	if (BoardMap_.find(Position) != BoardMap_.end())
	{
		return BoardMap_.at(Position);
	}
	return ECellType::OUT_OF_BORDER;
}

// Sets the cell type at the given position if it exists
void Board::SetCellType(Vector2 Position,ECellType CellType)
{
	if (BoardMap_.find(Position) != BoardMap_.end())
	{
		BoardMap_.at(Position) = CellType;
	}
}

// Returns the entire board map (positions and their cell types)
std::unordered_map<Vector2, ECellType, Vector2Hash, Vector2Equal> Board::getLevelData() const
{
	return BoardMap_;
}

// Finds and returns the first empty cell position, or {1,1} if none found
Vector2 Board::GetEmptyCell() const
{
	for (auto i : BoardMap_)
	{
		if (i.second == ECellType::EMPTY)
		{
			return i.first;
		}
	}
	return { 1,1 };
}

// Returns the width of the board
size_t Board::GetLevelXSize()const
{
	return LevelXSize_;
}

// Returns the height of the board
size_t Board::GetLevelYSize()const
{
	return LevelYSize_;
}

// Destructor
Board::~Board()
{
}


