#include<iostream>

//1��
/*void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	int a = 3, b = 2;
	swap(a, b);
	std::cout << a << " " << b;

	return 0;
}*/

//2��
/*bool bigger(int a, int b, int& big) {
	if (a == b)
		return true;
	else {
		if (a > b)
			big = a;
		else
			big = b;
		return false;
	}
}
int main() {
	int a = 3, b = 2, big;
	if (bigger(a, b, big))
		std::cout << a << "��" << b << "���� Ů�ϴ�." << big;
	else
		std::cout << b << "��" << a << "���� Ů�ϴ�." << big;
	
}*/

class Circle {
	int radius;
public:
	Circle(int r) { radius = r; }
	int getrRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { std::cout << "�������� " << radius << "�� ��\n"; }
};
void increaseBy(Circle& a, Circle& b) {
	int r = a.getrRadius() + b.getrRadius();
	a.setRadius(r);
}
int main() {
	Circle x(10), y(5);
	increaseBy(x, y);
	x.show();

}