#include "StateMachine.h"

//Initial run of the state machine, sets it to MainMenu
void StateMachine::SetUp()
{
	currentState = new MainMenu(); //Starting state
	currentState->Enter(); //call Enter on the current state
}

//called each frame
void StateMachine::Update()
{
	if (currentState->Execute()) //execute will flag true when it's time to change state
		if (!ChangeState(currentState->Exit())) { //pass the state returned by Exit to ChangeState
			ChangeState(new MainMenu());//set to Mainmenu to avoid crash. Better error handling could be used.
		}
}

//called when it's time to perform a change state.
bool StateMachine::ChangeState(State* state)
{
	Input::SuspendInput = true; // suspend so it doenst interupt the state change
	if (state->CanEnter()) {
		delete currentState;
		currentState = state;
		state->Enter();
		state->Execute();
		//<return>Return ture to flag it's successful</return>
		return true;
	}
	else
		//<return>Returns false if failes</return>
		return false;

	Input::SuspendInput = false; //resume input
}