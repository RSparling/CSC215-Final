#pragma once
#include "Stats.h"

/*
<summary>
A wrapper class for Stats that allows for polymorphism.
</summary>
*/
class Creature {
public:
	Creature() {
		stats = Stats();
	}

	//getters
	int GetHealth() {
		return stats.GetHitpoints();
	}

	int GetMana() {
		return stats.GetMana();
	}

	int GetDamage() {
		return stats.GetDamage();
	}

	//void Modify
	void ModifyHitpoints(int ammt) {
		stats.ModifyHitpoints(ammt);
	}

	void ModifyMana(int ammt) {
		stats.ModifyMana(ammt);
	}

	//setters
	void SetMana(int ammt) {
		stats.SetMana(ammt);
	}

	void SetHealth(int ammt) {
		stats.SetHitpoints(ammt);
	}

	//combat
	//roll damage
	int RollDamage() {
		return stats.RollDamage();
	}

	//return true if health <= 0
	bool TakeDamage(int ammt) {
		return stats.TakeDamage(ammt);
	}

	//gain a random ammount of mana
	int RecoverMP() {
		int ammt = rand() % 9 + 3;//recover 3-10 mana
		stats.ModifyMana(ammt);
		return ammt;
	}

	int Heal() {
		int ammt = rand() % 9 + 5; //gain 5-13 health
		if (ammt > stats.GetMana())
			return 0;
		stats.ModifyHitpoints(ammt);
		stats.ModifyMana(-(rand() % 4 + 1));//1-4 mana cost
		return ammt;
	}
private:
	Stats stats;
};