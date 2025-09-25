#include "IObject.h"


IObject::IObject(Vector2 Position, std::shared_ptr<Board> Board) noexcept : Board_(Board), Position_(Position)
{
    NumberGenerator_ = nullptr;
}

ECellType IObject::CheckPosition(Vector2 Position)
{
    return Board_.lock()->GetCellInfo(Position);
}
IObject::~IObject()
{
    if (!Board_.expired())
    {
        Board_.lock()->SetCellType(Position_, ECellType::EMPTY);
    }
}

IObject::IObject(IObject &&Object) noexcept
    : NumberGenerator_(std::move(Object.NumberGenerator_)), Board_(std::move(Object.Board_)),
      Position_(Object.Position_)
{
}
