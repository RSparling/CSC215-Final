#pragma once
#include <string>
#include "Input.h"
#include "Display.h"

/*
Displays and handles input for gameover

TODO:
find a way to abstract screens, alot of the code is similar between them which is a sign that
it should be abstracted
*/
class GameOverScreen
{
public:
	GameOverScreen();

	void Update();
	int  GetChoice();
	void Display();

private:
	std::string screen;
	int cursor;
};
