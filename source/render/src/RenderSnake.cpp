#include "RenderSnake.h"


RenderSnake::RenderSnake( Snake* Snake):Snake_(Snake)
{
    if (Snake != nullptr)
    {
        Image ImageSnake = LoadImage("Assets/Snake-Graphics.png");
        SnakeBodyTexture_ = LoadTextureFromImage(ImageSnake);

        UnloadImage(ImageSnake);
    }
    else
    {
        // Error: no initialized Snake
    }
}
void RenderSnake::Draw()const
{
    if (Snake_ != nullptr)
    {
        //Render SnakeHead
        DrawSnakePart(SnakeParts[SnakePartType::HEAD_UP], Snake_->getHeadPosition());
        for (int i = 0; i < Snake_->getTailPosition().size(); i++)
        {
            if (i == Snake_->getTailPosition().size() - 1)
            {
                DrawSnakePart(SnakeParts[SnakePartType::TAIL_UP], Snake_->getTailPosition()[i]);
                break;
            }
            DrawSnakePart(SnakeParts[SnakePartType::BODY_HORIZONTAL], Snake_->getTailPosition()[i]);
        }
    }
    else
    {
        DrawText("NO INITIALIZED SNAKE", BOARD_INITIAL_X_POS, BOARD_INITIAL_Y_POS, 14, RED);
    }


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


