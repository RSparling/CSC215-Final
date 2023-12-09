#include "GameOverScreen.h"

GameOverScreen::GameOverScreen()
{
	// Initialize the screen with the game over text and options
	screen =
		"|______________________________________________________________________________________________________________________|\n"//0
		"|                                                                                                                      |\n"//1
		"|                                                                                                                      |\n"//2
		"|                                                                                                                      |\n"//3
		"|            ######   #####   #   #  ######                                                                            |\n"//4
		"|            #        #   #   ## ##  #                                                                                 |\n"//5
		"|            #  ###   #####   # # #  ####                                                                              |\n"//6
		"|            #    #   #   #   #   #  #                                                                                 |\n"//7
		"|            ######   #   #   #   #  ######                                                                            |\n"//8
		"|                                                                                                                      |\n"//9
		"|                                                                                                                      |\n"//10
		"|                                             ######  #    #  #####  #####                                             |\n"//11
		"|                                             #    #  #    #  #      #   #                                             |\n"//12
		"|                                             #    #   #  #   ####   #####                                             |\n"//13
		"|                                             #    #   #  #   #      #  #                                              |\n"//14
		"|                                             ######    ##    #####  #   #                                             |\n"//15
		"|                                                                                                                      |\n"//16
		"|                                                                                                                      |\n"//17
		"|                                                                                                                      |\n"//18
		"|                                                                                                                      |\n"//19
		"|                                                                                                                      |\n"//20
		"|----------------------------------------------------------------------------------------------------------------------|\n"//21
		"|                                                                                                                      |\n"//22
		"|                                                                                                                      |\n"//23
		"|         Try Again                                                         Quit                                       |\n"//24
		"|                                                                                                                      |\n"//25
		"|______________________________________________________________________________________________________________________|\n"//26
		;
	cursor = 0;
}

void GameOverScreen::Update()
{
	Input* input = Input::GetInstance();

	// Increment or decrement the cursor based on input
	if (input->GetKeyDown(KeyCode::Arrow_Left))
		cursor -= 1;
	else if (input->GetKeyDown(KeyCode::Arrow_Right))
		cursor += 1;

	// Keep the cursor within bounds
	if (cursor > 1)
		cursor = 0;
	else if (cursor < 0)
		cursor = 1;

	system("cls");
	std::cout << screen;

	// Set the cursor position based on the current choice
	COORD coord = { (short)cursor == 0 ? 9 : 75,(short)24 };
	Display::GetInstance()->SetCursorPosition(coord);
	std::cout << ">";
	Display::GetInstance()->PlaceCursorAtBottom();
}

int GameOverScreen::GetChoice()
{
	return cursor;
}

void GameOverScreen::Display()
{
	system("cls");
	std::cout << screen;

	// Set the cursor position based on the current choice
	COORD coord = { (short)cursor == 0 ? 15 : 81,(short)24 };
	Display::GetInstance()->SetCursorPosition(coord);
	std::cout << ">";
	Display::GetInstance()->PlaceCursorAtBottom();
}