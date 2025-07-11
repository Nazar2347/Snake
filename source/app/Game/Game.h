#pragma once
#include "Board.h"
#include "InputHandler.h"
#include "RenderBoard.h"
#include "RenderFood.h"
#include "RenderSnake.h"
#include <memory>
#include <stack>

/**
 * @enum EGameLevel
 * @brief Represents the available game levels.
 */
enum class EGameLevel
{
    LEVEL1, /**< First level */
    LEVEL2, /**< Second level */
    LEVEL3  /**< Third level */
};

/**
 * @class Game
 * @brief Manages the main game logic, state, and rendering.
 *
 * The Game class encapsulates the core gameplay loop, input handling,
 * rendering, and level management. It owns the board, snake, food, and
 * rendering objects, and controls progression between levels.
 */
class Game
{
  public:
    /**
     * @brief Constructs a Game instance for the specified level.
     * @param Level The game level to initialize.
     */
    Game(EGameLevel Level);

    /**
     * @brief Processes player input and updates the command state.
     */
    void ProcessInput();

    /**
     * @brief Updates the game state, including snake movement and food logic.
     */
    void Update();

    /**
     * @brief Renders the current game state to the screen.
     */
    void Render();

    /**
     * @brief Checks if the game is over.
     * @return True if the game is over, false otherwise.
     */
    bool IsGameOver();

    /**
     * @brief Checks if the current level is completed.
     * @return True if the level is completed, false otherwise.
     */
    bool IsLevelCompleted();

    /**
     * @brief Gets the amount of food left in the current level.
     * @return The number of food items remaining.
     */
    size_t GetAmountFoodLeft();

    /**
     * @brief Destructor. Cleans up resources.
     */
    virtual ~Game();

    /**
     * @brief Stores the amount of food left in the current level.
     */
    size_t FoodLeft;

  protected:
    /**
     * @brief Initializes level 1.
     */
    void InitializeLevel1();

    /**
     * @brief Initializes level 2.
     */
    void InitializeLevel2();

    /**
     * @brief Initializes level 3.
     */
    void InitializeLevel3();

  private:
    std::shared_ptr<Board> Level_;                     /**< Pointer to the game board */
    std::unique_ptr<Snake> PlayerSnake_;               /**< Pointer to the player snake */
    std::unique_ptr<RenderBoard> BoardRender_;         /**< Pointer to the board renderer */
    std::unique_ptr<RenderSnake> SnakeRender_;         /**< Pointer to the snake renderer */
    std::unique_ptr<FoodRender> FoodRender_;           /**< Pointer to the food renderer */
    std::stack<std::unique_ptr<IFood>> LevelFoodStack; /**< Stack of food items for the level */
    InputHandler InputHandler_;                        /**< Handles player input */
    Command *PlayerCommand_;                           /**< Current player command */
    bool bIsLevelCompleted_;                           /**< Indicates if the level is completed */
};