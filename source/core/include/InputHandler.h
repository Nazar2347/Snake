#pragma once
#include "Command.h"
#include <raylib.h>

class InputHandler
{
public:
	InputHandler();
	Command* HandleInput();
	virtual ~InputHandler();
private:
	Command* ButtonW_;
	Command* ButtonD_;
	Command* ButtonA_;
	Command* ButtonS_;
	Command* NullCommand_;

};
