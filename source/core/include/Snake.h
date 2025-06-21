#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>

/**
 * @brief Represents a snake entity for grid-based games (e.g., Snake).
 *
 * The Snake class manages the position, movement, and state of a snake,
 * including its head, tail, and alive status. It provides methods to
 * manipulate the snake's length and position, and to query its current state.
 */
class Snake
{
public:
    /**
     * @brief Constructs a Snake with a given starting position.
     * @param StartingPos The initial position of the snake's head.
     */
    Snake(Vector2 StartingPos);

    /**
     * @brief Gets the positions of all tail segments.
     * @return A vector of Vector2 positions representing the tail.
     */
    std::vector<Vector2> getTailPosition()const;

    /**
     * @brief Gets the current position of the snake's head.
     * @return The head position as a Vector2.
     */
    Vector2 getHeadPosition()const;

    /**
     * @brief Extends the tail by a specified number of segments.
     * @param Size The number of segments to add to the tail.
     */
    void ExtendTailBy(size_t Size);

    /**
     * @brief Shortens the tail by a specified number of segments.
     * @param Size The number of segments to remove from the tail.
     */
    void ShortTailBy(size_t Size);

    /**
     * @brief Moves the snake in the specified direction.
     * @param Direction The direction vector to move the snake.
     */
    void Move(Vector2 Direction);

    /**
     * @brief Checks if the snake is alive.
     * @return True if the snake is alive, false otherwise.
     */
    bool isAlive();

    /**
     * @brief Destructor for the Snake class.
     */
    virtual ~Snake();

private:
    std::vector<Vector2> TailPosition_; ///< Positions of the tail segments.
    Vector2 HeadPosition_;              ///< Position of the snake's head.
    bool bIsAlive_;                     ///< Indicates if the snake is alive.
};