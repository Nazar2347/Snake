#pragma once
#include <raylib.h>
#include <raymath.h>

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
inline constexpr float GameTick = 0.15F;
} // namespace GameConst

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

inline constexpr int MAX_FOOD_ON_LEVEL = 5;

inline constexpr unsigned short FROG_MOVE_TIMER = 5;
inline constexpr unsigned short MOUSE_MOVE_TIMER = 2;

inline constexpr unsigned short MAX_SNAKE_LENGHT = 50;
} // namespace GameRules

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
 * @brief Rectangle for the lose label display.
 */
constexpr Rectangle LABEL_REC = {(SCREEN_WIDTH / 3) - 50, (SCREEN_HEIGHT / 2.5), 650, 200};

/**
 * @brief Rectangle for the win label display.
 * @brief UI scaling factor.
 */
constexpr float SCALE = 2.0F;

/**
 * @brief Cell size in pixels.
 */
constexpr float CELL_SIZE = 30 * SCALE; /*!< Cell size in pixels */

/**
 * @brief Initial X position of the game board.
 */
constexpr float BOARD_INITIAL_X_POS = 50.0F;

/**
 * @brief Initial Y position of the game board.
 */
constexpr float BOARD_INITIAL_Y_POS = 0.0F;

/**
 * @brief Scaling factor for blocks.
 */
constexpr float BLOCKS_SCALE = (SCALE / 10) + 0.01f;

/**
 * @brief Scaling factor for objects.
 */
constexpr float OBJECTS_SCALE = (SCALE / 2) + 0.0f;

constexpr float SCORE_BAR_SCALE = (SCALE * 3.5f);

struct LARGE_MESSAGE_LABEL
{
    static constexpr Vector2 Position = {UI::SCREEN_WIDTH / 3.8f, UI::SCREEN_HEIGHT / 6};
    static constexpr float Scale = 0.9F;
};
struct SCORE_BAR
{
    static constexpr Vector2 Position = {900, 200};
    static constexpr float Scale = (SCALE * 3.5f) / 10;
};

struct MENU_PANEL
{
    static constexpr Vector2 Position_ = {UI::SCREEN_WIDTH / 3.8f, UI::SCREEN_HEIGHT / 6};
    static constexpr float Scale = 0.75F;
};

struct START_BUTTON
{
    static constexpr Vector2 Position_ = {(UI::SCREEN_WIDTH / 3) + 45, UI::SCREEN_HEIGHT / 3};
    static constexpr float Scale_ = 0.9F;
};
struct EXIT_BUTTON
{
    static constexpr Vector2 Position_ = {(UI::SCREEN_WIDTH / 3) + 70, (UI::SCREEN_HEIGHT / 2) + 75};
    static constexpr float Scale_ = 0.75F;
};
struct RESTART_BUTTON
{
    static constexpr Vector2 Position_ = {UI::LABEL_REC.x + 260, UI::LABEL_REC.y + 200};
    static constexpr float Scale_ = 0.5F;
};

} // namespace UI
