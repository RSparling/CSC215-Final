#pragma once
#include "Creature.h"
#include "Input.h"
#include "Map.h"

class Player : public Creature
{
public:
	Player(int startingPositionX = 27, int startingPositionY = 10);

	//getters
	int GetPositionX() { return positionX; }
	int GetPositionY() { return positionY; }

	//actions
	void DoMove();
	void SetPosition(int x, int y);

	void Update();

	static Player* GetInstance() {
		if (instance == nullptr)
			instance = new Player(27, 10); //should be set to the spawn room though first instance is set by Game.h so it should not be reset
		return instance;
	}

private:
	int positionX = 0;
	int positionY = 0;

	static Player* instance;
};