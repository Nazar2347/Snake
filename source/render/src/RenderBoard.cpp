#include "RenderBoard.h"
#include "RenderConstant.h"
#include <iostream>

RenderBoard::RenderBoard(const Board& Board): LevelBoard_(Board)
{
	Image TopBorder = LoadImage("Assets/BorderTop.png");
	Image Ground1 = LoadImage("Assets/Ground1.png");
	if (TopBorder.data == NULL || Ground1.data==NULL)
	{
		std::cout << "Failed to load image \n";
	}
	
	BorderTopTexture_ = LoadTextureFromImage(TopBorder);
	GroundTexture_ = LoadTextureFromImage(Ground1);
	if (BorderTopTexture_.id == 0 || GroundTexture_.id ==0)
	{
		std::cout << "Failed to load texture for BorderTop.png \n";
	}
	UnloadImage(TopBorder);
	UnloadImage(Ground1);
}

void RenderBoard::Draw() const
{
	DrawBorder();
	DrawGround();
	
}

RenderBoard::~RenderBoard()
{
	UnloadTexture(BorderTopTexture_);
}

void RenderBoard::DrawBorder() const
{
	if (BorderTopTexture_.id != NULL)
	{
		for (int i = 0; i < LevelBoard_.GetLevelXSize(); i++)
		{
			for (int j = 0; j < LevelBoard_.GetLevelYSize(); j++)
			{
				Vector2 CurrentCell = { i,j };
				if (LevelBoard_.GetCellInfo(CurrentCell) == 1)
				{
					DrawTextureEx(BorderTopTexture_, { CurrentCell.x * CELL_SIZE+BOARD_INITIAL_X_POS,
						CurrentCell.y * CELL_SIZE +BOARD_INITIAL_Y_POS }, 0.0f, 0.11f, WHITE);
				}

			}
		}
	}
	else
	{
		std::cout << "Texture not valid, cannot draw\n";
	}
}

void RenderBoard::DrawGround() const
{
	if (GroundTexture_.id != NULL)
	{
		for (int i = 0; i < LevelBoard_.GetLevelXSize(); i++)
		{
			for (int j = 0; j < LevelBoard_.GetLevelYSize(); j++)
			{
				Vector2 CurrentCell = { i,j };
				if (LevelBoard_.GetCellInfo(CurrentCell) == 0)
				{
					DrawTextureEx(GroundTexture_,{ 
						CurrentCell.x * CELL_SIZE + BOARD_INITIAL_X_POS,
						CurrentCell.y * CELL_SIZE + BOARD_INITIAL_Y_POS }, 
						0.0f, 0.11f, WHITE);
				}

			}
		}
	}
}
