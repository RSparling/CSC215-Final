#include "MainMenu.h"

States::MainMenu::MainMenu() :menuChoice(0)
{
	menuChoice = 0;
	menuScreen = MainMenuScreen();
}

bool States::MainMenu::CanEnter()
{
	return true;
}

void States::MainMenu::Enter()
{
	menuScreen.Display();
}

bool States::MainMenu::Execute()
{
	menuScreen.Update();
	if (!Input::GetInstance()->GetKeyDown(KeyCode::Enter)) //can return early as everything is handled by MenuScreen until choice is confirmed.
		return false;

	menuChoice = menuScreen.GetChoice();
	if (menuChoice == 0 || menuChoice == 1)
		return true;

	return false; //should never reach here (unless menuScreen is modified
}

States::State* States::MainMenu::Exit()
{
	if (menuChoice == 0)
		return new MapState();

	//if the menu choice is 1 then it needs to exit the application
	exit(1);
	return new MainMenu();
}