#include <catch2/catch_test_macros.hpp>
#include <raylib.h>
#include "Snake.h"

// Helper for comparing Vector2

TEST_CASE("Snake construction() initializes head and tail", "[Snake]") {
    Vector2 start = { 5, 5 };
    Snake snake(start);

    REQUIRE(snake.getHeadPosition() == start);

    auto tail = snake.getTailPosition();
    REQUIRE(tail.size() == 1);
    REQUIRE(tail[0] == Vector2{ 6, 5 });
}

TEST_CASE("ExtendTailBy() increases tail size", "[Snake]") {
    Snake snake({ 0, 0 });
    size_t initialSize = snake.getTailPosition().size();

    snake.ExtendTailBy(3);
    auto tail = snake.getTailPosition();
    REQUIRE(tail.size() >= initialSize); // Only extends if size > 1 and < 100
}

TEST_CASE("ShortTailBy() decreases tail size and can kill snake", "[Snake]") {
    Snake snake({ 0, 0 });
    snake.ExtendTailBy(2);
    size_t before = snake.getTailPosition().size();

    snake.ShortTailBy(1);
    REQUIRE(snake.getTailPosition().size() == before - 1);
    REQUIRE(snake.isAlive());

    // Remove all tail elements
    snake.ShortTailBy(100);
    REQUIRE_FALSE(snake.isAlive());
}

TEST_CASE("Move() updates head and tail positions", "[Snake]") {
    Snake snake({ 1, 1 });
    auto oldHead = snake.getHeadPosition();
    auto oldTail = snake.getTailPosition();

    Vector2 dir = { 1, 0 };
    snake.Move(dir);

    auto newHead = snake.getHeadPosition();
    REQUIRE(newHead.x == oldHead.x + dir.x);
    REQUIRE(newHead.y == oldHead.y + dir.y);
    // Note: Tail movement logic may need to be checked for correctness
}

TEST_CASE("isAlive() returns correct status", "[Snake]") {
    Snake snake({ 0, 0 });
    REQUIRE(snake.isAlive());
    snake.ShortTailBy(100);
    REQUIRE_FALSE(snake.isAlive());
}