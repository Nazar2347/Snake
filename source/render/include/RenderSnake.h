#pragma once
#include <raylib.h>
#include "RenderConstant.h"
#include "Snake.h"



enum SnakePartType {
    BODY_TURN_TOP_RIGHT = 0,
    BODY_HORIZONTAL,
    BODY_TURN_TOP_LEFT,
    HEAD_UP,
    HEAD_RIGHT,

    BODY_TURN_DOWN_LEFT,
    BODY_VERTICAL,
    HEAD_LEFT,
    HEAD_DOWN,

    BODY_TURN_DOWN_RIGHT,
    TAIL_UP,
    TAIL_RIGHT,

    TAIL_LEFT,
    TAIL_DOWN,
};

class RenderSnake
{
public:
	RenderSnake(Snake& Snake);
	void Draw()const;
    void DrawSnakePart(Rectangle SnakePart, Vector2 Position)const;
    virtual ~RenderSnake();
private:
	Snake Snake_;
	Texture2D SnakeBodyTexture_;
    Rectangle SnakeParts[15] = {
        {0,   0, 64, 64},   //Body turn (top-left)
        {64,  0, 64, 64},   //Body horizontal (top-middle)
        {128, 0, 64, 64},   //Body turn (top-left)
        {192, 0, 64, 64},   //Head up
        {256, 0, 64, 64},   //Head right

        {0,   64, 64, 64},  // Body turn (down-left),  
        {128, 64, 64, 64},  // Body vertical
        {192, 64, 64, 64},  // Head left
        {256, 64,  64, 64},  // Head Down

        {128, 128, 64, 64}, // Body turn (down-right)
        {192, 128, 64, 64}, // Tail up
        {256, 128, 64, 64}, // Tail right

        {192,  192, 64, 64}, // Tail left
        {256, 192, 64, 64},  // Tail down
        
    };

};
