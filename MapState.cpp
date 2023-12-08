#include "MapState.h"

//checks if the state can be entered, should only be false on an error.
bool MapState::CanEnter()
{
	return true;
}

//called when the state is entered.
void MapState::Enter()
{
	system("cls");
	map.PrintMapFull();
	Input::SuspendInput = false;
}

//called every frame, used for the main logic of the state. Returns false on error or when the state is finished.
bool MapState::Execute()
{
	Input* input = Input::GetInstance();
	int viewportX = map.GetViewportPositionX();
	int viewportY = map.GetViewportPositionY();
	if (input->GetKeyDown(KeyCode::Arrow_Up))
		map.SetViewportPosition(viewportX, viewportY - 1);
	else if (input->GetKeyDown(KeyCode::Arrow_Down))
		map.SetViewportPosition(viewportX, viewportY + 1);
	else if (input->GetKeyDown(KeyCode::Arrow_Left))
		map.SetViewportPosition(viewportX - 1, viewportY);
	else if (input->GetKeyDown(KeyCode::Arrow_Right))
		map.SetViewportPosition(viewportX + 1, viewportY);

	map.PrintMap();
	return false;
}
//called when the state is exited, used for cleanup and last run operations
State* MapState::Exit()
{
	return nullptr;
}