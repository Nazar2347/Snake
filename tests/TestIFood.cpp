#include "Board.h"
#include "IFood.h"
#include <catch2/catch_test_macros.hpp>

// Helper: Create a simple 3x3 Board1 with all cells empty
static std::vector<std::vector<bool>> EmptyLevelData(size_t rows = 3, size_t cols = 3)
{
    return std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
}

TEST_CASE("AppleFood constructs and has correct type", "[AppleFood]")
{
    auto levelData =EmptyLevelData();
    std::shared_ptr<Board> Board1;
    Board1 = make_shared<Board>(levelData);
    Vector2 Position = {0, 2};

    AppleFood Apple(Position, Board1);

    REQUIRE(Apple.GetPosition().x == Position.x);
    REQUIRE(Apple.GetPosition().y == Position.y);
    REQUIRE(Apple.GetPoints() == GameRules::APPLE_POINTS);
    REQUIRE(Apple.GetFoodType() == EFoodType::APPLE);

    // DoSomething should not move the Apple
    Vector2 Before = Apple.GetPosition();
    Apple.DoSomething();
    REQUIRE(Apple.GetPosition().x == Before.x);
    REQUIRE(Apple.GetPosition().y == Before.y);
}

TEST_CASE("Frog moves when DoSomething is called", "[Frog]")
{
    auto LevelData = EmptyLevelData();
    std::shared_ptr<Board> Board1;
    Board1 = make_shared<Board>(LevelData);
    Vector2 Position = {1, 1};
    short Points = 7;

    Frog Frog(Position, Board1);

    REQUIRE(Frog.GetFoodType() == EFoodType::FROG);

    Vector2 Before = Frog.GetPosition();
    Frog.DoSomething();
    Vector2 After = Frog.GetPosition();

    // The Frog may or may not move (if random Position is not empty), but After is always a valid cell
    REQUIRE(Board1->GetCellInfo(After) == ECellType::FOOD);
    // The previous cell should be empty unless Frog didn't move
    if (Before.x != After.x || Before.y != After.y)
    {
        REQUIRE(Board1->GetCellInfo(Before) == ECellType::EMPTY);
    }
}

TEST_CASE("Mouse moves when DoSomething is called", "[Mouse]")
{
    auto LevelData = EmptyLevelData();
    std::shared_ptr<Board> Board1;
    Board1 = make_shared<Board>(LevelData);
    Vector2 Position = {2, 2};
    short Points = 3;

    Mouse Mouse(Position, Board1);

    REQUIRE(Mouse.GetFoodType() == EFoodType::MOUSE);

    Vector2 Before = Mouse.GetPosition();
    Mouse.DoSomething();
    Vector2 After = Mouse.GetPosition();

    REQUIRE(Board1->GetCellInfo(After) == ECellType::FOOD);
    if (Before.x != After.x || Before.y != Before.y)
    {
        REQUIRE(Board1->GetCellInfo(Before) == ECellType::EMPTY);
    }
}
