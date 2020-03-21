#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>

class SelectableRandom
{
public:
	SelectableRandom();
	int next();
	int nextRange(int start, int end);
};

