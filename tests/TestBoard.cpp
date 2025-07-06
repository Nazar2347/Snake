#include <catch2/catch_test_macros.hpp>
#include <raylib.h>
#include "Board.h"

// Helper: Create a simple 3x3 board with all cells empty (true)
std::vector<std::vector<bool>> CreateEmptyLevelData(size_t rows = 3, size_t cols = 3) 
{
    return std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
}

TEST_CASE("Board construction and size", "[Board]") 
{
    auto levelData = CreateEmptyLevelData(5, 4);
    Board board(levelData);

    REQUIRE(board.GetLevelXSize() == 4);
    REQUIRE(board.GetLevelYSize() == 5);
}

TEST_CASE("Board GetCellInfo and SetCellType", "[Board]") 
{
    auto levelData = CreateEmptyLevelData();
    Board board(levelData);

    Vector2 pos = {1, 1};
    // Assume ECellType::Empty is the default for 'true' in LevelData
    REQUIRE(board.GetCellInfo(pos) == ECellType::EMPTY);

    board.SetCellType(pos, ECellType::WALL);
    REQUIRE(board.GetCellInfo(pos) == ECellType::WALL);
}

TEST_CASE("Board getLevelData returns correct map", "[Board]")
{
    auto levelData = CreateEmptyLevelData();
    Board board(levelData);

    auto map = board.getLevelData();
    REQUIRE(map.size() == 9); // 3x3 board

    Vector2 pos = {0, 0};
    REQUIRE(map.find(pos) != map.end());
}

TEST_CASE("Board GetEmptyCell returns an empty cell", "[Board]") 
{
    auto levelData = CreateEmptyLevelData();
    Board board(levelData);

    Vector2 emptyCell = board.GetEmptyCell();
    REQUIRE(board.GetCellInfo(emptyCell) == ECellType::EMPTY);

    // Fill all cells, then GetEmptyCell should not return an empty cell (behavior depends on implementation)
    for (size_t y = 0; y < 3; ++y) {
        for (size_t x = 0; x < 3; ++x) {
            board.SetCellType({static_cast<float>(x), static_cast<float>(y)}, ECellType::WALL);
        }
    }
    REQUIRE_FALSE(board.GetCellInfo(emptyCell) == ECellType::EMPTY);
}
