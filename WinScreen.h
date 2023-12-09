#pragma once
#include "Display.h"
#include "Input.h"
class WinScreen
{
public:
	WinScreen();

	void Update();
	int GetChoice();
	void Display();

private:
	std::string screen;
	int cursor;
};
