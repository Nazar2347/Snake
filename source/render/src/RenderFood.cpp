#include "RenderFood.h"

FoodRender::FoodRender()
{
	Image AppleImage = LoadImage("Assets/Apple.png");
	Image FrogImage = LoadImage("Assets/Frog.png");
	AppleTexture_ = LoadTextureFromImage(AppleImage);
	FrogTexture_ = LoadTextureFromImage(FrogImage);

	UnloadImage(AppleImage);
	UnloadImage(FrogImage);
	
}

void FoodRender::Draw(IEatable* Object)
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
	else if (Object->GetFoodType() == EFoodType::CHOCOLATE)
	{
		DrawTextureEx(ChokolateTexture_, {
			Object->GetPosition().x * CELL_SIZE + BOARD_INITIAL_X_POS,
			Object->GetPosition().y * CELL_SIZE + BOARD_INITIAL_Y_POS
			}, 0.0f, OBJECTS_SCALE, WHITE
		);
	}
	else
	{
		DrawRectangle(
			Object->GetPosition().x * CELL_SIZE + BOARD_INITIAL_X_POS,
			Object->GetPosition().y * CELL_SIZE + BOARD_INITIAL_Y_POS
			, OBJECTS_SCALE * 32, OBJECTS_SCALE * 32, RED);
	}

}

FoodRender::~FoodRender()
{
	UnloadTexture(AppleTexture_);
	UnloadTexture(FrogTexture_);
	UnloadTexture(ChokolateTexture_);
}



