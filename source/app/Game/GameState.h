#pragma once
class Game;

class GameState
{
  public:
    GameState(Game &RefGame);
    virtual void Render() = 0;
    virtual void Update() = 0;
    virtual void ProcessInput() = 0;
    virtual ~GameState();

  protected:
    Game &Game_;
};

class GameState_Menu : public GameState
{
  public:
    GameState_Menu(Game &RefGame);
    void Render() override;
    void Update() override;
    void ProcessInput() override;
};

class GameState_Play : public GameState
{
  public:
    GameState_Play(Game &RefGame);
    void Render() override;
    void Update() override;
    void ProcessInput() override;
};

class GameState_Win : public GameState
{
  public:
    GameState_Win(Game &RefGame);
    void Render() override;
    void Update() override;
    void ProcessInput() override;
};
class GameState_Lose : public GameState
{
  public:
    GameState_Lose(Game &RefGame);
    void Render() override;
    void Update() override;
    void ProcessInput() override;
};
