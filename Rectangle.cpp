#include<iostream>
#include "Rectangle.h"

using namespace std;

int Rectangle::getArea()
{
	return width * height;
}

Rectangle::Rectangle()
{
	width = height = 1;
}
Rectangle::Rectangle(int x, int y)
{
	width = x;
	height = y;
}
Rectangle::Rectangle(int x)
{
	width = height = x;
}
bool Rectangle::isSqure()
{
	if (width == height)
		return true;
	else
		return false;
}
Rectangle::~Rectangle()
{
	cout << "持失切 社瑚" << endl;
}
