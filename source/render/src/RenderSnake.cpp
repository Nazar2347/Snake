#include "RenderSnake.h"

// Constructor: Initializes the RenderSnake with a pointer to a Snake object.
// Loads the snake body texture from an image file if the Snake pointer is valid.
RenderSnake::RenderSnake(const Snake *Snake) : Snake_(Snake)
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

// Draws the entire snake (head, body, tail) if the Snake pointer is valid.
// Otherwise, displays an error message on the board.
void RenderSnake::Draw() const
{
    if (Snake_ != nullptr)
    {
        DrawHead();
        DrawBody();
        DrawTail();
    }
    else
    {
        DrawText("NO INITIALIZED SNAKE", 
                    static_cast<int>(UI::BOARD_INITIAL_X_POS),
                    static_cast<int>(UI::BOARD_INITIAL_Y_POS), 
                    14, RED);
    }
}

// Draws a single part of the snake (head, body, or tail) at the specified board position.
void RenderSnake::DrawSnakePart(Rectangle SnakePart, Vector2 Position) const
{
    DrawTextureRec(SnakeBodyTexture_, SnakePart,
                   {(Position.x * UI::CELL_SIZE) + UI::BOARD_INITIAL_X_POS,
                    (Position.y * UI::CELL_SIZE) + UI::BOARD_INITIAL_Y_POS},
                   WHITE);
}

// Draws the snake's head using the correct texture based on the current direction.
void RenderSnake::DrawHead() const
{
    // Render Snake Head in the correct direction
    if (Snake_->GetHeadDirection() == EDirection::UP)
    {
        DrawSnakePart(SnakeParts[SnakePartType::HEAD_UP], Snake_->GetHeadPosition());
    }
    else if (Snake_->GetHeadDirection() == EDirection::DOWN)
    {
        DrawSnakePart(SnakeParts[SnakePartType::HEAD_DOWN], Snake_->GetHeadPosition());
    }
    else if (Snake_->GetHeadDirection() == EDirection::RIGHT)
    {
        DrawSnakePart(SnakeParts[SnakePartType::HEAD_RIGHT], Snake_->GetHeadPosition());
    }
    else if (Snake_->GetHeadDirection() == EDirection::LEFT)
    {
        DrawSnakePart(SnakeParts[SnakePartType::HEAD_LEFT], Snake_->GetHeadPosition());
    }
}

// Draws the snake's body segments, choosing the correct texture for straight or turning segments.
void RenderSnake::DrawBody() const
{
    Vector2 Next = Snake_->GetHeadPosition();

    // Iterate through all tail segments except the last one
    for (int i = 0; i < Snake_->GetTailPosition().size() - 1; i++)
    {
        Vector2 Current = Snake_->GetTailPosition()[i];
        Vector2 Previous = Snake_->GetTailPosition()[i + 1];

        // Draw straight vertical body part
        if (Next.x == Previous.x)
        {
            DrawSnakePart(SnakeParts[SnakePartType::BODY_VERTICAL], Current);
        }
        // Draw straight horizontal body part
        else if (Next.y == Previous.y)
        {
            DrawSnakePart(SnakeParts[SnakePartType::BODY_HORIZONTAL], Current);
        }
        // Draw body turns (various corner cases)
        else if ((Current.y == Next.y && Current.y > Previous.y) && (Current.x < Next.x && Current.x == Previous.x) ||
                 (Current.y > Next.y && Current.y == Previous.y) && (Current.x == Next.x && Current.x < Previous.x))
        {
            DrawSnakePart(SnakeParts[SnakePartType::BODY_TURN_DOWN_LEFT], Current);
        }
        else if (((Current.y > Next.y && Current.y == Previous.y) && (Current.x == Next.x && Current.x > Previous.x)) ||
                 ((Current.y == Next.y && Current.y > Previous.y) && (Current.x > Next.x && Current.x == Previous.x)))
        {
            DrawSnakePart(SnakeParts[SnakePartType::BODY_TURN_DOWN_RIGHT], Current);
        }
        else if (((Current.y == Next.y && Current.y < Previous.y) && (Current.x > Next.x && Current.x == Previous.x)) ||
                 ((Current.y < Next.y && Current.y == Previous.y) && (Current.x == Next.x && Current.x > Previous.x)))
        {
            DrawSnakePart(SnakeParts[SnakePartType::BODY_TURN_TOP_LEFT], Current);
        }
        else if (((Current.y < Next.y && Current.y == Previous.y) && (Current.x == Next.x && Current.x < Previous.x)) ||
                 ((Current.y == Next.y && Current.y < Previous.y) && (Current.x < Next.x && Current.x == Previous.x)))
        {
            DrawSnakePart(SnakeParts[SnakePartType::BODY_TURN_TOP_RIGHT], Current);
        }

        // Move to the next segment for the next iteration
        Next = Snake_->GetTailPosition()[i];
    }
}

// Draws the snake's tail using the correct texture based on the direction of the last segment.
void RenderSnake::DrawTail() const
{
    size_t TailLenght = Snake_->GetTailPosition().size();
    Vector2 Next;
    if (TailLenght >= 1)
    {
        Next = Snake_->GetTailPosition()[TailLenght - 2];
    }
    else
    {
        Next = Snake_->GetHeadPosition();
    }
    Vector2 TailPos = Snake_->GetTailPosition()[TailLenght - 1];

    // Determine the direction of the tail and draw the correct tail part
    if (Next.y < TailPos.y)
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

// Destructor: Unloads the snake body texture from GPU memory.
RenderSnake::~RenderSnake()
{
    UnloadTexture(SnakeBodyTexture_);
}
