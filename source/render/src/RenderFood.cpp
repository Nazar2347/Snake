#include "RenderFood.h"

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
	
}

void FoodRender::Draw(IFood* Object)
{
	if (Object->GetFoodType() == EFoodType::APPLE)
	{
		 DrawTextureEx(AppleTexture_, { 
			Object->GetPosition().x *CELL_SIZE +BOARD_INITIAL_X_POS, 
			Object->GetPosition().y *CELL_SIZE + BOARD_INITIAL_Y_POS
			}, 0.0f, OBJECTS_SCALE, WHITE
		 );

	}
	else if (Object->GetFoodType() == EFoodType::FROG)
	{
		DrawTextureEx(FrogTexture_, {
			Object->GetPosition().x * CELL_SIZE + BOARD_INITIAL_X_POS,
			Object->GetPosition().y * CELL_SIZE + BOARD_INITIAL_Y_POS
			}, 0.0f, OBJECTS_SCALE, WHITE
		);

	}
	else if (Object->GetFoodType() == EFoodType::MOUSE)
	{
		DrawTextureEx(MouseTexture_, {
			Object->GetPosition().x * CELL_SIZE + BOARD_INITIAL_X_POS,
			Object->GetPosition().y * CELL_SIZE + BOARD_INITIAL_Y_POS
			}, 0.0f, OBJECTS_SCALE, WHITE
		);
	}
	else
	{
		DrawRectangle(
			(int)(Object->GetPosition().x * CELL_SIZE + BOARD_INITIAL_X_POS),
			(int)(Object->GetPosition().y * CELL_SIZE + BOARD_INITIAL_Y_POS)
			, (int)OBJECTS_SCALE * 32, (int)OBJECTS_SCALE * 32, RED);
	}

}

FoodRender::~FoodRender()
{
	UnloadTexture(AppleTexture_);
	UnloadTexture(FrogTexture_);
	UnloadTexture(MouseTexture_);
}



