#include "MainMenu.h"

States::MainMenu::MainMenu() :menuChoice(0)
{
	menuChoice = 0; // initialize menuChoice to 0
	menuScreen = MainMenuScreen(); // create a new MainMenuScreen object and assign it to menuScreen
}

bool States::MainMenu::CanEnter()
{
	return true; // always return true
}

void States::MainMenu::Enter()
{
	menuChoice = -1;
	menuScreen.Display(); // call the Display function of menuScreen
}

bool States::MainMenu::Execute()
{
	menuScreen.Update(); // call the Update function of menuScreen
	if (!Input::GetInstance()->GetKeyDown(KeyCode::Enter)) // check if the Enter key is not pressed
		return false; // return false and exit the function

	menuChoice = menuScreen.GetChoice(); // get the choice selected by the user from menuScreen
	if (menuChoice == 0 || menuChoice == 1) // check if the choice is 0 or 1
		return true; // return true and exit the function

	return false; // return false and exit the function
}

States::State* States::MainMenu::Exit()
{
	if (menuChoice == 0) // check if the choice is 0
		return new MapState(); // return a new MapState object

	exit(1); // exit the application
	return new MainMenu(); // return a new MainMenu object
}