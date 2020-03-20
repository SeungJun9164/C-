#include<iostream>
#include"Rectangle.h"

using namespace std;

int main()
{
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSqure()) cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSqure()) cout << "rect2은 정사각형이다." << endl;
	if (rect3.isSqure()) cout << "rect3은 정사각형이다." << endl;
	cout << "사각형의 넓이는 : " << rect1.getArea() << endl;
	cout << "사각형의 넓이는 : " << rect2.getArea() << endl;
	cout << "사각형의 넓이는 : " << rect3.getArea() << endl;

	return 0;
}