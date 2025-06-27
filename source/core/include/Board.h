#pragma once
#include <vector>
#include <raylib.h>
#include <unordered_map>

/**
 * @brief Enumerates the available level types for the board.
 */
enum class ELevelType
{
    FOREST,         /**< Standard forest level. */
    SPURCE_FOREST,  /**< Spruce forest level. */
    WINTER_FOREST   /**< Winter-themed forest level. */
};

enum class ECellType
{
    EMPTY,
    WALL,
    FOOD,
    SNAKE,
    OUT_OF_BORDER
};

// === Equality struct ===
struct Vector2Equal 
{
    bool operator()(const Vector2& a, const Vector2& b) const noexcept
    {
        return static_cast<int>(a.x) == static_cast<int>(b.x) &&
               static_cast<int>(a.y) == static_cast<int>(b.y);
    }
};
// === Hash struct ===
struct Vector2Hash
{
    std::size_t operator()(const Vector2& v) const noexcept 
    {
        int x = static_cast<int>(v.x);
        int y = static_cast<int>(v.y);
        return std::hash<int>()(x) ^ (std::hash<int>()(y) << 1);
    }
};

/**
 * @brief Represents a 2D board for level data and player positioning.
 *
 * The Board class manages the level's grid data, starting position, and provides
 * methods to query and modify the board state.
 */
class Board
{
public:
    /**
     * @brief Constructs a Board with the given level data and starting position.
     * @param LevelData 2D vector representing the level's cell states.
     * @param StartingPos The initial position on the board.
     */
    Board(std::vector<std::vector<bool>> LevelData);

    /**
     * @brief Changes the current level data.
     * @param LevelData 2D vector representing the new level's cell states.
     */
    void ChangeLevel(std::vector<std::vector<bool>> LevelData);

    /**
     * @brief Gets the state of a cell at the specified position.
     * @param Position The position to query.
     * @return True if the cell is active, false otherwise.
     */
    ECellType GetCellInfo(Vector2 Position) const;

    /**
     * @brief Retrieves the current level data.
     * @return 2D vector representing the level's cell states.s
     */
    std::unordered_map<Vector2,ECellType,Vector2Hash,Vector2Equal> getLevelData() const;

    void TransformLevelData();
    /**
     * @brief Gets the width (number of columns) of the level.
     * @return The number of columns in the level.
     */
    size_t GetLevelXSize() const;

    /**
     * @brief Gets the height (number of rows) of the level.
     * @return The number of rows in the level.
     */
    size_t GetLevelYSize() const;

    /**
     * @brief Destroys the Board instance.
     */
    virtual ~Board();

private:
    std::vector<std::vector<bool>> LevelData_;
    std::unordered_map<Vector2, ECellType, Vector2Hash, Vector2Equal> BoardMap_;/**< 2D vector storing the level's cell states. */
    Vector2 StartingPosition_;                 /**< The starting position on the board. */
    size_t LevelXSize_;                        /**< The width (number of columns) of the level. */
    size_t LevelYSize_;                        /**< The height (number of rows) of the level. */
};
