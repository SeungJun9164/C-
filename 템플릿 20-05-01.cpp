/*템플릿 : 매개 변수 타입만 다른 중복된 함수들을 일반화 시킨 틀

template키워드 이용
template <class T> || template <typename T>

구체화 : 중복함수들을 템플릿화하는 과정의 역과정*/

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
	std::cout << "donut의 반지름 : " << donut.getRadius() << std::endl;
	std::cout << "pizza의 반지름 : " << pizza.getRadius() << std::endl;
}
템플릿 함수는 컴파일되지도 않고 호출되지도 않는 그저 틀 이다.
***********함수를 호출할 때 매개변수 타입이 동일해야한다.************

template <class T>
T bigger(T a, T b) {
	if (a > b) return a;
	else return b;
}
int main() {
	int a = 20, b = 50;
	char c = 'a', d = 'z';
	std::cout << "bigger(20,50)의 결과는 " << bigger(a, b) << std::endl;
	std::cout << "bigger(a,z)의 결과는 " << bigger(c, d) << std::endl;
}