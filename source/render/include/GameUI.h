#pragma once
#include <raylib.h>
#include "GameConstants.h"
#include "Button.h"
#include <string>



/**
 * @brief Enumerates the possible game states.
 */
enum class EGameStates
{
    MENU,      ///< Main menu state
    GAME,      ///< Gameplay state
    GAME_OVER, ///< Game over state
    WIN        ///< Win state
};

/**
 * @brief Handles the user interface for the game, including menus and state transitions.
 */
class GameUI
{
public:
    /**
     * @brief Constructs the GameUI object and initializes UI elements.
     */
    GameUI();

    /**
     * @brief Updates the UI logic, including button states and game state transitions.
     */
    void Update();

    /**
     * @brief Draws the current UI elements based on the game state.
     */
    void Draw();

    /**
     * @brief Sets the current game state.
     * @param NewGameState The new state to set.
     */
    void SetGameState(EGameStates NewGameState);

    /**
     * @brief Gets the current game state.
     * @return The current EGameStates value.
     */
    EGameStates GetGameState();

    /**
     * @brief Destroys the GameUI object and releases resources.
     */
    ~GameUI();

    /**
     * @brief Indicates whether the game is currently paused.
     */
    bool bIsPaused_;

    /**
     * @brief Indicates whether the game should close.
     */
    bool bIsGameShouldClose;
    /**
     * @brief Draws background for the game
     */
    void DrawBackgorund();
    void SetGameScore(size_t & GameScore);
protected:
    /**
     * @brief Draws the main menu UI.
     */
    void DrawMenu();

    /**
     * @brief Draws the win label UI.
     */
    void DrawWinLabel();

    /**
     * @brief Draws the gameover label UI.
     */
    void DrawGameOverLabel();

    /**
     * @brief Draws inner game UI
     * @param Score - for displaying score
     */
    void DrawGameUI();


private:
    /**
     * @brief The background texture for the UI.
     */
    Texture2D Background_;
    Texture2D MenuPanel_;
    Texture2D GameOverLablel_;
    Texture2D YouWonLabel_;
    

    /**
     * @brief The current state of the game.
     */
    EGameStates CurrentState_;

    /**
     * @brief Pointer to the start button UI element.
     */
    Button* StartButton_;

    /**
     * @brief Pointer to the exit button UI element.
     */
    Button* ExitButton_;

    /**
     * @brief Pointer to the restart button UI element.
     */
    Button* RestartButton_;
    size_t* CurrentScore;
};
