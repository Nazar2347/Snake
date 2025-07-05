    #include "Snake.h"

// Constructor: Initializes the snake's head position, alive state, direction, and starting tail
Snake::Snake(Vector2 StartingPos, Board &Board) : 
    HeadPosition_(StartingPos),
    bIsAlive_(true),
    HeadDirection_(EDirection::LEFT),
    Direction_ (EDirection::LEFT),
    IMove(Board)
{
    // Add initial tail segment to the right of the head
    TailPosition_.push_back({ StartingPos.x + 1, StartingPos.y });
}

// Returns a copy of the current tail positions.
std::vector<Vector2> Snake::getTailPosition() const
{
    return TailPosition_;
}

// Returns the current head position.
Vector2 Snake::getHeadPosition() const
{
    return HeadPosition_;
}

// Changes the size of the snake's tail by the given amount (positive to grow, negative to shrink)
void Snake::ChangeTailSizeBy(int Size)
{
    if (Size < 0)
    {
        // Shrink the tail
        for (; Size < 0; Size++)
        {
            if (TailPosition_.size() >= 1)
            {
                Board_->SetCellType(TailPosition_.back(), ECellType::EMPTY);
                TailPosition_.pop_back();
                if (TailPosition_.size() <= 1)
                {
                    bIsAlive_ = false; // Snake dies if tail less than 2
                }
            }
            else
            {
                bIsAlive_ = false; // Snake dies if tail less than 2
            }
        }
    }
    else
    {
        // Grow the tail
        for (int i = 0; i < Size; i++)
        {
            if (TailPosition_.size() >= 1 && TailPosition_.size() < 100)
            {
                Vector2 LastElementOfTail = TailPosition_.back();
                TailPosition_.push_back({ LastElementOfTail.x + 1, LastElementOfTail.y });
                printf("TailPosition increased\n");
            }
        }
    }
}

// Moves the snake in the current direction, updates board and tail positions
void Snake::Move()
{
    Vector2 NextCell;

    // Step 1: Compute next cell based on current direction
    switch (Direction_)
    {
    case EDirection::UP:    NextCell = Vector2Add(HeadPosition_, { 0, -1 }); break;
    case EDirection::DOWN:  NextCell = Vector2Add(HeadPosition_, { 0, 1 });  break;
    case EDirection::LEFT:  NextCell = Vector2Add(HeadPosition_, { -1, 0 }); break;
    case EDirection::RIGHT: NextCell = Vector2Add(HeadPosition_, { 1, 0 });  break;
    default: return;
    }

  
    // Prevent immediate reversal into the first tail segment
    if (Vector2Equals(NextCell, TailPosition_[0]))
    {
        // Reverse direction if about to collide with first tail segment
        switch (Direction_)
        {
        case EDirection::UP:    Direction_ = EDirection::DOWN;  break;
        case EDirection::DOWN:  Direction_ = EDirection::UP;  break;
        case EDirection::LEFT:  Direction_ = EDirection::RIGHT;  break;
        case EDirection::RIGHT: Direction_ = EDirection::LEFT;  break;
        }

        // Recalculate next cell after direction change
        switch (Direction_)
        {
        case EDirection::UP:    NextCell = Vector2Add(HeadPosition_, { 0, -1 }); break;
        case EDirection::DOWN:  NextCell = Vector2Add(HeadPosition_, { 0, 1 });  break;
        case EDirection::LEFT:  NextCell = Vector2Add(HeadPosition_, { -1, 0 }); break;
        case EDirection::RIGHT: NextCell = Vector2Add(HeadPosition_, { 1, 0 });  break;
        default: return;
        }
    }
    // Check for collision with wall, border, or itself

    // Move head to next cell and update board
    Vector2 OldBodyPos = HeadPosition_;
    HeadPosition_ = NextCell;
    HeadDirection_ = Direction_;
    // Move each tail segment to the position of the previous segment
    for (int i = 0; i < TailPosition_.size(); i++)
    {
        Board_->SetCellType(TailPosition_[i], ECellType::SNAKE);
        Vector2 OldBodyPos2 = TailPosition_[i];
        TailPosition_[i] = OldBodyPos;
        OldBodyPos = OldBodyPos2;
        // Clear the last cell previously occupied by the tail
        if (i == TailPosition_.size() - 1)
        {
            Board_->SetCellType(OldBodyPos, ECellType::EMPTY);
        }
    }
    // Check for collision with wall, border, or itself
    if (CheckPosition(HeadPosition_) == ECellType::WALL 
        ||CheckPosition(HeadPosition_)==ECellType::OUT_OF_BORDER
        ||CheckPosition(HeadPosition_)==ECellType::SNAKE)
    {
        bIsAlive_ = false; 
        printf("Snake died\n");
        return;
    }
    Board_->SetCellType(HeadPosition_, ECellType::SNAKE);
}

// Sets the direction of the snake's movement
void Snake::SetDirection(EDirection Direction)
{
    Direction_ = Direction;
}

// Returns the current direction of the snake's head
EDirection Snake::GetHeadDirection()
{
    return HeadDirection_;
}
EDirection Snake::GetDirection()
{
    return Direction_;
}

// Returns whether the snake is alive
bool Snake::isAlive()
{
    return bIsAlive_;
}

// Destructor
Snake::~Snake()
{

}

