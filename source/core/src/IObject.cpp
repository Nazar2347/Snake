#include "IObject.h"

IObject::IObject(Vector2 Position, std::shared_ptr<Board> Board) : Board_(Board), Position_(Position)
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