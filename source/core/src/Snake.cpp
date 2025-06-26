#include "Snake.h"

// Constructor: Initializes the snake's head position, alive status, and starting direction.
// Also adds the initial tail segment to the right of the head.
Snake::Snake(Vector2 StartingPos, Board &Board) : 
    HeadPosition_(StartingPos),
    bIsAlive_(true),
    HeadDirection_(EDirection::UP),
    IMove(Board)
{
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

// Extends the tail by the specified number of segments, up to a maximum of 100 segments.
// New segments are added in a straight line from the last tail segment.
void Snake::ExtendTailBy(size_t Size)
{
    for (int i = 0; i < Size; i++)
    {
        // Only extend if there is at least one tail segment and less than 100 segments.
        if (TailPosition_.size() >= 1 && TailPosition_.size() < 100)
        {
            Vector2 LastElementOfTail = TailPosition_.back();
            TailPosition_.push_back({ LastElementOfTail.x + 1, LastElementOfTail.y });
            printf("TailPosition increased\n");
        }
    }
}

// Shortens the tail by the specified number of segments.
// If the tail becomes empty, the snake is marked as dead.
void Snake::ShortTailBy(size_t Size)
{
    for (int i = 0; i < Size; i++)
    {
        if (TailPosition_.size() < 1)
        {
            bIsAlive_ = false;
        }
        else
        {
            TailPosition_.pop_back();
        }
    }
}

// Moves the snake forward by one cell in the current direction.
// Prevents reversing into the snake's own body by rejecting moves that would do so.
void Snake::Move()
{
    Vector2 NextCell;

    // Step 1: Compute next cell based on current direction
    switch (HeadDirection_)
    {
    case EDirection::UP:    NextCell = Vector2Add(HeadPosition_, { 0, -1 }); break;
    case EDirection::DOWN:  NextCell = Vector2Add(HeadPosition_, { 0, 1 });  break;
    case EDirection::LEFT:  NextCell = Vector2Add(HeadPosition_, { -1, 0 }); break;
    case EDirection::RIGHT: NextCell = Vector2Add(HeadPosition_, { 1, 0 });  break;
    default: return;
    }
    if (CheckPosition(NextCell) == 1)
    {
        return;
    }
    // Step 2: If reversing into own body, reject the move by computing old direction instead
    if (TailPosition_.size() > 0 && Vector2Equals(NextCell, TailPosition_[0]))
    {
        // Reverse the direction to prevent moving into the body
        switch (HeadDirection_)
        {
        case EDirection::UP:    HeadDirection_ = EDirection::DOWN; break;
        case EDirection::DOWN:  HeadDirection_ = EDirection::UP; break;
        case EDirection::LEFT:  HeadDirection_ = EDirection::RIGHT; break;
        case EDirection::RIGHT: HeadDirection_ = EDirection::LEFT; break;
        }

        // Recompute valid direction cell (with restored HeadDirection_)
        switch (HeadDirection_)
        {
        case EDirection::UP:    NextCell = Vector2Add(HeadPosition_, { 0, -1 }); break;
        case EDirection::DOWN:  NextCell = Vector2Add(HeadPosition_, { 0, 1 });  break;
        case EDirection::LEFT:  NextCell = Vector2Add(HeadPosition_, { -1, 0 }); break;
        case EDirection::RIGHT: NextCell = Vector2Add(HeadPosition_, { 1, 0 });  break;
        default: return;
        }
    }

    // Step 3: Move the head to the next cell
    Vector2 OldBodyPos = HeadPosition_;
    HeadPosition_ = NextCell;

    // Step 4: Move the tail segments to follow the head
    for (int i = 0; i < TailPosition_.size(); i++)
    {
        Vector2 OldBodyPos2 = TailPosition_[i];
        TailPosition_[i] = OldBodyPos;
        OldBodyPos = OldBodyPos2;
    }
}

// Sets the snake's movement direction.
void Snake::SetDirection(EDirection Direction)
{
    HeadDirection_ = Direction;
}

// Returns the current movement direction.
EDirection Snake::GetDirection()
{
    return HeadDirection_;
}

// Returns whether the snake is alive.
bool Snake::isAlive()
{
    return bIsAlive_;
}

// Destructor: No dynamic memory to clean up.
Snake::~Snake()
{

}

