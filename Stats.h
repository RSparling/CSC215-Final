#pragma once
#include <vector>

enum Stat {
	hitPoints,
	magicPoints,
	strength,
	speed,
	stamina,
	smarts,
	pAttack,
	mAttack,
	pDefense,
	mDefense,
	res_fire,
	res_earth,
	res_air,
	res_water,
	ENDMARKER
};

struct Stats {
public:
	Stats() {
		stats.assign(Stat::ENDMARKER, 0);
	}
	int GetStat(Stat stat) {
		return stats[stat];
	}
	int SetStat(Stat stat, int value) {
		stats[stat] = value;
	}
	int ModifyStat(Stat stat, int value) {
		stats[stat] += value;
	}

private:
	std::vector<int> stats;
};