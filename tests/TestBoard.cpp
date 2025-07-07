#include <catch2/catch_test_macros.hpp>
#include <raylib.h>
#include "Board.h"


TEST_CASE("Vector2Equal compares integer values", "[Vector2Equal]") {
    Vector2 a{ 1.0f, 2.0f };
    Vector2 b{ 1.0f, 2.0f };
    Vector2 c{ 1.1f, 2.0f };
    Vector2 d{ 1.0f, 2.9f };
    Vector2Equal eq;

    REQUIRE(eq(a, b));
    REQUIRE(eq(a, c)); // 1.0 == 1.1 as int
    REQUIRE(eq(a, d)); // 2.0 == 2.9 as int
    Vector2 e{ 2.0f, 2.0f };
    REQUIRE_FALSE(eq(a, e));
}

TEST_CASE("Vector2Hash produces consistent hashes", "[Vector2Hash]") {
    Vector2Hash hash;
    Vector2 a{ 1.0f, 2.0f };
    Vector2 b{ 1.0f, 2.0f };
    Vector2 c{ 2.0f, 1.0f };
    REQUIRE(hash(a) == hash(b));
    REQUIRE(hash(a) != hash(c));
}

TEST_CASE("Board constructor initializes correctly", "[Board]") {
    std::vector<std::vector<bool>> level = {
        {0, 1},
        {1, 0}
    };
    Board board(level);

    REQUIRE(board.GetLevelXSize() == 2);
    REQUIRE(board.GetLevelYSize() == 2);

    auto map = board.getLevelData();
    REQUIRE(map.size() == 4);
    REQUIRE(board.GetCellInfo({ 0,0 }) == ECellType::EMPTY);
    REQUIRE(board.GetCellInfo({ 0,1 }) == ECellType::WALL);
    REQUIRE(board.GetCellInfo({ 1,0 }) == ECellType::WALL);
    REQUIRE(board.GetCellInfo({ 1,1 }) == ECellType::EMPTY);
}

TEST_CASE("GetCellInfo returns OUT_OF_BORDER for invalid positions", "[Board]") {
    std::vector<std::vector<bool>> level = {
        {0}
    };
    Board board(level);
    REQUIRE(board.GetCellInfo({ 5,5 }) == ECellType::OUT_OF_BORDER);
}

TEST_CASE("SetCellType updates cell type if position exists", "[Board]") {
    std::vector<std::vector<bool>> level = {
        {0, 1}
    };
    Board board(level);
    Vector2 pos{ 0, 0 };
    REQUIRE(board.GetCellInfo(pos) == ECellType::EMPTY);
    board.SetCellType(pos, ECellType::WALL);
    REQUIRE(board.GetCellInfo(pos) == ECellType::WALL);

    // Should not throw or change anything for out-of-bounds
    Vector2 invalid{ 5, 5 };
    board.SetCellType(invalid, ECellType::EMPTY);
    REQUIRE(board.GetCellInfo(invalid) == ECellType::OUT_OF_BORDER);
}

TEST_CASE("getLevelData returns the correct map", "[Board]") {
    std::vector<std::vector<bool>> level = {
        {0, 1},
    };
    Board board(level);
    auto map = board.getLevelData();
    REQUIRE(map.size() == 2);
    REQUIRE(map.at(Vector2{ 0,0 }) == ECellType::EMPTY);
    REQUIRE(map.at(Vector2{ 1,0 }) == ECellType::WALL);
}

TEST_CASE("GetEmptyCell returns first empty cell or {1,1}", "[Board]") {
    std::vector<std::vector<bool>> level = {
        {1, 1},
        {1, 0}
    };
    Board board(level);
    Vector2 empty = board.GetEmptyCell();
    REQUIRE(board.GetCellInfo(empty) == ECellType::EMPTY);

    // All walls: should return {1,1}
    std::vector<std::vector<bool>> allWalls = {
        {1, 1},
        {1, 1}
    };
    Board board2(allWalls);
    REQUIRE(board2.GetEmptyCell().x == 1.0f);
    REQUIRE(board2.GetEmptyCell().y == 1.0f);
}

TEST_CASE("GetLevelXSize and GetLevelYSize return correct sizes", "[Board]") {
    std::vector<std::vector<bool>> level = {
        {0, 1, 0},
        {1, 0, 1}
    };
    Board board(level);
    REQUIRE(board.GetLevelXSize() == 3);
    REQUIRE(board.GetLevelYSize() == 2);
}
