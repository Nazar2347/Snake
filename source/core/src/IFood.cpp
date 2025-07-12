#include "IFood.h"

// IFood constructor: initializes food with points, position, and board reference
IFood::IFood(short int Points, Vector2 Position, std::shared_ptr<Board> Board)
    : IObject(Position, Board), Points_(Points)
{
    FoodType_ = EFoodType::NONE;
    // If the initial position is not empty, find an empty cell
    if (Board_.lock()->GetCellInfo(Position_) != ECellType::EMPTY)
    {
        Position_ = Board_.lock()->GetEmptyCell();
    }
    // Mark the cell as containing food
    Board_.lock()->SetCellType(Position_, ECellType::FOOD);
}

// Returns the current position of the food
Vector2 IFood::GetPosition() const noexcept
{
    return Position_;
}

// Returns the points value of the food
short int IFood::GetPoints() const noexcept
{
    return Points_;
}

// Sets the position of the food
void IFood::SetPosition(Vector2 Position) noexcept
{
    Position_ = Position;
}

// Returns the type of the food
EFoodType IFood::GetFoodType() const noexcept
{
    return FoodType_;
}

// IFood destructor: clears the food from the board
IFood::~IFood() = default;

// AppleFood constructor: sets type to APPLE
AppleFood::AppleFood(Vector2 Position, std::shared_ptr<Board> Board) : IFood(GameRules::APPLE_POINTS, Position, Board)
{
    FoodType_ = EFoodType::APPLE;
}

// AppleFood does nothing special when activated
void AppleFood::DoSomething() noexcept
{
    // do nothing
}
void AppleFood::Move() noexcept
{
    // do nothing as it is a stationary item
}

// Frog constructor: sets type to FROG and initializes movement
Frog::Frog(Vector2 Position, std::shared_ptr<Board> Board) : IFood(GameRules::FROG_POINTS, Position, Board)
{
    MoveTimer_ = 0;
    FoodType_ = EFoodType::FROG;
    constexpr int MinStep = -2;
    constexpr int MaxStep = 2;
    NumberGenerator_ = std::make_unique<RandomNumberGenerator>(MinStep, MaxStep);
}

// Frog jumps to a new position when number of MoveTimer is corresponds
void Frog::DoSomething()
{
    if ((MoveTimer_ % GameRules::FROG_MOVE_TIMER) == 0)
    {
        // jump for over 1 cell
        this->Move();
    }
    MoveTimer_++;
}
// Moves the frog to a random empty position within its range
void Frog::Move()
{
    Vector2 NewRandomPos;
    NewRandomPos.x = Position_.x + NumberGenerator_->GetRandomValue();
    NewRandomPos.y = Position_.y + NumberGenerator_->GetRandomValue();
    if (CheckPosition(NewRandomPos) == ECellType::EMPTY)
    {
        Board_.lock()->SetCellType(Position_, ECellType::EMPTY);
        SetPosition(NewRandomPos);
        Board_.lock()->SetCellType(NewRandomPos, ECellType::FOOD);
    }
    else
    {
        return;
    }
}

// Mouse constructor: sets type to MOUSE and initializes movement
Mouse::Mouse(Vector2 Position, std::shared_ptr<Board> Board) : IFood(GameRules::MOUSE_POINTS, Position, Board)
{
    FoodType_ = EFoodType::MOUSE;
    constexpr short MinStep = -1;
    constexpr short MaxStep = 1;
    NumberGenerator_ = std::make_unique<RandomNumberGenerator>(MinStep, MaxStep);
    MoveTimer_ = GameRules::MOUSE_MOVE_TIMER;
}

// Mouse moves to a new position when number of MoveTimer is corresponds
void Mouse::DoSomething()
{
    if ((MoveTimer_ % GameRules::MOUSE_MOVE_TIMER) == 0)
    {
        this->Move();
    }
    MoveTimer_++;
}

// Moves the mouse to a random empty position within its range
void Mouse::Move()
{
    Vector2 NewRandomPos;
    NewRandomPos.x = Position_.x + NumberGenerator_->GetRandomValue();
    NewRandomPos.y = Position_.y + NumberGenerator_->GetRandomValue();
    if (CheckPosition(NewRandomPos) == ECellType::EMPTY)
    {
        Board_.lock()->SetCellType(Position_, ECellType::EMPTY);
        SetPosition(NewRandomPos);
        Board_.lock()->SetCellType(NewRandomPos, ECellType::FOOD);
    }
    else
    {
        return;
    }
}
