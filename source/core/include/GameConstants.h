#pragma once
#include <raylib.h>

/**
 * @file GameConstants.h
 * @brief Contains global constants for game logic and UI configuration.
 */

/// @namespace GameConst
/// @brief Contains general game constants.
namespace GameConst
{
    /**
     * @brief Time interval for each game tick (in seconds).
     */
    inline constexpr float GameTick = 0.15f;
}

/// @namespace GameRules
/// @brief Contains constants related to game rules and scoring.
namespace GameRules
{
    /**
     * @brief Points awarded for collecting an apple (negative value).
     */
    inline constexpr int APPLE_POINTS = -3;

    /**
     * @brief Points awarded for collecting a mouse.
     */
    inline constexpr int MOUSE_POINTS = 1;

    /**
     * @brief Points awarded for collecting a frog.
     */
    inline constexpr int FROG_POINTS = 2;

    /**
     * @brief Initial size of the snake.
     */
    inline constexpr int INITIAL_SNAKE_SIZE = 2;
}

/// @namespace UI
/// @brief Contains constants for user interface layout and scaling.
namespace UI
{
    /**
     * @brief Font size for labels.
     */
    inline constexpr int LABLE_FONT_SIZE = 96;

    /**
     * @brief Width of the game screen in pixels.
     */
    inline constexpr int SCREEN_WIDTH = 1280;

    /**
     * @brief Height of the game screen in pixels.
     */
    inline constexpr int SCREEN_HEIGHT = 720;

    /**
     * @brief Rectangle for the win label display.
     */
    constexpr Rectangle WIN_LABLEL = { (SCREEN_WIDTH / 3)-50, (SCREEN_HEIGHT / 3) ,650,200 };

    /**
     * @brief Rectangle for the lose label display.
     */
    constexpr Rectangle LOSE_LABLEL = { (SCREEN_WIDTH / 3)-50, (SCREEN_HEIGHT / 2.5) ,650,200 };

    /**
     * @brief UI scaling factor.
     */
    constexpr float SCALE = 2.0f;

    /**
     * @brief Cell size in pixels.
     */
    constexpr float CELL_SIZE = 30 * SCALE; /*!< Cell size in pixels */

    /**
     * @brief Initial X position of the game board.
     */
    constexpr float BOARD_INITIAL_X_POS = 50.0f;

    /**
     * @brief Initial Y position of the game board.
     */
    constexpr float BOARD_INITIAL_Y_POS =0.0f;

    /**
     * @brief Scaling factor for blocks.
     */
    constexpr float BLOCKS_SCALE = (SCALE / 10) + 0.01f;

    /**
     * @brief Scaling factor for objects.
     */
    constexpr float OBJECTS_SCALE = (SCALE / 2) + 0.0f;
}
