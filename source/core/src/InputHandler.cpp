#include "InputHandler.h"

// Constructor: Initializes command objects for each input direction and a null command.
InputHandler::InputHandler()
{
    ButtonW_ = std::make_unique<MoveUPCommand>();    // 'W' or 'Up Arrow' key: Move up
    ButtonD_ = std::make_unique<MoveRightCommand>(); // 'D' or 'Right Arrow' key: Move right
    ButtonA_ = std::make_unique<MoveLeftCommand>();  // 'A' or 'Left Arrow' key: Move left
    ButtonS_ = std::make_unique<MoveDownCommand>();  // 'S' or 'Down Arrow' key: Move down
    NullCommand_ = std::make_unique<NullCommand>();  // No input: Do nothing
}

// Checks for key presses and returns the corresponding command object.
Command *InputHandler::HandleInput()
{
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
    {
        return ButtonW_.get(); // Move up
    }
    else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
    {
        return ButtonD_.get(); // Move right
    }
    else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
    {
        return ButtonA_.get(); // Move left
    }
    else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
    {
        return ButtonS_.get(); // Move down
    }
    else
    {
        return NullCommand_.get(); // No relevant key pressed
    }
}

// Destructor: Cleans up allocated command objects.
InputHandler::~InputHandler()
{
}
