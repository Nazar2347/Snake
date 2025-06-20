#pragma once
#include <vector>
#include <raylib.h>

/**
 * @brief Enumerates the available level types for the board.
 */
enum class ELevelType
{
    FOREST,         /**< Standard forest level. */
    SPURCE_FOREST,  /**< Spruce forest level. */
    WINTER_FOREST   /**< Winter-themed forest level. */
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
    Board(std::vector<std::vector<bool>> LevelData, Vector2 StartingPos);

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
    bool GetCellInfo(Vector2 Position) const;

    /**
     * @brief Retrieves the current level data.
     * @return 2D vector representing the level's cell states.
     */
    std::vector<std::vector<bool>> getLevelData() const;

    /**
     * @brief Gets the starting position for the board.
     * @return The starting position as a Vector2.
     */
    Vector2 getStartingPos() const;

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
    std::vector<std::vector<bool>> LevelData_; /**< 2D vector storing the level's cell states. */
    Vector2 StartingPosition_;                 /**< The starting position on the board. */
    size_t LevelXSize_;                        /**< The width (number of columns) of the level. */
    size_t LevelYSize_;                        /**< The height (number of rows) of the level. */
};
