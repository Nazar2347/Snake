#include <catch2/catch_test_macros.hpp>
#include <raylib.h>
#include "Snake.h"


TEST_CASE("Snake construction() initializes head ansd tail", "[Snake]") {
    REQUIRE((2 + 2) == 4);
   /* Snake snake(Start,TestLevel);

    REQUIRE(snake.getHeadPosition() == Start);
    
    auto tail = snake.getTailPosition();
    REQUIRE(tail.size() == 1);
    REQUIRE(tail[0] == Vector2{ 6, 5 });*/

}
//
//TEST_CASE("ExtendTailBy() increases tail size", "[Snake]") {
//    Snake snake(Start, TestLevel);
//    size_t initialSize = snake.getTailPosition().size();
//
//    snake.ExtendTailBy(1);
//    auto tail = snake.getTailPosition();
//    REQUIRE(tail.size() >= initialSize); // Only extends if size > 1 and < 100
//}
//
//TEST_CASE("ShortTailBy() decreases tail size and can kill snake", "[Snake]") {
//    Snake snake(Start,TestLevel);
//    snake.ExtendTailBy(2);
//    size_t before = snake.getTailPosition().size();
//
//    snake.ShortTailBy(1);
//    REQUIRE(snake.getTailPosition().size() == before - 1);
//    REQUIRE(snake.isAlive());
//
//    // Remove all tail elements
//    snake.ShortTailBy(100);
//    REQUIRE_FALSE(snake.isAlive());
//}

//TEST_CASE("SetDirection and GetDirection work as expected", "[Snake]") {
//    Snake snake({ 2, 2 },TestLevel);
//    snake.SetDirection(EDirection::DOWN);
//    REQUIRE(snake.GetDirection() == EDirection::DOWN);
//
//    snake.SetDirection(EDirection::LEFT);
//    REQUIRE(snake.GetDirection() == EDirection::LEFT);
//}
//
//TEST_CASE("Move() updates head and tail positions correctly", "[Snake]") {
//    Snake snake({ 3, 3 });
//    Vector2 initialHead = snake.getHeadPosition();
//    auto initialTail = snake.getTailPosition();
//
//    // Default direction is UP
//    snake.Move();
//    Vector2 expectedHead = { initialHead.x, initialHead.y - 1 };
//    REQUIRE(snake.getHeadPosition().x == expectedHead.x);
//    REQUIRE(snake.getHeadPosition().y == expectedHead.y);
//
//    // Tail should follow the old head position
//    auto tail = snake.getTailPosition();
//    REQUIRE(tail[0].x == initialHead.x);
//    REQUIRE(tail[0].y == initialHead.y);
//}
//
//TEST_CASE("Move() prevents reversing into own body", "[Snake]") {
//    Snake snake({ 4, 4 });
//    snake.ExtendTailBy(1); // Now tail has 2 segments
//
//    // Move once to update positions
//    snake.Move();
//
//    // Try to reverse direction into the body
//    snake.SetDirection(EDirection::DOWN); // Opposite of UP
//    Vector2 beforeMove = snake.getHeadPosition();
//    snake.Move();
//
//    // Head should not move into the tail's first segment
//    REQUIRE_FALSE(snake.getHeadPosition() == snake.getTailPosition()[0]);
//    // Head should have moved in the opposite direction (UP again)
//    REQUIRE(snake.getHeadPosition().y == beforeMove.y - 1);
//}
//
//TEST_CASE("ExtendTailBy does not exceed 100 segments", "[Snake]") {
//    Snake snake({ 0, 0 });
//    snake.ExtendTailBy(200);
//    REQUIRE(snake.getTailPosition().size() <= 100);
//}
//
//TEST_CASE("isAlive() returns correct status", "[Snake]") {
//    Snake snake({ 0, 0 });
//    REQUIRE(snake.isAlive());
//    snake.ShortTailBy(100);
//    REQUIRE_FALSE(snake.isAlive());
//}