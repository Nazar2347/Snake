#include "RenderFood.h"

// Constructor: Loads images and creates textures for each food type
FoodRender::FoodRender()
{
    Image AppleImage = LoadImage("Assets/Apple.png");
    Image FrogImage = LoadImage("Assets/Frog.png");
    Image MouseImage = LoadImage("Assets/Mouse.png");
    AppleTexture_ = LoadTextureFromImage(AppleImage);
    FrogTexture_ = LoadTextureFromImage(FrogImage);
    MouseTexture_ = LoadTextureFromImage(MouseImage);

    UnloadImage(AppleImage);
    UnloadImage(FrogImage);
    // MouseImage is not unloaded here, possibly intentional or a bug
}

// Draws the given food object using the appropriate texture or a red rectangle if type is unknown
void FoodRender::Draw(const IFood &Object)
{
    if (Object.GetFoodType() == EFoodType::APPLE)
    {
        // Draw apple texture at the food's position
        DrawTextureEx(AppleTexture_,
                      {(Object.GetPosition().x * UI::CELL_SIZE) + UI::BOARD_INITIAL_X_POS,
                       (Object.GetPosition().y * UI::CELL_SIZE) + UI::BOARD_INITIAL_Y_POS},
                      0.0F, UI::OBJECTS_SCALE, WHITE);
    }
    else if (Object.GetFoodType() == EFoodType::FROG)
    {
        // Draw frog texture at the food's position
        DrawTextureEx(FrogTexture_,
                      {(Object.GetPosition().x * UI::CELL_SIZE) + UI::BOARD_INITIAL_X_POS,
                       (Object.GetPosition().y * UI::CELL_SIZE) + UI::BOARD_INITIAL_Y_POS},
                      0.0F, UI::OBJECTS_SCALE, WHITE);
    }
    else if (Object.GetFoodType() == EFoodType::MOUSE)
    {
        // Draw mouse texture at the food's position
        DrawTextureEx(MouseTexture_,
                      {(Object.GetPosition().x * UI::CELL_SIZE) + UI::BOARD_INITIAL_X_POS,
                       (Object.GetPosition().y * UI::CELL_SIZE) + UI::BOARD_INITIAL_Y_POS},
                      0.0F, UI::OBJECTS_SCALE, WHITE);
    }
    else
    {
        // Draw a red rectangle for unknown food types
        DrawRectangle((int)((Object.GetPosition().x * UI::CELL_SIZE) + UI::BOARD_INITIAL_X_POS),
                      (int)((Object.GetPosition().y * UI::CELL_SIZE) + UI::BOARD_INITIAL_Y_POS), (int)UI::OBJECTS_SCALE,
                      (int)UI::OBJECTS_SCALE, RED);
    }
}

// Destructor: Unloads all loaded textures
FoodRender::~FoodRender()
{
    UnloadTexture(AppleTexture_);
    UnloadTexture(FrogTexture_);
    UnloadTexture(MouseTexture_);
}
