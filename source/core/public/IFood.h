#pragma once
#include "IObject.h"


#include <memory>
/**
 * @brief Enumerates the different types of food available in the game.
 */
enum class EFoodType
{
    APPLE, /**< Apple food type. */
    FROG,  /**< Frog food type. */
    MOUSE, /**< Mouse food type. */
    NONE   /**< No food. */
};

/**
 * @brief Abstract base class representing food items on the board.
 */
class IFood : public IObject
{
  public:
    /**
     * @brief Constructs a food item with the given points, position, and board reference.
     * @param Points The score value of the food.
     * @param Position The position of the food on the board.
     * @param Board Reference to the game board.
     */
    IFood(short int Points, Vector2 Position, std::shared_ptr<Board> Board);

    /**
     * @brief Gets the current position of the food.
     * @return The position of the food.
     */
    virtual Vector2 GetPosition() const noexcept;

    /**
     * @brief Gets the score value of the food.
     * @return The points awarded for this food.
     */
    virtual short int GetPoints() const noexcept;

    /**
     * @brief Sets the position of the food.
     * @param Position The new position for the food.
     */
    virtual void SetPosition(Vector2 Position) noexcept;

    /**
     * @brief Performs the food's special action (to be implemented by derived classes).
     */
    virtual void DoSomething() = 0;

    /**
     * @brief Gets the type of the food.
     * @return The food type.
     */
    EFoodType GetFoodType() const noexcept;

    /**
     * @brief Virtual destructor for IFood.
     */
    virtual ~IFood();

  protected:
    short int Points_;   ///< The score value of the food.
    EFoodType FoodType_; ///< The type of the food.
};

/**
 * @brief Represents an apple food item.
 */
class AppleFood : public IFood
{
  public:
    /**
     * @brief Constructs an AppleFood object.
     * @param Points The score value of the apple.
     * @param Position The position of the apple on the board.
     * @param Board Reference to the game board.
     */
    AppleFood(Vector2 Position, std::shared_ptr<Board> Board);

    /**
     * @brief Performs the apple's special action.
     */
    void DoSomething() noexcept override;
    void Move() noexcept override;
};

/**
 * @brief Represents a frog food item that can move.
 */
class Frog : public IFood
{
  public:
    /**
     * @brief Constructs a Frog object.
     * @param Points The score value of the frog.
     * @param Position The position of the frog on the board.
     * @param Board Reference to the game board.
     */
    Frog(Vector2 Position, std::shared_ptr<Board> Board);

    /**
     * @brief Performs the frog's special action.
     */
    void DoSomething() override;

  protected:
    /**
     * @brief Moves the frog on the board.
     */
    void Move() override;

  private:
    unsigned short MoveTimer_; ///< Move timer per frame
};

/**
 * @brief Represents a mouse food item that can move.
 */
class Mouse : public IFood
{
  public:
    /**
     * @brief Constructs a Mouse object.
     * @param Points The score value of the mouse.
     * @param Position The position of the mouse on the board.
     * @param Board Reference to the game board.
     */
    Mouse(Vector2 Position, std::shared_ptr<Board> Board);

    /**
     * @brief Performs the mouse's special action.
     */
    void DoSomething() override;

  protected:
    /**
     * @brief Moves the mouse on the board.
     */
    void Move() override;

  private:
    /**
     * @.
     */
    unsigned short MoveTimer_; ///< Move timer per frame
};
