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