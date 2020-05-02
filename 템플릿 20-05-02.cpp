#include<iostream>

//하나의 제네릭 타입을 가진 경우
/*template <class T>
T add(T data[], int n) {
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += data[i];
	return sum;
}
int main() {
	int x[] = { 1,2,3,4,5 };
	double d[] = { 1.2,2.3,3.4,5.6,6.7 };

	std::cout << "sum of x[] " << add(x, 5) << std::endl;
	std::cout << "sum of d[] " << add(d, 6) << std::endl;
}

//두개 이상의 제네릭 타입을 가진 경우
template <class T1, class T2>
void mcopy(T1 src[], T2 dest[], int n) {
	for (int i = 0; i < ni++)
		dest[i] = (T2)src[i];
}
int main() {
	int x[] = { 1,2,3,4,5 };
	double d[5];
	char c[5] = { 'H','e','l','l','o' }, e[5];

	mcopy(x, d, 5);
	mcopy(c, e, 5);

	for (int i = 0; i < 5; i++) std::cout << d[i] << ' ' << "\n";
	for (int i = 0; i < 5; i++) std::cout << e[i] << ' ' << "\n";
}

//템플릿 함수보다 중복함수가 우선
template <class T>
void print(T array[], int n) {
	for (int i = 0; i < n; i++)
		std::cout << arra[i] << '\t';
	std::cout << endl;
}
void print(char array[], int n) {
	for (int i = 0; i < n; i++)
		std::cout << (int)array[i] << '\t';
	std::cout << std::endl;
}
int main() {
	int x[] = { 1,2,3,4,5 };
	double d[5] = { 1.1,2.2,3.3,4.4,5.5 };
	print(x, 5);
	print(d, 5);

	char c[5] = { 1,2,3,4,5 };
	print(c, 5);//이름이 중복된 함수를 템플릿 함수보다 먼저 바인딩하므로 1,2,3,4,5 출력
}*/

//제네릭 스택 클래스
template <class T>
class MyStack {
	int tos;
	T data[100];
public:
	MyStack();
	void push(T element);
	T pop();
};

template <class T>
MyStack<T>::MyStack() {
	tos = -1;
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		std::cout << "stack full";
		return;
	}
	tos++;
	data[tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	T retData;
	if (tos == -1) {
		std::cout << "stack empty";
		return 0;
	}
	retData = data[tos--];
	return retData;
}

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	void show() { std::cout << '(' << x << ',' << y << ')' << std::endl; }
};
//1번
/*int main() {
	MyStack<int> iStack; //int만 저장할 수 있는 스택
	iStack.push(3);
	std::cout << iStack.pop() << std::endl;

	MyStack<double> dStack;
	dStack.push(3.5);
	std::cout << dStack.pop() << std::endl;

	MyStack<char>* p = new MyStack<char>();
	p->push('a');
	std::cout << p->pop() << std::endl;
	delete p;
}*/
//2번
int main() {
	MyStack<int*> ipStack; //int*만 저장할 수 있는 스택

	int* p = new int[3];
	for (int i = 0; i < 3; i++)
		p[i] = i * 10;
	ipStack.push(p);
	int* q = ipStack.pop();
	for (int i = 0; i < 3; i++)
		std::cout << q[i] << ' ';
	std::cout << "\n";
	delete[] p;


	MyStack<Point> pointStack; //Point 형만 저장할 수 있는 스택
	Point a(2, 3), b;
	pointStack.push(a);
	b = pointStack.pop();
	b.show();

	MyStack<Point*> pStack; //Point* 형만 저장할 수 있는 스택
	pStack.push(new Point(10, 20));
	Point* pPoint = pStack.pop();
	pPoint->show();

	MyStack<std::string> stringStack; //string 형만 저장할 수 있는 스택
	std::string s = "c++";
	stringStack.push(s);
	stringStack.push("java");
	std::cout << stringStack.pop() << ' ';
	std::cout << stringStack.pop() << ' ';
}

//두 개 이상의 제네릭 타입을 가진 제네릭 클래스

template <class T1, class T2>
class GClass {
	T1 data1;
	T2 data2;
public:
	GClass();
	void set(T1 a, T2 b);
	void get(T1& a, T2& b);
};

template <class T1, class T2>
GClass<T1, T2>::GClass() {
	data1 = 0; data2 = 0;
}

template <class T1, class T2>
void GClass<T1, T2>::set(T1 a, T2 b) {
	data1 = a; data2 = b;
}

template <class T1, class T2>
void GClass<T1, T2>::get(T1 &a, T2 &b) {
	a = data1; b = data2;
}
int main() {
	int a;
	double b;
	GClass<int, double> x;
	x.set(2, 0.5);
	x.get(a, b);
	std::cout << "a=" << a << "\tb=" << b << std::endl;

	char c;
	float d;
	GClass<char, float> y;
	y.set('m', 12.5);
	y.get(c, d);
	std::cout << "c=" << c << "\td=" << d << std::endl;
}
