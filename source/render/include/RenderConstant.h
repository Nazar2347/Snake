#pragma once

#include <raylib.h>

/**
 * @brief Global rendering constants for board and cell layout.
 */

/**
 * @brief Global scale factor for rendering.
 */
constexpr float SCALE = 2.0f;

/**
 * @brief Size of a single board cell in pixels, after scaling.
 */
constexpr float CELL_SIZE = 30 * SCALE; /*!< Cell size in pixels */

/**
 * @brief Initial X position (in pixels) where the board is rendered.
 */
constexpr float BOARD_INITIAL_X_POS = 50.0f;

/**
 * @brief Initial Y position (in pixels) where the board is rendered.
 */
constexpr float BOARD_INITIAL_Y_POS = 50.0f;

/**
 * @brief Scale factor for rendering individual blocks.
 */
constexpr float BLOCKS_SCALE = (SCALE / 10) + 0.01f;