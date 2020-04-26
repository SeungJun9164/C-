#include<iostream>

//1��, 2��
/*class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};
class NamedCircle : public Circle {
	std::string name;
	int radius;
public:
	NamedCircle() { ; }
	NamedCircle(int radius, std::string name) { 
		this->radius = radius;
		this->name = name; 
		setRadius(radius);
	}
	void setName(std::string name) { this->name = name; }
	std::string getName() { return name; }
	void show() {
		std::cout << "�������� "<< getRadius() << "�� "<< name <<std::endl;
	}
};

int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();

	NamedCircle pizza[5];
	int radius, max;
	std::string name, max_name;

	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << ">> ";
		std::cin >> radius >> name;
		pizza[i].setRadius(radius);
		pizza[i].setName(name);
	}
	max = pizza[0].getRadius();
	for (int i = 1; i < 5; i++) {
		if (pizza[i].getRadius() > max) {
			max = pizza[i].getRadius();
			max_name = pizza[i].getName();
		}
	}
	std::cout << "���� ������ ū ���ڴ� " << max_name << std::endl;
	return 0;
}*/
//3��, 4��
/*class Point {
	int x, y;
public:
	Point() { ; }
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {
	std::string color;
public:
	ColorPoint(int x = 0, int y = 0, std::string color = "BLACK") : Point(x, y) {
		this->color = color;
	}
	void setPoint(int x, int y) {
		move(x, y);
	}
	void setColor(std::string color) {
		this->color = color;
	}
	void show() {
		std::cout << color << "������ (" << getX() << ", " << getY() << ")�� ��ġ�� ���Դϴ�.\n\n";
	}
};

int main() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();

	ColorPoint zeroPoint;
	zeroPoint.show();

	ColorPoint cp2(5, 5);
	cp2.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}*/
//5��, 6��
class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[]mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};
class MyQueue : public BaseArray{
	int num, _index;
public:
	MyQueue(int capacity) : BaseArray(capacity) { num = -1; _index = 0; }
	void enqueue(int n) {
		put(_index, n);
		_index++;
	}
	int capacity() {
		return getCapacity();
	}
	int length() {
		return _index;
	}
	int dequeue() {
		_index--;	
		num++;
		return get(num);
	}
};
class MyStack : public BaseArray {
	int num, _index;
public:
	MyStack(int capacity) : BaseArray(capacity) { _index = 0; }
	void push(int n) {
		put(_index, n);
		_index++;
	}
	int capacity() {
		return getCapacity();
	}
	int length() {
		return _index;
	}
	int pop() {
		_index--;
		return get(_index);
	}
};
int main() {
	MyQueue mQ(100);
	int n;
	std::cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		std::cin >> n;
		mQ.enqueue(n);
	}
	std::cout << "ť�� �뷮 : " << mQ.capacity() << ", ť�� ũ�� : " << mQ.length() << std::endl;
	std::cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�. ";
	while (mQ.length() != 0) {
		std::cout << mQ.dequeue() << ' ';
	}
	std::cout << std::endl << "ť�� ���� ũ�� : " << mQ.length() << std::endl;

	MyStack mStack(100);
	int n;
	std::cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		std::cin >> n;
		mStack.push(n);
	}
	std::cout << "���ÿ뷮 : " << mStack.capacity() << ", ���� ũ�� : " << mStack.length() << std::endl;
	std::cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>>";
	while (mStack.length() != 0) {
		std::cout << mStack.pop() << ' ';
	}
	std::cout << std::endl << "������ ���� ũ�� : " << mStack.length() << std::endl;
}