#pragma once
#include "IFood.h"

/**
 * @brief Handles rendering of food items on the game board.
 *
 * The FoodRender class is responsible for drawing different types of food
 * (such as apples, frogs, and mice) using their associated textures.
 */
class FoodRender
{
  public:
    /**
     * @brief Constructs a FoodRender object and loads food textures.
     */
    FoodRender();

    /**
     * @brief Draws the specified food object on the screen.
     * @param Object Pointer to the IFood object to be rendered.
     */
    void Draw(const IFood &Object);

    /**
     * @brief Destroys the FoodRender object and releases resources.
     */
    virtual ~FoodRender();

  protected:
    Texture2D AppleTexture_; ///< Texture for rendering apple food.
    Texture2D FrogTexture_;  ///< Texture for rendering frog food.
    Texture2D MouseTexture_; ///< Texture for rendering mouse food.
};
