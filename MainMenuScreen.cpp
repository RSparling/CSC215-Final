#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen()
{
	screen =
		"|______________________________________________________________________________________________________________________|\n"//0
		"|                                                                                                                      |\n"//1
		"|                                                                                                                      |\n"//2
		"|                                                                                                                      |\n"//3
		"|                                                                                                                      |\n"//4
		"|     #######          ##            ##      ###           ##         ######          #######     ###           ##     |\n"//5
		"|     #########        ##            ##      ###           ##      ###      ##       #       #    ###           ##     |\n"//6
		"|     ##       ##      ##            ##      ## ##         ##    ##           #     #         #   ## ##         ##     |\n"//7
		"|     ##        ##     ##            ##      ## ##         ##    ##            #    #         #   ## ##         ##     |\n"//8
		"|     ##         ##    ##            ##      ##   ##       ##    ##            ##   #         #   ##   ##       ##     |\n"//9
		"|     ##         ##    ##            ##      ##   ##       ##    ##            ##   #         #   ##   ##       ##     |\n"//10
		"|     ##         ##    ##            ##      ##     #      ##    ##                 #         #   ##     #      ##     |\n"//11
		"|     ##         ##    ##            ##      ##     #      ##    ##                 #         #   ##     #      ##     |\n"//12
		"|     ##         ##    ##            ##      ##     #      ##    ##                 #         #   ##     #      ##     |\n"//13
		"|     ##         ##    ##            ##      ##      #     ##    ##        ######   #         #   ##      #     ##     |\n"//14
		"|     ##         ##    ##            ##      ##       #    ##    ##         #####   #         #   ##       #    ##     |\n"//15
		"|     ##        ##     ##            ##      ##       #    ##    ##            ##   #         #   ##       #    ##     |\n"//16
		"|     ##       ##      ##            ##      ##         #  ##    ##            ##   #         #   ##         #  ##     |\n"//17
		"|     ##      ##       ##            ##      ##         #  ##    ##            ##   #         #   ##         #  ##     |\n"//18
		"|     #########          ##        ##        ##          ####      ###      ###      #       #    ##          ####     |\n"//19
		"|     ######               ########          ##          ####        ########         #######     ##          ####     |\n"//20
		"|                                                                                                                      |\n"//21
		"|______________________________________________________________________________________________________________________|\n"//22
		"|                                                                                                                      |\n"//23
		"|               Begin                                                             Exit                                 |\n"//24
		"|                                                                                                                      |\n"//25
		"|__ Use Left and Right Arrow to navigate, enter to confirm ____________________________________________________________|\n"//26
		;
	cursor = 0;
}

void MainMenuScreen::Update()
{
	Input* input = Input::GetInstance();

	//incriment cursor based on input
	if (input->GetKeyDown(KeyCode::Arrow_Left))
		cursor -= 1;
	else if (input->GetKeyDown(KeyCode::Arrow_Right))
		cursor += 1;

	//keep cursor in bounds
	if (cursor > 1)
		cursor = 0;
	else if (cursor < 0)
		cursor = 1;

	system("cls");
	std::cout << screen;

	COORD coord = { (short)cursor == 0 ? 15 : 81,(short)24 };
	Display::GetInstance()->SetCursorPosition(coord);
	std::cout << ">";
	Display::GetInstance()->PlaceCursorAtBottom();
}
int MainMenuScreen::GetChoice()
{
	return cursor;
}

void MainMenuScreen::Display()
{
	system("cls");
	std::cout << screen;

	COORD coord = { (short)cursor == 0 ? 15 : 81,(short)24 };
	Display::GetInstance()->SetCursorPosition(coord);
	std::cout << ">";
	Display::GetInstance()->PlaceCursorAtBottom();
}