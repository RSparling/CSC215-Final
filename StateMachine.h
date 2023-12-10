/// <summary>
/// Class representing a state machine that manages different states of the application.
/// </summary>
/// <remarks>
/// This class is responsible for setting up the initial state, updating the current state, and changing states.
/// </remarks>
#pragma once
#include "State.h"
#include "MainMenu.h"

using namespace States;

class StateMachine
{
public:
	void SetUp();
	void Update();
	bool ChangeState(State* state);

private:
	State* currentState;
	State* previousState;
};