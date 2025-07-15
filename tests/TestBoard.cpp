#include "Board.h"
#include <catch2/catch_test_macros.hpp>
#include <raylib.h>

TEST_CASE("Vector2Equal compares integer values", "[Vector2Equal]")
{
    Vector2 PositionA{1.0f, 2.0f};
    Vector2 PositionB{1.0f, 2.0f};
    Vector2 PositionC{1.1f, 2.0f};
    Vector2 PositionD{1.0f, 2.9f};
    Vector2Equal Equal;

    REQUIRE(Equal(PositionA, PositionB));
    REQUIRE(Equal(PositionA, PositionC)); // 1.0 == 1.1 as int
    REQUIRE(Equal(PositionA, PositionD)); // 2.0 == 2.9 as int
    Vector2 E{2.0f, 2.0f};
    REQUIRE_FALSE(Equal(PositionA, E));
}

TEST_CASE("Vector2Hash produces consistent hashes", "[Vector2Hash]")
{
    Vector2Hash Hash;
    Vector2 PositionA{1.0f, 2.0f};
    Vector2 PositionB{1.0f, 2.0f};
    Vector2 PositionC{2.0f, 1.0f};
    REQUIRE(Hash(PositionA) == Hash(PositionB));
    REQUIRE(Hash(PositionA) != Hash(PositionC));
}

TEST_CASE("Board constructor initializes correctly", "[Board]")
{
    std::vector<std::vector<bool>> Level = {{0, 1}, {1, 0}};
    Board Board(Level);

    REQUIRE(Board.GetLevelXSize() == 2);
    REQUIRE(Board.GetLevelYSize() == 2);

    auto Map = Board.getLevelData();
    REQUIRE(Map.size() == 4);
    REQUIRE(Board.GetCellInfo({0, 0}) == ECellType::EMPTY);
    REQUIRE(Board.GetCellInfo({0, 1}) == ECellType::WALL);
    REQUIRE(Board.GetCellInfo({1, 0}) == ECellType::WALL);
    REQUIRE(Board.GetCellInfo({1, 1}) == ECellType::EMPTY);
}

TEST_CASE("GetCellInfo returns OUT_OF_BORDER for invalid positions", "[Board]")
{
    std::vector<std::vector<bool>> Level = {{0}};
    Board Board(Level);
    REQUIRE(Board.GetCellInfo({5, 5}) == ECellType::OUT_OF_BORDER);
}

TEST_CASE("SetCellType updates cell type if position exists", "[Board]")
{
    std::vector<std::vector<bool>> Level = {{0, 1}};
    Board Board(Level);
    Vector2 Position{0, 0};
    REQUIRE(Board.GetCellInfo(Position) == ECellType::EMPTY);
    Board.SetCellType(Position, ECellType::WALL);
    REQUIRE(Board.GetCellInfo(Position) == ECellType::WALL);

    // Should not throw or change anything for out-of-bounds
    Vector2 Invalid{5, 5};
    Board.SetCellType(Invalid, ECellType::EMPTY);
    REQUIRE(Board.GetCellInfo(Invalid) == ECellType::OUT_OF_BORDER);
}

TEST_CASE("getLevelData returns the correct map", "[Board]")
{
    std::vector<std::vector<bool>> Level = {
        {0, 1},
    };
    Board Board(Level);
    auto Map = Board.getLevelData();
    REQUIRE(Map.size() == 2);
    REQUIRE(Map.at(Vector2{0, 0}) == ECellType::EMPTY);
    REQUIRE(Map.at(Vector2{1, 0}) == ECellType::WALL);
}

TEST_CASE("GetEmptyCell returns first empty cell or {1,1}", "[Board]")
{
    std::vector<std::vector<bool>> Level = {{1, 1}, {1, 0}};
    Board Board1(Level);
    Vector2 Empty = Board1.GetEmptyCell();
    REQUIRE(Board1.GetCellInfo(Empty) == ECellType::EMPTY);

    // All walls: should return {1,1}
    std::vector<std::vector<bool>> Level2 = {{1, 1}, {1, 1}};
    Board Board2(Level2);
    REQUIRE(Board2.GetEmptyCell().x == 1.0f);
    REQUIRE(Board2.GetEmptyCell().y == 1.0f);
}

TEST_CASE("GetLevelXSize and GetLevelYSize return correct sizes", "[Board]")
{
    std::vector<std::vector<bool>> Level = {{0, 1, 0}, {1, 0, 1}};
    Board Board(Level);
    REQUIRE(Board.GetLevelXSize() == 3);
    REQUIRE(Board.GetLevelYSize() == 2);
}
