#pragma once
#include "GameConstants.h"
#include <raylib.h>

/**
 * @brief Represents a clickable button with a texture in the game UI.
 */
class Button
{
  public:
    /**
     * @brief Constructs a Button object.
     * @param FileName Path to the texture file for the button.
     * @param Position The position where the button will be drawn.
     * @param size The scale factor for the button texture.
     */
    Button(const char *FileName, Vector2 Position, float Scale);

    /**
     * @brief Draws the button on the screen.
     */
    void Draw();

    /**
     * @brief Checks if the button has been clicked.
     * @return true if the button is clicked, false otherwise.
     */
    bool isClicked();

    /**
     * @brief Destroys the Button object and releases resources.
     */
    ~Button();

  private:
    /**
     * @brief The texture used for the button.
     */
    Texture2D ButtonTexture_;

    /**
     * @brief The position of the button on the screen.
     */
    Vector2 Position_;
};
