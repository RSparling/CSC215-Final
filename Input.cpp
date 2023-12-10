#include "Input.h"

Input* Input::instance = nullptr;

bool Input::SuspendInput = false;
Input::Input()
{
	instance = this;
	inputs.assign(KeyCode::LAST_ELEMENT, false);
}

//called every frame to set keys
void Input::Update()
{
	//reset all keys to false
	inputs.assign(KeyCode::LAST_ELEMENT, false);

	//early end flag
	if (SuspendInput)
		return;

	int ch = _getch(); // Get the first code of the key

	if (ch == 0 || ch == 224) // Check if it's a special key (like arrow keys)
	{
		int ch2 = _getch(); // Get the second code of the key

		// Update inputs based on the arrow key pressed
		switch (ch2)
		{
		case 72: inputs[KeyCode::Arrow_Up] = true; break;    // Up arrow key
		case 80: inputs[KeyCode::Arrow_Down] = true; break;  // Down arrow key
		case 75: inputs[KeyCode::Arrow_Left] = true; break;  // Left arrow key
		case 77: inputs[KeyCode::Arrow_Right] = true; break; // Right arrow key
		}
	}
	else
	{
		// Update inputs for other keys like Escape and Enter
		switch (ch)
		{
		case 27: inputs[KeyCode::Esc] = true; break;   // Escape key
		case 13: inputs[KeyCode::Enter] = true; break; // Enter key
		}
	}
}

//return the instance of input using the singleton pattern
Input* Input::GetInstance()
{
	//if instance is null, create a new instance
	//this is to ensure there is no null return;
	if (instance == nullptr)
		instance = new Input();
	return instance;
}

void Input::FlushInputs()
{
	instance->inputs.assign(KeyCode::LAST_ELEMENT, false);
}

bool Input::GetKeyDown(KeyCode key)
{
	//try catch to catch weird out of bounds errors.
	try {
		return inputs[key];
	}
	catch (const std::exception& excep) {
		return false;
	}
}