#include "InputHandler.h"


InputHandler::InputHandler()
{
	 ButtonW_ = new MoveUPCommand();
	 ButtonD_ = new MoveRightCommand();
	 ButtonA_ = new MoveLeftCommand();
	 ButtonS_ = new MoveDownCommand();
	 NullCommand_ = new NullCommand();
}
Command* InputHandler::HandleInput()
{
	if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
	{
		return ButtonW_;
	}
	else if(IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
	{
		return ButtonD_;
	}
	else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
	{
		return ButtonA_;
	}
	else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
	{
		return ButtonS_;
	}
	else
	{
		return NullCommand_;
	}
}

InputHandler::~InputHandler()
{
	delete ButtonW_;
	delete ButtonD_;
	delete ButtonA_;
	delete ButtonS_;
	delete NullCommand_;
}

