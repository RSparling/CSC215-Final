#pragma once
#include "Creature.h"
#include "Map.h"
#include "Input.h"

class Player : public Creature
{
public:
	Player();

	int GetPlayerPositionX;
	int GetPlayerPositionY;

	void DoMove();
	void SetPosition(int x, int y);

private:
	int playerPositionX = 0;
	int playerPositionY = 0;
};