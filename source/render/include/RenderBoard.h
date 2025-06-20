#pragma once
#include "Board.h"
#include "RenderConstant.h"
class RenderBoard
{
public:
	RenderBoard(const Board& Board);
	void Draw()const;
	virtual ~RenderBoard();
private:
	Board LevelBoard_;
	Texture2D BorderTopTexture_;
	Texture2D GroundTexture_;
	void DrawBorder()const;
	void DrawGround()const;
	
};
