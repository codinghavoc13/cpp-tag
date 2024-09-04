#pragma once
#include "stdafx.h"
#include <cstdlib> //IMPORTANT!!!
#include <ctime> //IMPORTANT!!!
#include <iostream>

using namespace std;

int randNum()
{
	int random_integer;
	random_integer = (rand() % 12) + 1;
	return random_integer;
}

int randItemNum()
{
	int random_integer;
	random_integer = (rand() % 6) + 1;
	return random_integer;
}

int randEnemyNum()
{
	int random_integer;
	random_integer = (rand() % 5) + 1;
	return random_integer;
}

int randCombatNum()
{
	int random_integer;
	random_integer = (rand() % 4) + 1;
	return random_integer;
}

//Below is extra code used for testing

/*char block = 219;
for (int ctr = 0; ctr < 10; ctr++)
cout << block;
cout << endl;*/

//int a = 0, b = 0, c = 0; //Test purposes only

/*Test purposes only. Used for evaluating random values with modulus of 3
for (int ctr = 0; ctr < 200; ctr++){

for (int i = 0; i < 16; i++)
{
int test = randNum();
//cout << i << ": " << test << endl;
test = randNum() % 3; //Used to determine chances of treasure and/or enemy

switch (test){
case 0:
a++;
break;
case 1:
b++;
break;
case 2:
c++;
break;
}
}
}
cout << " a: " << a << " b: " << b << " c: " << c << endl;  //Test purposes only*/

//Work the following code in to the new sector code after creating the start sector
//srand(time(NULL));
//int randNum;
//int countA = 0, countB = 0;
//int myArray[3][3];
////cout << "Fill:\n";
//for (int a = 0; a < 3; a++)
//	for (int b = 0; b < 3; b++)
//	{
//		randNum = rand() % 25 + 1;
//		cout << randNum << " ";
//		myArray[a][b] = (randNum % 2);
//	}
////cout << "Print:\n";
//cout << endl;
//for (int a = 0; a < 3; a++)
//	for (int b = 0; b < 3; b++)
//	{
//		if (myArray[a][b] == 1)
//		{
//			cout << myArray[a][b] << endl;
//			countA++;
//		}
//		else
//		{
//			cout << myArray[a][b] << endl;
//			countB++;
//		}
//	}

//cout << "countA: " << countA << endl;
//cout << "countB: " << countB << endl;

//Single rand
//char myArray2[20];
//for (int ctr = 0; ctr < 20; ctr++)
//{
//	randNum = rand() % 25 + 1;
//	myArray2[ctr] = randNum;
//	if (randNum % 2 == 1)
//		myArray2[ctr] = 'y';
//	else
//		myArray2[ctr] = 'n';
//	cout << myArray2[ctr] << " ";
//}