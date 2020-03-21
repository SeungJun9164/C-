#include "SelectableRandom.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

SelectableRandom::SelectableRandom()
{
	srand((unsigned)time(0));	
}
int SelectableRandom::next() {
	int num;
	while (1)
	{
		num = rand();
		if (num % 2 == 0)
			break;
	}
	return num;
}
int SelectableRandom::nextRange(int start, int end) {
	int num;
	while (1)
	{
		num = rand() % (end - start + 1) + 2;
		if (num % 2 == 1)
			break;
	}
	return num;
}