#include<iostream>

//1번
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
//2번
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
		std::cout << a << "가" << b << "보다 큽니다." << big;
	else
		std::cout << b << "가" << a << "보다 큽니다." << big;
	
}*/
//3번
/*class Circle {
	int radius;
public:
	Circle(int r) { radius = r; }
	int getrRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { std::cout << "반지름이 " << radius << "인 원\n"; }
};
void increaseBy(Circle& a, Circle& b) {
	int r = a.getrRadius() + b.getrRadius();
	a.setRadius(r);
}
int main() {
	Circle x(10), y(5);
	increaseBy(x, y);
	x.show();
}*/
//4번
/*char& find(char a[], char c, bool& success) {
	for (int i = 0; i < sizeof(a); i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}
	return *a;
}

int main() {
	char s[] = "iike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		std::cout << "M을 발견할 수 없다." << std::endl;
		return 0;
	}
	loc = 'm';
	std::cout << s << std::endl;
}*/
//5번
/*class MyIntStack {
	int p[10];
	int tos;
public:
	MyIntStack() { tos = 0; }
	bool push(int n) {
		if (tos == 10)
			return false;
		else {
			p[tos] = n;
			tos++;
			return true;
		}
	}
	bool pop(int& n) {
		tos--;
		if (tos == -1)
			return false;
		else {
			n = p[tos];
			return true;
		}
	}
};
int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i))
			std::cout << i << ' ';
		else
			std::cout << std::endl << i + 1 << " 번째 stack full" << std::endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n))
			std::cout << n << ' ';
		else
			std::cout << std::endl << i + 1 << " 번째 stack empty";
	}
	std::cout << std::endl;
}*/
//6번
/*class MyIntStack {
	int* p;
	int size;
	int tos;
public:
	MyIntStack() { tos = 0; }
	MyIntStack(int size) { tos = 0; this->size = size; p = new int[size]; }
	MyIntStack(MyIntStack& s) {
		this->p = new int[s.size];
		this->size = s.size;
		this->tos = s.tos;
		for (int i = 0; i < s.tos; i++)
			this->p[i] = s.p[i];
	}
	~MyIntStack() { delete[] p; }
	bool push(int n) {
		if (tos == size)
			return false;
		else {
			p[tos] = n;
			tos++;
			return p[tos];
		}
	}
	bool pop(int& n) {
		tos--;
		if (tos == -1)
			return false;
		else {
			n = p[tos];
			return true;
		}
	}
};
int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	std::cout << "스택 a에서 팝한 값 " << n << std::endl;
	b.pop(n);
	std::cout << "스택 b에서 팝한 값 " << n << std::endl;
}*/
//7번
class Accmulator {
	int value;
public:
	Accmulator(int value) { this->value = value; }
	Accmulator& add(int n) {
		value += n;
		return *this;
	}
	int get() { return value; }
};
int main() {
	Accmulator acc(10);
	acc.add(5).add(6).add(7);
	std::cout << acc.get();
}