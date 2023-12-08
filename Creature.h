#pragma once
#include "Stats.h"

class Creature
{
public:
	Creature() {
		stats = *new Stats();
	}

	int GetHitPoints() { return stats.GetStat(Stat::hitPoints); }
	int GetMagicPoints() { return stats.GetStat(Stat::magicPoints); }

	//inbetween function to prevent direct access
	int GetStat(Stat stat) { return stats.GetStat(stat); }
private:
	Stats stats;
};