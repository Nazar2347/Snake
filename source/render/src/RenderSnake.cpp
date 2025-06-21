#include "RenderSnake.h"


RenderSnake::RenderSnake(Snake& Snake): Snake_(Snake)
{
    
    Image ImageSnake = LoadImage("Assets/Snake-Graphics.png");
    SnakeBodyTexture_ = LoadTextureFromImage(ImageSnake);

    UnloadImage(ImageSnake);

}
void RenderSnake::Draw()const
{

}
void RenderSnake::DrawSnakePart(Rectangle Area, Vector2 Position)
{
    DrawTextureRec(SnakeBodyTexture_, Area, Position, WHITE);
}

RenderSnake::~RenderSnake()
{
    UnloadTexture(SnakeBodyTexture_);
}


