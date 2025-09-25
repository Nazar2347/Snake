#include "Snake.h"
#include <raylib.h>

// Constructor: Initializes the snake's head position, alive state, direction, and starting tail
Snake::Snake(Vector2 StartingPos, std::shared_ptr<Board> Board)
    : IObject(StartingPos, Board), Direction_(EDirection::LEFT), bIsAlive_(true), HeadDirection_(EDirection::LEFT)
{
    // Add initial tail segment to the right of the head
    const Vector2 TailPos = {StartingPos.x + 1, StartingPos.y};
    TailPosition_.push_back(TailPos);
}

// Returns a copy of the current tail positions.
std::vector<Vector2> Snake::GetTailPosition() const
{
    return TailPosition_;
}

void Snake::SetHeadPosition(const Vector2 Position) noexcept
{
    Position_ = Position;
}

// Changes the size of the snake's tail by the given amount (positive to grow, negative to shrink)
void Snake::ChangeTailSizeBy(int Size)
{
    if (Size < 0)
    {
        // Shrink the tail
        for (; Size < 0; Size++)
        {
            if (!TailPosition_.empty())
            {
                Board_.lock()->SetCellType(TailPosition_.back(), ECellType::EMPTY);
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
            if (!TailPosition_.empty() && TailPosition_.size() < GameRules::MAX_SNAKE_LENGHT)
            {

                const Vector2 LastTailSegment = TailPosition_.back();
                Vector2 NewTailSegment = {LastTailSegment.x + 1,
                                          LastTailSegment.y}; // default case to pushing to the right
                if (TailPosition_.size() > 2)
                {
                    const Vector2 PreLastTailSegment = *(TailPosition_.end() - 2);

                    if (PreLastTailSegment.y < LastTailSegment.y) // Push below of the tail
                    {
                        NewTailSegment = {LastTailSegment.x, LastTailSegment.y + 1};
                    }
                    else if (PreLastTailSegment.y > LastTailSegment.y)
                    {
                        NewTailSegment = {LastTailSegment.x, LastTailSegment.y - 1}; // push above of the tail
                    }
                    else if (PreLastTailSegment.x > LastTailSegment.x)
                    {
                        NewTailSegment = {LastTailSegment.x - 1, LastTailSegment.y}; // push to the left
                    }
                }

                TailPosition_.push_back(NewTailSegment);
#ifdef DEBUG
                printf("TailPosition increased\n");
#endif // DEBUG
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
    case EDirection::UP:
        NextCell = Vector2Add(this->GetHeadPosition(), {0, -1});
        break;
    case EDirection::DOWN:
        NextCell = Vector2Add(this->GetHeadPosition(), {0, 1});
        break;
    case EDirection::LEFT:
        NextCell = Vector2Add(this->GetHeadPosition(), {-1, 0});
        break;
    case EDirection::RIGHT:
        NextCell = Vector2Add(this->GetHeadPosition(), {1, 0});
        break;
    default:
        return;
    }

    // Prevent immediate reversal into the first tail segment
    const bool isGoingBackwards = static_cast<bool>(Vector2Equals(NextCell, TailPosition_.at(0)));
    if (isGoingBackwards)
    {
        // Reverse direction if about to collide with first tail segment
        switch (Direction_)
        {
        case EDirection::UP:
            Direction_ = EDirection::DOWN;
            break;
        case EDirection::DOWN:
            Direction_ = EDirection::UP;
            break;
        case EDirection::LEFT:
            Direction_ = EDirection::RIGHT;
            break;
        case EDirection::RIGHT:
            Direction_ = EDirection::LEFT;
            break;
        }

        // Recalculate next cell after direction change
        switch (Direction_)
        {
        case EDirection::UP:
            NextCell = Vector2Add(GetHeadPosition(), {0, -1});
            break;
        case EDirection::DOWN:
            NextCell = Vector2Add(GetHeadPosition(), {0, 1});
            break;
        case EDirection::LEFT:
            NextCell = Vector2Add(GetHeadPosition(), {-1, 0});
            break;
        case EDirection::RIGHT:
            NextCell = Vector2Add(GetHeadPosition(), {1, 0});
            break;
        default:
            return;
        }
    }
    // Check for collision with wall, border, or itself

    // Move head to next cell and update board
    Vector2 OldBodyPos = GetHeadPosition();
    SetHeadPosition(NextCell);
    HeadDirection_ = Direction_;

    // Move each tail segment to the position of the previous segment
    for (int i = 0; i < TailPosition_.size(); i++)
    {
        Board_.lock()->SetCellType(TailPosition_.at(i), ECellType::SNAKE);
        const Vector2 OldBodyPos2 = TailPosition_.at(i);
        TailPosition_.at(i) = OldBodyPos;
        OldBodyPos = OldBodyPos2;
        // Clear the last cell previously occupied by the tail
        if (i == TailPosition_.size() - 1)
        {
            Board_.lock()->SetCellType(OldBodyPos, ECellType::EMPTY);
        }
        // Check for collision with wall, border, or itself
    }
    if (CheckPosition(GetHeadPosition()) == ECellType::WALL ||
        CheckPosition(GetHeadPosition()) == ECellType::OUT_OF_BORDER ||
        CheckPosition(GetHeadPosition()) == ECellType::SNAKE)
    {
        bIsAlive_ = false;
#ifdef DEBUG
        printf("Snake died\n");
#endif // DEBUG

        return;
    }
    Board_.lock()->SetCellType(GetHeadPosition(), ECellType::SNAKE);
}

// Sets the direction of the snake's movement
void Snake::SetDirection(EDirection Direction)
{
    Direction_ = Direction;
}
