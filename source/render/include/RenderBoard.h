#pragma once
#include "Board.h"
#include "GameConstants.h"

/**
 * @brief Handles rendering of the game board and its background.
 *
 * The RenderBoard class is responsible for drawing the board, including its background
 * and borders, using textures and data from the Board class.
 */
class RenderBoard
{
  public:
    /**
     * @brief Constructs a RenderBoard with the given Board data.
     * @param Board Reference to the Board object containing level data.
     */
    RenderBoard(const Board &Board);

    /**
     * @brief Draws the board and its background to the screen.
     */
    void Draw() const;

    /**
     * @brief Destroys the RenderBoard instance and releases resources.
     */
    virtual ~RenderBoard();

  private:
    const Board &LevelBoard_;    /**< The board data to be rendered. */
    Texture2D BorderTopTexture_; /**< Texture for the top border of the board. */
    Texture2D GroundTexture1_;   /**< First ground texture for the board background. */
    Texture2D GroundTexture2_;   /**< Second ground texture for the board background. */

    /**
     * @brief Draws the background elements of the board.
     */
    void DrawBackground() const;
};
