/*���ø� : �Ű� ���� Ÿ�Ը� �ٸ� �ߺ��� �Լ����� �Ϲ�ȭ ��Ų Ʋ

templateŰ���� �̿�
template <class T> || template <typename T>

��üȭ : �ߺ��Լ����� ���ø�ȭ�ϴ� ������ ������*/

#include<iostream>

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <class T>
void myswap(T& a, T& b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int a = 4, b = 5;
	myswap(a, b);
	std::cout << "a= " << a << ", b= " << b << std::endl;

	double c = 0.3, d = 12.5;
	myswap(c, d);
	std::cout << "c= " << c << ", d= " << d << std::endl;

	Circle donut(5), pizza(20);
	myswap(donut, pizza);
	std::cout << "donut�� ������ : " << donut.getRadius() << std::endl;
	std::cout << "pizza�� ������ : " << pizza.getRadius() << std::endl;
}
���ø� �Լ��� �����ϵ����� �ʰ� ȣ������� �ʴ� ���� Ʋ �̴�.
***********�Լ��� ȣ���� �� �Ű����� Ÿ���� �����ؾ��Ѵ�.************

template <class T>
T bigger(T a, T b) {
	if (a > b) return a;
	else return b;
}
int main() {
	int a = 20, b = 50;
	char c = 'a', d = 'z';
	std::cout << "bigger(20,50)�� ����� " << bigger(a, b) << std::endl;
	std::cout << "bigger(a,z)�� ����� " << bigger(c, d) << std::endl;
}