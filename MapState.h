#pragma once
#include <iostream>
#include "Input.h"
#include "State.h"
#include "Map.h"

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
		MapState() :map(*new Map()) {
		}
		// Inherited via State
		bool CanEnter() override;
		void Enter() override;
		bool Execute() override;
		State* Exit() override;

	private:
		Map& map;
	};
}