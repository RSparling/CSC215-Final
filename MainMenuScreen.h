#pragma once
#include <iostream>
#include <string.h>
#include "Input.h"
#include "Display.h"

class MainMenuScreen
{
public:
	MainMenuScreen();

	void Update();
	int  GetChoice();
	void Display();
private:
	std::string screen;
	int cursor;
};