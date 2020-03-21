#pragma once
#include <iostream>

using namespace std;
class Date
{private:
	int year;
	int month;
	int day;
	string str;
public:
	Date(int yy, int mm, int dd);
	Date(string s);
	void show();
	int getYear();
	int getMonth();
	int getDay();
};

