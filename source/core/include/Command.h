#pragma once
#include "Snake.h"

/**
 * @brief Abstract base class for all command objects.
 *
 * The Command class defines the interface for executing commands
 * that operate on a Snake actor. Derived classes implement specific
 * actions by overriding the execute() method.
 */
class Command
{
public:
    /**
     * @brief Executes the command on the given Snake actor.
     * @param SnakeActor Reference to the Snake object to operate on.
     */
    virtual void execute(Snake& SnakeActor) = 0;

    /**
     * @brief Virtual destructor for safe polymorphic deletion.
     */
    virtual ~Command();
protected:
};

/**
 * @brief Command to move the Snake up.
 */
class MoveUPCommand : public Command
{
public:
    /**
     * @brief Executes the move up action on the Snake.
     * @param SnakeActor Reference to the Snake object.
     */
    void execute(Snake& SnakeActor) override;
};

/**
 * @brief Command to move the Snake down.
 */
class MoveDownCommand : public Command
{
public:
    /**
     * @brief Executes the move down action on the Snake.
     * @param SnakeActor Reference to the Snake object.
     */
    void execute(Snake& SnakeActor) override;
};

/**
 * @brief Command to move the Snake right.
 */
class MoveRightCommand : public Command
{
public:
    /**
     * @brief Executes the move right action on the Snake.
     * @param SnakeActor Reference to the Snake object.
     */
    void execute(Snake& SnakeActor) override;
};

/**
 * @brief Command to move the Snake left.
 */
class MoveLeftCommand : public Command
{
public:
    /**
     * @brief Executes the move left action on the Snake.
     * @param SnakeActor Reference to the Snake object.
     */
    void execute(Snake& SnakeActor) override;
};

/**
 * @brief Command that performs no action.
 *
 * Used as a default or null object when no input is detected.
 */
class NullCommand : public Command
{
public:
    /**
     * @brief Executes the null action (does nothing).
     * @param SnakeActor Reference to the Snake object.
     */
    void execute(Snake & SnakeActor) override;
};
