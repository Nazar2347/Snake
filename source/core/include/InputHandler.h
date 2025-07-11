#pragma once
#include "Command.h"
#include <memory>
#include <raylib.h>

/**
 * @brief Handles user input and maps it to command objects.
 *
 * The InputHandler class is responsible for processing user input (such as keyboard events)
 * and returning the appropriate Command object based on the input. It uses the Command pattern
 * to decouple input handling from game logic.
 */
class InputHandler
{
  public:
    /**
     * @brief Constructs an InputHandler and initializes command mappings.
     */
    InputHandler();

    /**
     * @brief Processes current input and returns the corresponding command.
     *
     * Checks for user input (e.g., key presses) and returns a pointer to the
     * appropriate Command object. If no relevant input is detected, returns a NullCommand.
     *
     * @return Command* Pointer to the command corresponding to the current input.
     */
    Command *HandleInput();

    /**
     * @brief Destructor for InputHandler.
     */
    virtual ~InputHandler();

  private:
    std::unique_ptr<Command> ButtonW_;     ///< Command for the 'W' key (move up).
    std::unique_ptr<Command> ButtonD_;     ///< Command for the 'D' key (move right).
    std::unique_ptr<Command> ButtonA_;     ///< Command for the 'A' key (move left).
    std::unique_ptr<Command> ButtonS_;     ///< Command for the 'S' key (move down).
    std::unique_ptr<Command> NullCommand_; ///< Command for no input or unhandled input.
};
