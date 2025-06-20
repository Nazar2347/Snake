#include "RenderBoard.h"
#include <iostream>

RenderBoard::RenderBoard(const Board& Board): LevelBoard_(Board)
{
	Image TopBorder = LoadImage("C:/Users/dunas/source/repos/Snake/Assets/BorderTop.png");
	if (TopBorder.data == NULL)
	{
		std::cout << "Failed to load image for BorderTop.png \n";
	}
	
	BorderTopTexture_ = LoadTextureFromImage(TopBorder);
	if (BorderTopTexture_.id == 0)
	{
		std::cout << "Failed to load texture for BorderTop.png \n";
	}
	UnloadImage(TopBorder);
}

void RenderBoard::Draw() const
{
	if (BorderTopTexture_.id !=NULL)
	{
		for (int i = 0; i < LevelBoard_.getLevelData().size(); i++)
		{
			for (int j = 0; j < LevelBoard_.getLevelData().at(i).size(); j++)
			{
				Vector2 CurrentCell = { i,j };
				if (LevelBoard_.GetCellInfo(CurrentCell) == 1)
				{
					DrawTextureEx(BorderTopTexture_, { CurrentCell.x*30,CurrentCell.y*30 }, 0.0f, 0.11f, WHITE);
				}
				
			}
		}
	}
	else
	{
		std::cout << "Texture not valid, cannot draw\n";
	}
}

RenderBoard::~RenderBoard()
{
	UnloadTexture(BorderTopTexture_);
}
