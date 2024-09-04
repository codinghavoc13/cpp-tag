#pragma once
#include "stdafx.h"
#include "player.h"
#include <math.h>

void Player::incPlayerExp(int n)
{
	int exp = getExp();
	int newLevel = getLevel();
	int newExp = exp + n;
	int check = 40 * newLevel;
	if (newExp > check)
	{
		do
		{
			newLevel++;
			check = 40 * newLevel;
		} while (exp > check);
	}

	cout << "New level is: " << newLevel << endl;
	cout << "New exp amount is " << newExp << endl;
	setLevel(newLevel);
	setExp(newExp);
}

