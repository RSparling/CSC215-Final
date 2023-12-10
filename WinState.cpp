#include "WinState.h"

bool States::WinState::CanEnter() // Check if the state can be entered
{
	return true; // Cannot enter the Game Over state
}

void States::WinState::Enter() // Enter the Game Over state
{
	winScreen.Display(); // Display the Game Over screen
	Input::SuspendInput = false;
	Input::FlushInputs();
}

bool States::WinState::Execute() // Execute the Game Over state
{
	winScreen.Update(); // Update the Game Over screen

	if (!input->GetKeyDown(KeyCode::Enter)) {// If the Enter key is pressed	
		return false;
	}
	else {
		menuChoice = winScreen.GetChoice();
		if (menuChoice == 0 || menuChoice == 1)
			return true;
	}
	return false;  // Return false to indicate that the game over has not been confirmed yet
}

State* States::WinState::Exit() // Exit the Game Over state
{
	int choice = winScreen.GetChoice(); // Get the player's choice from the Game Over screen

	if (choice == 1) // If the choice is 1 (exit game)
		exit(1); // Exit the game

	return new MainMenu(); // Return a new MainMenu state
}