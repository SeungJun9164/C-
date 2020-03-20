#pragma once
class Rectangle
{
private:
	int width;
	int height;
public:
	int getArea();
	Rectangle();
	Rectangle(int x, int y);
	Rectangle(int x);
	bool isSqure();
	~Rectangle();
};
