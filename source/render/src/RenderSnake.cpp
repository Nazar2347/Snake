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
        DrawHead();
        DrawBody();
        DrawTail();

       
    }
    else
    {
        DrawText("NO INITIALIZED SNAKE", static_cast<int>(BOARD_INITIAL_X_POS), static_cast<int>(BOARD_INITIAL_Y_POS), 14, RED);
    }


}
void RenderSnake::DrawSnakePart(Rectangle SnakePart, Vector2 Position)const
{
    DrawTextureRec(SnakeBodyTexture_, SnakePart, 
        { Position.x * CELL_SIZE + BOARD_INITIAL_X_POS,
          Position.y * CELL_SIZE + BOARD_INITIAL_Y_POS },
        WHITE);
    
}

void RenderSnake::DrawHead() const
{
    //Render SnakeHead

    if (Snake_->GetDirection() == EDirection::UP)
    {
        DrawSnakePart(SnakeParts[SnakePartType::HEAD_UP], Snake_->getHeadPosition());
    }
    else if (Snake_->GetDirection() == EDirection::DOWN)
    {
        DrawSnakePart(SnakeParts[SnakePartType::HEAD_DOWN], Snake_->getHeadPosition());
    }
    else if (Snake_->GetDirection() == EDirection::RIGHT)
    {
        DrawSnakePart(SnakeParts[SnakePartType::HEAD_RIGHT], Snake_->getHeadPosition());
    }
    else if (Snake_->GetDirection() == EDirection::LEFT)
    {
        DrawSnakePart(SnakeParts[SnakePartType::HEAD_LEFT], Snake_->getHeadPosition());
    }
}

void RenderSnake::DrawBody() const
{
    Vector2 Next = Snake_->getHeadPosition();

    for (int i = 0; i < Snake_->getTailPosition().size() - 1; i++)
    {
        Vector2 Current = Snake_->getTailPosition()[i];
        Vector2 Previous = Snake_->getTailPosition()[i + 1];
        
            if (Next.x == Previous.x)
            {
                DrawSnakePart(SnakeParts[SnakePartType::BODY_VERTICAL], Current);
            }
            else if (Next.y == Previous.y )
            {
                DrawSnakePart(SnakeParts[SnakePartType::BODY_HORIZONTAL], Current);
            }


            else if (Next.y < Previous.y && Next.x > Previous.x) // 9-12 +
            {
                DrawSnakePart(SnakeParts[SnakePartType::BODY_TURN_TOP_RIGHT], Current);
            }
            else if (Next.y < Previous.y && Next.x < Previous.x) // 6-9 +
            {
                DrawSnakePart(SnakeParts[SnakePartType::BODY_TURN_DOWN_LEFT], Current);
            }
            else if (Next.y > Previous.y && Next.x > Previous.x) // 12-3 +
            {
                DrawSnakePart(SnakeParts[SnakePartType::BODY_TURN_TOP_LEFT], Current); 
            }
            else if (Next.y > Previous.y && Next.x < Previous.x) //3-6 +
            {
                DrawSnakePart(SnakeParts[SnakePartType::BODY_TURN_DOWN_RIGHT], Current);
            }
          
            
            
            Next = Snake_->getTailPosition()[i];
        
    }
}

void RenderSnake::DrawTail() const
{
    size_t TailLenght = Snake_->getTailPosition().size();
    Vector2 Next;
    if (TailLenght >= 1)
    {
        Next = Snake_->getTailPosition()[TailLenght-2];
    }
    else
    {
        Next = Snake_->getHeadPosition();
    }
    Vector2 TailPos = Snake_->getTailPosition()[TailLenght-1];
    
    if (Next.y <TailPos.y)
    {
        DrawSnakePart(SnakeParts[SnakePartType::TAIL_UP], TailPos);
    }
    else if (Next.y > TailPos.y)
    {
        DrawSnakePart(SnakeParts[SnakePartType::TAIL_DOWN], TailPos);
    }
    else if (Next.x > TailPos.x)
    {
        DrawSnakePart(SnakeParts[SnakePartType::TAIL_RIGHT], TailPos);
    }
    else if (Next.x < TailPos.x)
    {
        DrawSnakePart(SnakeParts[SnakePartType::TAIL_LEFT], TailPos);
    }
}

RenderSnake::~RenderSnake()
{
    UnloadTexture(SnakeBodyTexture_);
}


