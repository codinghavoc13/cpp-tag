#include "stdafx.h"
#include <stdlib.h> //IMPORTANT!!!
#include <time.h> //IMPORTANT!!!
using namespace std;

class RandNum
{
public:
	RandNum() {};
	int num;
	int getNum()
	{
		srand((unsigned int)time(NULL));
		//int num = 0;
		num = rand() % 12 + 1;
		return num;
	}
};