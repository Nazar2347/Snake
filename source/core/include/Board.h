#pragma once
#include <vector>
#include <raylib.h>
#include <unordered_map>
#include "GameConstants.h"

/**
 * @brief Types of levels available in the game.
 */
enum class ELevelType
{
    FOREST,         /**< Standard forest level. */
    SPURCE_FOREST,  /**< Spruce forest level. */
    WINTER_FOREST   /**< Winter-themed forest level. */
};

/**
 * @brief Types of cells that can exist on the board.
 */
enum class ECellType
{
    EMPTY,          /**< Empty cell. */
    WALL,           /**< Wall cell. */
    FOOD,           /**< Food cell. */
    SNAKE,          /**< Snake cell. */
    OUT_OF_BORDER   /**< Cell outside the board boundaries. */
};

/**
 * @brief Functor for comparing two Vector2 objects for equality.
 */
struct Vector2Equal     
{
    /**
     * @brief Compares two Vector2 objects for equality.
     * @param a First vector.
     * @param b Second vector.
     * @return True if both vectors have the same integer coordinates, false otherwise.
     */
    bool operator()(const Vector2& a, const Vector2& b) const noexcept;
};

/**
 * @brief Functor for hashing a Vector2 object.
 */
struct Vector2Hash
{
    /**
     * @brief Computes a hash value for a Vector2 object.
     * @param v The vector to hash.
     * @return The hash value.
     */
    std::size_t operator()(const Vector2& v) const noexcept;
};

/**
 * @brief Represents the game board and manages its state.
 */
class Board
{
public:
    /**
     * @brief Constructs a Board from the given level data.
     * @param LevelData 2D vector representing the initial level layout.
     */
    Board(std::vector<std::vector<bool>> LevelData);

    /**
     * @brief Gets the type of cell at the specified position.
     * @param Position The position to query.
     * @return The type of cell at the given position.
     */
    ECellType GetCellInfo(Vector2 Position) const;

    /**
     * @brief Sets the type of cell at the specified position.
     * @param Position The position to modify.
     * @param Celltype The new cell type.
     */
    void SetCellType(Vector2 Position, ECellType Celltype);

    /**
     * @brief Gets the current level data as a map of positions to cell types.
     * @return The level data map.
     */
    std::unordered_map<Vector2, ECellType, Vector2Hash, Vector2Equal> getLevelData() const;

    /**
     * @brief Gets the width (number of columns) of the level.
     * @return The width of the level.
     */
    size_t GetLevelXSize() const;

    /**
     * @brief Gets a random empty cell position on the board.
     * @return The position of an empty cell.
     */
    Vector2 GetEmptyCell() const;

    /**
     * @brief Gets the height (number of rows) of the level.
     * @return The height of the level.
     */
    size_t GetLevelYSize() const;

    /**
     * @brief Destroys the Board and releases resources.
     */
    virtual ~Board();

private:
    /**
     * @brief Transforms the initial level data into the board map.
     */
    void TransformLevelData();

    std::vector<std::vector<bool>> LevelData_; /**< 2D vector storing the initial level layout. */
    std::unordered_map<Vector2, ECellType, Vector2Hash, Vector2Equal> BoardMap_; /**< Map storing the cell states. */
    Vector2 StartingPosition_;                 /**< The starting position on the board. */
    size_t LevelXSize_;                        /**< The width (number of columns) of the level. */
    size_t LevelYSize_;                        /**< The height (number of rows) of the level. */
};
