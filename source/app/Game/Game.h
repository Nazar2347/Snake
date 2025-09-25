#pragma once


#include <vector>
#include <memory>
#include <stack>


class Board;
class Snake;
class IFood;
class GameState;
class GameUI;
class InputHandler;
class Command;
class RenderBoard;
class RenderSnake;
class FoodRender;

/**
 * @enum EGameLevel
 * @brief Represents the available game levels.
 */
enum class EGameLevel
{
    LEVEL1,  /**< First level */
    LEVEL2,  /**< Second level */
    LEVEL3,  /**< Third level */
    GAME_WIN /**< Game Completed*/
};

/**
 * @class Game
 * @brief Manages the main game logic, state, and rendering.
 *
 * The Game class encapsulates the core gameplay loop, input handling,
 * rendering, and level management. It owns the board, UI,  snake, food, and
 * rendering objects, and controls progression between levels.
 */
class Game
{
  public:
    /**
     * @brief Constructs a Game instance for the specified level.
     */
    Game();
    void InitializeLevel();
    /**
     * @brief calls GameState to handle inputlogic
     */
    void ProcessInput();
    /**
     * @brief Processing input for Snake.
     */
    void ProcessInputOnGame();

    /**
     * @brief calls GameState to handle update
     */
    void Update();
    /**
     * @brief Updates the game componetns during game  .
     */
    void UpdateOnPlay();

    /**
     * @brief Renders the current game state to the screen.
     */
    void Render();
    /**
     * @brief Renders the game componets duing Play scene.
     */
    void RenderOnPlay();

    /**
     * @brief Checks if the game is over.
     * @return True if the game is over, false otherwise.
     */
    bool IsGameOver() const;

    /**
     * @brief Checks if the current level is completed.
     * @return True if the level is completed, false otherwise.
     */
    bool IsLevelCompleted() const;

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

    /**
     * @return Return reference on GameUI object.
     */
    GameUI* GetGameUI();

    /**
     * @brief Switches the Game State.
     */
    void SetCurrentState(std::unique_ptr<GameState> State);
    /**
     * @return  true - if EGameLevel == Win.
     */

    bool IsGameWin();

    /**
     * @brief Indicates whether the game should close.
     */
    bool bIsGameShouldClose_;

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
    std::unique_ptr<GameState> CurrentState_;
    GameUI* GameUI_;             /**< UI of the game/ */
    EGameLevel CurrentLevel_;   /**< Indicator of ongoing level */
    InputHandler* InputHandler_; /**< Handles player input */
    Command *PlayerCommand_;    /**< Current player command */
    bool bIsLevelCompleted_;    /**< Indicates if the level is completed */
};