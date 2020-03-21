#include<string>
#include<iostream>
#include "Date.h"
using namespace std;


Date::Date(int yy, int mm, int dd)
{
	year = yy;
	month = mm;
	day = dd;
}
Date::Date(string s)
{
	str = s;	
}
void Date::show()
{
	year = stoi(str.substr(0, 4));
	month = stoi(str.substr(5, 1));
	day = stoi(str.substr(7, 2));

	cout << year << "³â" << month << "¿ù" << day << "ÀÏ" << endl;
}
int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}