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
	map = Map::GetInstance();
	player = Player::GetInstance();
	map->PrintMapFull();
	Input::SuspendInput = false;
	currentEncounterChance = baseEncounterChance;
	srand(time(0));
	isEncounter = false;
	isPlayeWin = false;
}

//called every frame, used for the main logic of the state. Returns false on error or when the state is finished.
bool MapState::Execute()
{
	player->DoMove();
	map->PrintMap();
	if (isThereEncounter())
	{
		isEncounter = true;
		return true;
	}

	if (map->GetTileIDAt(player->GetPositionX(), player->GetPositionY()) == 4) // tile is equal to win tile;
	{
		isPlayeWin = true;
		return true;
	}

	return false;
}
//called when the state is exited, used for cleanup and last run operations
State* MapState::Exit()
{
	if (isPlayeWin)
		return new WinState();

	else
		return new EncounterState();
}

bool MapState::isThereEncounter()
{
	lastRoll = rand() % 150;

	if (lastRoll < currentEncounterChance)
	{
		isEncounter = true;
		return true;
	}
	else
		currentEncounterChance += chanceIncreasePerStep;
	return false;
}