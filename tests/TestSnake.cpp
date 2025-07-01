#include <catch2/catch_test_macros.hpp>
#include <raylib.h>
#include "Snake.h"
#include "Board.h"

std::vector<std::vector <bool>> TestLevelData = {
    {1,1,1,1,1,1},
    {1,0,0,0,0,1},
    {1,0,0,0,0,1},
    {1,0,0,0,0,1},
    {1,0,0,0,0,1},
    {1,1,1,1,1,1} };
Board TestLevel(TestLevelData);


TEST_CASE("Snake Constructor initializes correctly", "[Snake]") {
    Vector2 start;
    start.x = 1;
    start.y = 1;
    Snake snake(start, TestLevel);

    REQUIRE(snake.getHeadPosition().x == 1);
    REQUIRE(snake.getHeadPosition().y == 1);
    std::vector<Vector2> tail = snake.getTailPosition();
    REQUIRE(tail.size() == 1);
    REQUIRE(tail[0].x == 2);
    REQUIRE(tail[0].y == 1);
    REQUIRE(snake.isAlive());
    REQUIRE(snake.GetDirection() == EDirection::LEFT);
}

TEST_CASE("Snake::SetDirection and GetDirection", "[Snake]") {
    Vector2 start;
    start.x = 0;
    start.y = 0;
    Snake snake(start, TestLevel);

    snake.SetDirection(EDirection::LEFT);
    REQUIRE(snake.GetDirection() == EDirection::LEFT);

    snake.SetDirection(EDirection::DOWN);
    REQUIRE(snake.GetDirection() == EDirection::DOWN);
}

TEST_CASE("Snake::ChangeTailSizeBy grows and shrinks tail", "[Snake]") {
    Vector2 start;
    start.x = 0;
    start.y = 0;
    Snake snake(start, TestLevel);

    // Grow tail by 2
    snake.ChangeTailSizeBy(2);
    std::vector<Vector2> tail = snake.getTailPosition();
    REQUIRE(tail.size() == 3);

    // Shrink tail by 1
    snake.ChangeTailSizeBy(-1);
    tail = snake.getTailPosition();
    REQUIRE(tail.size() == 2);

    // Shrink tail to zero, snake should die
    snake.ChangeTailSizeBy(-2);
    REQUIRE(snake.getTailPosition().size() == 0);
    REQUIRE_FALSE(snake.isAlive()); //problem
}


TEST_CASE("Snake::isAlive returns correct state", "[Snake]") {
    Vector2 start;
    start.x = 0;
    start.y = 0;
    Snake snake(start, TestLevel);

    REQUIRE(snake.isAlive());
    snake.ChangeTailSizeBy(-1); // Remove only tail segment
    snake.ChangeTailSizeBy(-1); // Should die
    REQUIRE_FALSE(snake.isAlive());
}

TEST_CASE("Snake::getHeadPosition and getTailPosition", "[Snake]") {
    Vector2 start;
    start.x = 5;
    start.y = 5;
    Snake snake(start, TestLevel);

    REQUIRE(snake.getHeadPosition().x == 5);
    REQUIRE(snake.getHeadPosition().y == 5);
    std::vector<Vector2> tail = snake.getTailPosition();
    REQUIRE(tail.size() == 1);
    REQUIRE(tail[0].x == 6);
    REQUIRE(tail[0].y == 5);
}

TEST_CASE("Snake interacts correctly with custom TestLevel board", "[Snake][Board]") {
    // Use the provided TestLevelData and TestLevel
    Vector2 start;
    start.x = 2;
    start.y = 2;
    Snake snake(start, TestLevel);

    // Initial state
    REQUIRE(snake.getHeadPosition().x == 2);
    REQUIRE(snake.getHeadPosition().y == 2);
    REQUIRE(snake.isAlive());

    // Move up (should be valid)
    snake.SetDirection(EDirection::UP);
    snake.Move();
    REQUIRE(snake.getHeadPosition().x == 2);
    REQUIRE(snake.getHeadPosition().y == 1);
    REQUIRE(snake.isAlive());

    // Move left (should be valid)
    snake.SetDirection(EDirection::LEFT);
    snake.Move();
    REQUIRE(snake.getHeadPosition().x == 1);
    REQUIRE(snake.getHeadPosition().y == 1);
    REQUIRE(snake.isAlive());

    // Move left into wall (should die or stop, depending on implementation)
    snake.Move();
    // The expected result depends on your Snake implementation:
    // If hitting a wall kills the snake:
    REQUIRE_FALSE(snake.isAlive());
    // If hitting a wall prevents movement but doesn't kill:
    // REQUIRE(snake.getHeadPosition().x == 1);
    // REQUIRE(snake.getHeadPosition().y == 1);
}

TEST_CASE("Snake tail grows, shrinks, and follows head correctly on TestLevel", "[Snake][Tail]") {
    Vector2 start;
    start.x = 2;
    start.y = 2;
    Snake snake(start, TestLevel);

    // Initial tail check
    std::vector<Vector2> tail = snake.getTailPosition();
    REQUIRE(tail.size() == 1);
    REQUIRE(tail[0].x == 3);
    REQUIRE(tail[0].y == 2);

    // Grow tail by 2
    snake.ChangeTailSizeBy(2);
    tail = snake.getTailPosition();
    REQUIRE(tail.size() == 3);

    // Move right
    snake.SetDirection(EDirection::LEFT);
    snake.Move();
    REQUIRE(snake.getHeadPosition().x == 1); //problem
    REQUIRE(snake.getHeadPosition().y == 2);

    tail = snake.getTailPosition();
    REQUIRE(tail.size() == 3);
    REQUIRE(tail[0].x == 2);
    REQUIRE(tail[0].y == 2);
    REQUIRE(tail[1].x == 3);
    REQUIRE(tail[1].y == 2);
    REQUIRE(tail[2].x == 4);
    REQUIRE(tail[2].y == 2);

    // Shrink tail by 2
    snake.ChangeTailSizeBy(-2);
    tail = snake.getTailPosition();
    REQUIRE(tail.size() == 1);

    // Move down
    snake.SetDirection(EDirection::DOWN);
    snake.Move();
    REQUIRE(snake.getHeadPosition().x == 1);
    REQUIRE(snake.getHeadPosition().y == 3);

    tail = snake.getTailPosition();
    REQUIRE(tail.size() == 1);
    REQUIRE(tail[0].x == 1);
    REQUIRE(tail[0].y == 2);
}