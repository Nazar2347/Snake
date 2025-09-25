#pragma once
class Button;
#include "GameConstants.h"

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
     * @brief Destroys the GameUI object and releases resources.
     */
    ~GameUI();

    /**
     * @brief Draws background for the game
     */
    void DrawBackgorund();
    /**
     * @brief Sets a GameScore for score bar
     */
    void StartCountingGameScore(size_t &GameScore);

    bool IsStartButtonClicked();
    bool IsRestartButtonClicked();
    bool IsExitButtonClicked();

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
     * @param Score_ - for displaying score
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
    Texture2D ScoreBar_;

    /**
     * @brief Pointer to the start button UI element.
     */
    Button *StartButton_;

    /**
     * @brief Pointer to the exit button UI element.
     */
    Button *ExitButton_;

    /**
     * @brief Pointer to the restart button UI element.
     */
    Button *RestartButton_;
    /**
     * @brief Pointer to Game score
     */
    size_t *Score_;
    size_t StartScore_;
};
