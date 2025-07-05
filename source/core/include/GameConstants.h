#pragma once
#include <raylib.h>

namespace GameConst
{
	inline constexpr float GameTick = 0.15f;
}
namespace UI
{
	inline constexpr int LABLE_FONT_SIZE = 96;
	inline constexpr int SCREEN_WIDTH = 1920;
	inline constexpr int SCREEN_HEIGHT = 960;
	constexpr Rectangle WIN_LABLEL = { (SCREEN_WIDTH / 3)-50, (SCREEN_HEIGHT / 3) ,650,200 };
	constexpr Rectangle LOSE_LABLEL = { (SCREEN_WIDTH / 3)-50, (SCREEN_HEIGHT / 2.5) ,650,200 };
	constexpr float SCALE = 2.0f;

	
	constexpr float CELL_SIZE = 30 * SCALE; /*!< Cell size in pixels */

	
	constexpr float BOARD_INITIAL_X_POS = 50.0f;

	
	constexpr float BOARD_INITIAL_Y_POS = 50.0f;

	
	constexpr float BLOCKS_SCALE = (SCALE / 10) + 0.01f;

	constexpr float OBJECTS_SCALE = (SCALE / 2) + 0.0f;

}
