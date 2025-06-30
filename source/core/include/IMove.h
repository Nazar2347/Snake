#pragma once
#include "Utilities.h"
#include "Board.h"

/**
 * @brief Interface for movable entities on the game board.
 *
 * Provides a contract for movement and position checking logic.
 */
class IMove
{
public:
    /**
     * @brief Constructs a movable entity with a reference to the game board.
     * @param Board Reference to the game board.
     */
    IMove(Board &Board);

    /**
     * @brief Moves the entity on the board.
     *
     * Must be implemented by derived classes.
     */
    virtual void Move() = 0;

    /**
     * @brief Virtual destructor for IMove.
     */
    virtual ~IMove();

protected:
    RandomNumberGenerator* NumberGenerator_; ///< Pointer to a random number generator for movement logic.
    /**
     * @brief Checks the type of cell at the specified position.
     * @param Position The position to check.
     * @return The cell type at the given position.
     */
    virtual ECellType CheckPosition(Vector2 Position);
    Board* Board_; ///< Pointer to the game board.
};