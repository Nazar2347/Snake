#pragma once
#include "IFood.h"
#include "RenderConstant.h"


class FoodRender
{
public:
	FoodRender();
	void Draw(IFood* Object);
	virtual ~FoodRender();
protected:
	Texture2D AppleTexture_;
	Texture2D FrogTexture_;
	Texture2D MouseTexture_;
};





