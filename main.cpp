#include<iostream>
#include"Rectangle.h"

using namespace std;

int main()
{
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSqure()) cout << "rect1�� ���簢���̴�." << endl;
	if (rect2.isSqure()) cout << "rect2�� ���簢���̴�." << endl;
	if (rect3.isSqure()) cout << "rect3�� ���簢���̴�." << endl;
	cout << "�簢���� ���̴� : " << rect1.getArea() << endl;
	cout << "�簢���� ���̴� : " << rect2.getArea() << endl;
	cout << "�簢���� ���̴� : " << rect3.getArea() << endl;

	return 0;
}