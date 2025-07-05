#include <catch2/catch_test_macros.hpp>
#include <raylib.h>
#include "Board.h"
#include "IFood.h"

// Helper: Create a simple 3x3 board with all cells empty
static std::vector<std::vector<bool>> CreateEmptyLevelData(size_t rows = 3, size_t cols = 3)
{
    return std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
}


TEST_CASE("AppleFood constructs and has correct type", "[AppleFood]") 
{
    auto levelData = CreateEmptyLevelData();
    Board board(levelData);
    Vector2 pos = {0, 2};
    

    AppleFood apple(pos, board);

    REQUIRE(apple.GetPosition().x == pos.x);
    REQUIRE(apple.GetPosition().y == pos.y);
    REQUIRE(apple.GetPoints() == GameRules::APPLE_POINTS);
    REQUIRE(apple.GetFoodType() == EFoodType::APPLE);

    // DoSomething should not move the apple
    Vector2 before = apple.GetPosition();
    apple.DoSomething();
    REQUIRE(apple.GetPosition().x == before.x);
    REQUIRE(apple.GetPosition().y == before.y);
}

TEST_CASE("Frog moves when DoSomething is called", "[Frog]")
{
    auto levelData = CreateEmptyLevelData();
    Board board(levelData);
    Vector2 pos = {1, 1};
    short points = 7;

    Frog frog(pos, board);

    REQUIRE(frog.GetFoodType() == EFoodType::FROG);

    Vector2 before = frog.GetPosition();
    frog.DoSomething();
    Vector2 after = frog.GetPosition();

    // The frog may or may not move (if random pos is not empty), but after is always a valid cell
    REQUIRE(board.GetCellInfo(after) == ECellType::FOOD);
    // The previous cell should be empty unless frog didn't move
    if (before.x != after.x || before.y != after.y) {
        REQUIRE(board.GetCellInfo(before) == ECellType::EMPTY);
    }
}

TEST_CASE("Mouse moves when DoSomething is called", "[Mouse]") 
{
    auto levelData = CreateEmptyLevelData();
    Board board(levelData);
    Vector2 pos = {2, 2};
    short points = 3;

    Mouse mouse( pos, board);

    REQUIRE(mouse.GetFoodType() == EFoodType::MOUSE);

    Vector2 before = mouse.GetPosition();
    mouse.DoSomething();
    Vector2 after = mouse.GetPosition();

    REQUIRE(board.GetCellInfo(after) == ECellType::FOOD);
    if (before.x != after.x || before.y != before.y) {
        REQUIRE(board.GetCellInfo(before) == ECellType::EMPTY);
    }
}
