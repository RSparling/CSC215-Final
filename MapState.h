#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Input.h"
#include "State.h"
#include "Map.h"
#include "Player.h"
#include "EncounterState.h"
#include "WinState.h"
using namespace States;

namespace States {
	/*
	<summary>
	This is the state that the game will be in when the player is on the map.
	</summary>
	*/
	class MapState :public State
	{
	public:
		// Inherited via State
		bool CanEnter() override;
		void Enter() override;
		bool Execute() override;
		State* Exit() override;
	private:
		Map* map;
		Player* player;

		bool isThereEncounter();

		//every time the player moves, there is a chance of an encounter
		//this increases the chance of an encounter every time the player moves
		float baseEncounterChance = 5;
		float chanceIncreasePerStep = .1;
		float currentEncounterChance = 0;

		bool isPlayeWin = false;

		//exists to aid in debugging
		float lastRoll = 0;

		//flag for state change
		bool isEncounter = false;
	};
}