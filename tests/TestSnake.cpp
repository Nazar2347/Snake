#include "Board.h"
#include "Snake.h"
#include <catch2/catch_test_macros.hpp>
#include <raylib.h>

std::vector<std::vector <bool>> TestLevelData = 
{
    {1,1,1,1,1,1},
    {1,0,0,0,0,1},
    {1,0,0,0,0,1},
    {1,0,0,0,0,1},
    {1,0,0,0,0,1},
    {1,1,1,1,1,1} 
};

auto TestLevel = std::make_shared<Board>(TestLevelData);

TEST_CASE("Snake Constructor initializes correctly", "[Snake]")
{
    Vector2 StartPosition;
    StartPosition.x = 1;
    StartPosition.y = 1;
    Snake Snake1(StartPosition, TestLevel);

    REQUIRE(Snake1.GetHeadPosition().x == 1);
    REQUIRE(Snake1.GetHeadPosition().y == 1);
    std::vector<Vector2> tail = Snake1.GetTailPosition();
    REQUIRE(tail.size() == 1);
    REQUIRE(tail[0].x == 2);
    REQUIRE(tail[0].y == 1);
    REQUIRE(Snake1.isAlive());
    REQUIRE(Snake1.GetDirection() == EDirection::LEFT);
}

TEST_CASE("Snake::SetDirection and GetDirection", "[Snake]")
{
    Vector2 StartPosition;
    StartPosition.x = 0;
    StartPosition.y = 0;
    Snake Snake1(StartPosition, TestLevel);

    Snake1.SetDirection(EDirection::LEFT);
    REQUIRE(Snake1.GetDirection() == EDirection::LEFT);

    Snake1.SetDirection(EDirection::DOWN);
    REQUIRE(Snake1.GetDirection() == EDirection::DOWN);
}

TEST_CASE("Snake::ChangeTailSizeBy grows and shrinks tail", "[Snake]")
{
    Vector2 StartPosition;
    StartPosition.x = 0;
    StartPosition.y = 0;
    Snake Snake(StartPosition, TestLevel);

    // Grow SnakeBody by 2
    Snake.ChangeTailSizeBy(2);
    std::vector<Vector2> SnakeBody = Snake.GetTailPosition();
    REQUIRE(SnakeBody.size() == 3);

    // Shrink SnakeBody by 1
    Snake.ChangeTailSizeBy(-1);
    SnakeBody = Snake.GetTailPosition();
    REQUIRE(SnakeBody.size() == 2);

    // Shrink SnakeBody to zero, Snake1 should die
    Snake.ChangeTailSizeBy(-2);
    REQUIRE(Snake.GetTailPosition().size() == 0);
    REQUIRE_FALSE(Snake.isAlive()); // problem
}

TEST_CASE("Snake::isAlive returns correct state", "[Snake]")
{
    Vector2 StartPostition;
    StartPostition.x = 0;
    StartPostition.y = 0;
    Snake Snake(StartPostition, TestLevel);

    REQUIRE(Snake.isAlive());
    Snake.ChangeTailSizeBy(-1); // Remove only SnakeBody segment
    Snake.ChangeTailSizeBy(-1); // Should die
    REQUIRE_FALSE(Snake.isAlive());
}

TEST_CASE("Snake::getHeadPosition and getTailPosition", "[Snake]")
{
    Vector2 StartPosition;
    StartPosition.x = 5;
    StartPosition.y = 5;
    Snake Snake1(StartPosition, TestLevel);

    REQUIRE(Snake1.GetHeadPosition().x == 5);
    REQUIRE(Snake1.GetHeadPosition().y == 5);
    std::vector<Vector2> SnakeBody = Snake1.GetTailPosition();
    REQUIRE(SnakeBody.size() == 1);
    REQUIRE(SnakeBody[0].x == 6);
    REQUIRE(SnakeBody[0].y == 5);
}

TEST_CASE("Snake interacts correctly with custom TestLevel board", "[Snake][Board]")
{
    // Use the provided TestLevelData and TestLevel
    Vector2 StartPosition;
    StartPosition.x = 2;
    StartPosition.y = 2;
    Snake Snake1(StartPosition, TestLevel);

    // Initial state
    REQUIRE(Snake1.GetHeadPosition().x == 2);
    REQUIRE(Snake1.GetHeadPosition().y == 2);
    REQUIRE(Snake1.isAlive());

    // Move up (should be valid)
    Snake1.SetDirection(EDirection::UP);
    Snake1.Move();
    REQUIRE(Snake1.GetHeadPosition().x == 2);
    REQUIRE(Snake1.GetHeadPosition().y == 1);
    REQUIRE(Snake1.isAlive());

    // Move left (should be valid)
    Snake1.SetDirection(EDirection::LEFT);
    Snake1.Move();
    REQUIRE(Snake1.GetHeadPosition().x == 1);
    REQUIRE(Snake1.GetHeadPosition().y == 1);
    REQUIRE(Snake1.isAlive());

    // Move left into wall (should die or stop, depending on implementation)
    Snake1.Move();
    // The expected result depends on your Snake implementation:
    // If hitting a wall kills the Snake1:
    REQUIRE_FALSE(Snake1.isAlive());
    // If hitting a wall prevents movement but doesn't kill:
    // REQUIRE(Snake1.getHeadPosition().x == 1);
    // REQUIRE(Snake1.getHeadPosition().y == 1);
}

TEST_CASE("Snake tail grows, shrinks, and follows head correctly on TestLevel", "[Snake][Tail]")
{
    Vector2 StartPostition;
    StartPostition.x = 2;
    StartPostition.y = 2;
    Snake Snake(StartPostition, TestLevel);

    // Initial SnakeBody check
    std::vector<Vector2> SnakeBody = Snake.GetTailPosition();
    REQUIRE(SnakeBody.size() == 1);
    REQUIRE(SnakeBody[0].x == 3);
    REQUIRE(SnakeBody[0].y == 2);

    // Grow SnakeBody by 2
    Snake.ChangeTailSizeBy(2);
    SnakeBody = Snake.GetTailPosition();
    REQUIRE(SnakeBody.size() == 3);

    // Move right
    Snake.SetDirection(EDirection::LEFT);
    Snake.Move();
    REQUIRE(Snake.GetHeadPosition().x == 1); // problem
    REQUIRE(Snake.GetHeadPosition().y == 2);

    SnakeBody = Snake.GetTailPosition();
    REQUIRE(SnakeBody.size() == 3);
    REQUIRE(SnakeBody[0].x == 2);
    REQUIRE(SnakeBody[0].y == 2);
    REQUIRE(SnakeBody[1].x == 3);
    REQUIRE(SnakeBody[1].y == 2);
    REQUIRE(SnakeBody[2].x == 4);
    REQUIRE(SnakeBody[2].y == 2);

    // Shrink SnakeBody by 2
    Snake.ChangeTailSizeBy(-2);
    SnakeBody = Snake.GetTailPosition();
    REQUIRE(SnakeBody.size() == 1);

    // Move down
    Snake.SetDirection(EDirection::DOWN);
    Snake.Move();
    REQUIRE(Snake.GetHeadPosition().x == 1);
    REQUIRE(Snake.GetHeadPosition().y == 3);

    SnakeBody = Snake.GetTailPosition();
    REQUIRE(SnakeBody.size() == 1);
    REQUIRE(SnakeBody[0].x == 1);
    REQUIRE(SnakeBody[0].y == 2);
}