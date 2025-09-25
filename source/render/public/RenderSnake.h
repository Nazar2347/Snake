#pragma once
#include "Snake.h"
/**
 * @enum SnakePartType
 * @brief Enumerates the different graphical parts of the snake for rendering.
 */
enum SnakePartType
{
    BODY_TURN_TOP_RIGHT = 0, ///< Body turn (top-right)
    BODY_HORIZONTAL,         ///< Body horizontal
    BODY_TURN_TOP_LEFT,      ///< Body turn (top-left)
    HEAD_UP,                 ///< Head facing up
    HEAD_RIGHT,              ///< Head facing right

    BODY_TURN_DOWN_LEFT, ///< Body turn (down-left)
    BODY_VERTICAL,       ///< Body vertical
    HEAD_LEFT,           ///< Head facing left
    HEAD_DOWN,           ///< Head facing down

    BODY_TURN_DOWN_RIGHT, ///< Body turn (down-right)
    TAIL_UP,              ///< Tail facing up
    TAIL_RIGHT,           ///< Tail facing right

    TAIL_LEFT, ///< Tail facing left
    TAIL_DOWN, ///< Tail facing down
};

/**
 * @class RenderSnake
 * @brief Handles rendering of the Snake object using raylib textures and coordinates.
 */
class RenderSnake
{
  public:
    /**
     * @brief Constructs a RenderSnake object for a given Snake instance.
     * @param Snake Pointer to the Snake object to render.
     */
    RenderSnake(const Snake *Snake);

    /**
     * @brief Draws the entire snake (head, body, tail) on the screen.
     */
    void Draw() const;

    /**
     * @brief Destructor. Releases any loaded textures.
     */
    virtual ~RenderSnake();

  protected:
    /**
     * @brief Draws the snake's head using the correct texture and orientation.
     */
    void DrawHead() const;

    /**
     * @brief Draws the snake's body segments, including straight and turning parts.
     */
    void DrawBody() const;

    /**
     * @brief Draws the snake's tail using the correct texture and orientation.
     */
    void DrawTail() const;

    /**
     * @brief Draws a single part of the snake at the specified board position.
     * @param SnakePart Rectangle describing the part of the texture to use.
     * @param Position Board position to draw the part at.
     */
    void DrawSnakePart(Rectangle SnakePart, Vector2 Position) const;

  private:
    const Snake *Snake_;         ///< Pointer to the Snake object being rendered.
    Texture2D SnakeBodyTexture_; ///< Texture containing all snake parts.

    /**
     * @brief Rectangles defining the regions of the texture for each snake part.
     * The order matches the SnakePartType enum.
     */
    Rectangle SnakeParts[15] = {
        {0, 0, 64, 64},   // Body turn (top-right)
        {64, 0, 64, 64},  // Body horizontal
        {128, 0, 64, 64}, // Body turn (top-left)
        {192, 0, 64, 64}, // Head up
        {256, 0, 64, 64}, // Head right

        {0, 64, 64, 64},   // Body turn (down-left)
        {128, 64, 64, 64}, // Body vertical
        {192, 64, 64, 64}, // Head left
        {256, 64, 64, 64}, // Head down

        {128, 128, 64, 64}, // Body turn (down-right)
        {192, 128, 64, 64}, // Tail up
        {256, 128, 64, 64}, // Tail right

        {192, 192, 64, 64}, // Tail left
        {256, 192, 64, 64}, // Tail down
    };
};
