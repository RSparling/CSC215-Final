#pragma once
#include <vector>

struct Stats {
public:
	Stats(int startingHitpoints = -1, int startingMana = -1, int startingDamage = -1) {
		hitpoints = startingHitpoints == -1 ? rand() % 10 + 1 : startingHitpoints;
		mana = startingMana == -1 ? rand() % 10 + 1 : startingMana;
		damage = startingDamage == -1 ? rand() % 4 + 2 : damage;
	}
	int GetHitpoints() {
		return hitpoints;
	}

	int GetMana() {
		return mana;
	}

	int GetDamage() {
		return damage;
	}

	//returns true if hitpoints is reduce to 0 or less
	bool TakeDamage(int damage) {
		hitpoints -= damage;
		if (hitpoints <= 0) {
			return true;
		}
		return false;
	}

	void SetHitpoints(int hp) {
		hitpoints = hp;
	}

	void ModifyHitpoints(int ammt) {
		hitpoints += ammt;
	}

	void SetMana(int m) {
		mana = m;
	}

	void ModifyMana(int ammt) {
		mana += ammt;
	}

	int RollDamage() {
		int result = (rand() % damage) + damage / 2;
		return result;
	}

private:
	int hitpoints;
	int damage;
	int mana;
};