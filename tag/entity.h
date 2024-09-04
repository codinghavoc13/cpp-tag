#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Entity {

public:
	void setHealth(double h) { health = h; }
	void incHealth(double h)
	{
		health = health + h;
		if (health > 100)
			health = 100;
	}
	void decHealth(double h) { health = health - h; }
	double getHealth() { return health; }

	void setWeaponDmg(double wd) { weaponDamage = wd; }
	double getWeaponDmg() { return weaponDamage; }
	void setDmgMult(double dm) { dmgMulti = dm; }
	double getDmgMult() { return dmgMulti; }

	double getTotalDmg() { return weaponDamage * dmgMulti; }

private:
	double health = 100.0;
	double weaponDamage = 10.0;
	double dmgMulti = 1.0;
};