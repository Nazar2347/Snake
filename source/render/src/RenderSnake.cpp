#include "RenderSnake.h"


RenderSnake::RenderSnake(Snake& Snake): Snake_(Snake)
{
    
    Image ImageSnake = LoadImage("Assets/Snake-Graphics.png");
    SnakeBodyTexture_ = LoadTextureFromImage(ImageSnake);

    UnloadImage(ImageSnake);

}
void RenderSnake::Draw()const
{
    //Render SnakeHead
    DrawSnakePart(SnakeParts[SnakePartType::TAIL_LEFT], Snake_.getHeadPosition());
}
void RenderSnake::DrawSnakePart(Rectangle SnakePart, Vector2 Position)const
{
    DrawTextureRec(SnakeBodyTexture_, SnakePart, 
        { Position.x * CELL_SIZE + BOARD_INITIAL_X_POS,
          Position.y * CELL_SIZE + BOARD_INITIAL_Y_POS },
        WHITE);
    
}

RenderSnake::~RenderSnake()
{
    UnloadTexture(SnakeBodyTexture_);
}


