#include "InputHandler.h"

// Constructor: Initializes command objects for each input direction and a null command.
InputHandler::InputHandler()
{
    ButtonW_ = new MoveUPCommand();      // 'W' or 'Up Arrow' key: Move up
    ButtonD_ = new MoveRightCommand();   // 'D' or 'Right Arrow' key: Move right
    ButtonA_ = new MoveLeftCommand();    // 'A' or 'Left Arrow' key: Move left
    ButtonS_ = new MoveDownCommand();    // 'S' or 'Down Arrow' key: Move down
    NullCommand_ = new NullCommand();    // No input: Do nothing
}

// Checks for key presses and returns the corresponding command object.
Command* InputHandler::HandleInput()
{
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
    {
        return ButtonW_; // Move up
    }
    else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
    {
        return ButtonD_; // Move right
    }
    else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
    {
        return ButtonA_; // Move left
    }
    else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
    {
        return ButtonS_; // Move down
    }
    else
    {
        return NullCommand_; // No relevant key pressed
    }
}

// Destructor: Cleans up allocated command objects.
InputHandler::~InputHandler()
{
    delete ButtonW_;
    delete ButtonD_;
    delete ButtonA_;
    delete ButtonS_;
    delete NullCommand_;
}

