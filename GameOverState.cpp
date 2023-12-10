#include "GameOverState.h"

bool States::GameOverState::CanEnter() // Check if the state can be entered
{
	return true; // Cannot enter the Game Over state
}

void States::GameOverState::Enter() // Enter the Game Over state
{
	gameOverScreen.Display();
	Input::SuspendInput = false;
	Input::FlushInputs();
	 // Display the Game Over screen
}

bool States::GameOverState::Execute() // Execute the Game Over state
{
	gameOverScreen.Update(); // Update the Game Over screen

	if (!input->GetKeyDown(KeyCode::Enter)) {// If the Enter key is pressed	
		return false;
	}
	else {
		menuChoice = gameOverScreen.GetChoice();
		if (menuChoice == 0 || menuChoice == 1)
			return true;
	}
	return false; // Return false to indicate that the game over has not been confirmed yet
}

State* States::GameOverState::Exit() // Exit the Game Over state
{
	if (menuChoice == 1) // If the choice is 1 (exit game)
		exit(1); // Exit the game

	return new MainMenu(); // Return a new MainMenu state
}