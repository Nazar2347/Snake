#include "RenderBoard.h"
#include "GameConstants.h"
#include <iostream>

// Constructor: Loads images and creates textures for the board
RenderBoard::RenderBoard(const Board &Board) : LevelBoard_(Board)
{
    Image TopBorder = LoadImage("Assets/BorderTop.png");
    Image Ground1 = LoadImage("Assets/Ground1.png");
    Image Ground2 = LoadImage("Assets/Ground2.png");
    if (TopBorder.data == nullptr || Ground1.data == nullptr || Ground2.data == nullptr)
    {
        std::cout << "Failed to load image \n";
    }

    BorderTopTexture_ = LoadTextureFromImage(TopBorder);
    GroundTexture1_ = LoadTextureFromImage(Ground1);
    GroundTexture2_ = LoadTextureFromImage(Ground2);
    if (BorderTopTexture_.id == 0 || GroundTexture1_.id == 0 || GroundTexture2_.id == 0)
    {
        std::cout << "Failed to load texture for BorderTop.png \n";
    }
    UnloadImage(TopBorder);
    UnloadImage(Ground1);
    UnloadImage(Ground2);
}

// Draws the board and its cells
void RenderBoard::Draw() const
{
    DrawBackground();
    if (BorderTopTexture_.id != NULL && GroundTexture1_.id != 0 && GroundTexture2_.id != 0)
    {
        for (int i = 0; i < LevelBoard_.GetLevelXSize(); i++)
        {
            for (int j = 0; j < LevelBoard_.GetLevelYSize(); j++)
            {
                Vector2 CurrentCell = {(float)i, float(j)};
                if (LevelBoard_.GetCellInfo(CurrentCell) == ECellType::WALL)
                {
                    // Draw border texture for active cell
                    DrawTextureEx(BorderTopTexture_,
                                  {(CurrentCell.x * UI::CELL_SIZE) + UI::BOARD_INITIAL_X_POS,
                                   (CurrentCell.y * UI::CELL_SIZE) + UI::BOARD_INITIAL_Y_POS},
                                  0.0F, UI::BLOCKS_SCALE, WHITE);
                }
                else
                {
                    // Alternate ground textures for inactive cells
                    if ((i + j) % 2 == 0)
                    {
                        DrawTextureEx(GroundTexture1_,
                                      {(CurrentCell.x * UI::CELL_SIZE) + UI::BOARD_INITIAL_X_POS,
                                       (CurrentCell.y * UI::CELL_SIZE) + UI::BOARD_INITIAL_Y_POS},
                                      0.0F, UI::BLOCKS_SCALE, WHITE);
                    }
                    else
                    {
                        DrawTextureEx(GroundTexture2_,
                                      {(CurrentCell.x * UI::CELL_SIZE) + UI::BOARD_INITIAL_X_POS,
                                       (CurrentCell.y * UI::CELL_SIZE) + UI::BOARD_INITIAL_Y_POS},
                                      0.0F, UI::BLOCKS_SCALE, WHITE);
                    }
                }
            }
        }
    }
    else
    {
        std::cout << "Texture not valid, cannot draw\n";
    }
}

// Destructor: Unloads textures
RenderBoard::~RenderBoard()
{
    UnloadTexture(BorderTopTexture_);
    UnloadTexture(GroundTexture1_);
    UnloadTexture(GroundTexture2_);
}

// Draws the background rectangle for the board
void RenderBoard::DrawBackground() const
{
    Rectangle Backgoround;
    Backgoround.x = UI::BOARD_INITIAL_X_POS;
    Backgoround.y = UI::BOARD_INITIAL_Y_POS;
    Backgoround.height = static_cast<float>(LevelBoard_.GetLevelYSize());
    Backgoround.width = static_cast<float>(LevelBoard_.GetLevelXSize());

    DrawRectangle(static_cast<int>(Backgoround.x), static_cast<int>(Backgoround.y),
                  static_cast<int>(Backgoround.width * UI::CELL_SIZE),
                  static_cast<int>(Backgoround.height * UI::CELL_SIZE), LIME);
}
