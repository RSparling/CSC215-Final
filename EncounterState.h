#pragma once
#include "State.h"
#include "Player.h"
#include "CombatScreen.h"
#include "MapState.h"
#include "GameOverState.h"

using States::State;

namespace States {
	/*
		<summary>
			Handles player combat encounters.
		</summary>
	*/
	class EncounterState : public State
	{
	public:
		// Inherited via State
		bool CanEnter() override;
		void Enter() override;
		bool Execute() override;
		State* Exit() override;

	private:
		CombatScreen* combatScreen;
		Creature monsterCombatData;
		Creature* playerCombatData;
		void ResolveCombatRound();

		bool isGameOver;
		bool isCombatOver;
	};
}