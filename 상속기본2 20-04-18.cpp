#include<iostream>


/*class Point {
protected:
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() { std::cout << "(" << x << "," << y << ")" << std::endl; }
};

class ColorPoint : public Point{
	std::string color;
public:
	void setColor(std::string color) { this->color = color; }
	void showColorPoint() {
		std::cout << color << " : ";
		showPoint();
	}
	bool equals(ColorPoint p) {
		if (x == p.x && y == p.y && color == p.color)
			return true;
		else
			return false;
	}
};
int main() {
	Point p;
	p.set(2, 3);
	p.x = 5;
	p.y = 5;
	p.showPoint();

	ColorPoint cp;
	cp.x = 10;
	cp.y = 10;
	cp.set(3, 4);
	cp.setColor("Red");

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");
	std::cout << ((cp.equals(cp2)) ? "true" : "flase");
}*/
//접근 지정자 protected 의 범위를 알아보기 위한 문제로 
//protected는 선언한 클래스와 파생클래스에서만 사용가능하다. 
//따라서 main함수에서 직접적으로 사용하는것은 불가능
//컴파일 오류가 발생하는 곳은 p.x=5; / p.y=5; / cp.x=10; / cp.y=10;

//파생클래스에도 생성자와 소멸자가 있는데, 파생클래스의 객체가 생성될 때 기본클래스의 생성자가 먼저 생성된 후 파생클래스의 생성자가 생성된다.
//기본생성자->파생생성자 순서
//파생클래스의 생성자를 생성할 때 함께 실행될 기본클래스의 생성자를 지정해주어야 한다.
//하지만 지정하지않으면 묵시적으로 기본클래스의 기본생성자를 실행해줌
//선택해서 지정해주는 경우는 밑 예제코드
//소멸자도 마찬가지이다. 하지만 생성자와 반대로 맨 마지막에 생성된 생성자가 제일처음에 소멸된다.

/*class TV {
	int size;
public:
	TV() { size = 20; }
	TV(int size) { this->size = size; }
	int getSize() { return size; }
};
class WideTV : public TV {
	bool videoIn;
public:
	WideTV(int size, bool videoIn) : TV(size) { //TV클래스의 TV(int size)생성자를 지정해줌
		this->videoIn = videoIn;
	}
	bool getVideoIn() { return videoIn; }
};
class SmartTV :public WideTV {
	std::string ipAddr;
public:
	SmartTV(std::string ipAddr, int size) :WideTV(size, true) {
		this->ipAddr = ipAddr;
	}
	std::string getIpAddr() { return ipAddr; }
};
int main() {
	SmartTV htv("192,0,0,1", 32);
	std::cout << "size=" << htv.getSize() << std::endl;
	std::cout << "videoIn=" << std::boolalpha << htv.getVideoIn() << std::endl; //std::boolalpha  : 값을 true,false로 출력되기 해줌
	std::cout << "Ip=" << htv.getIpAddr() << std::endl;
}*/

// public상속 : 기본클래스의 protected,public 멤버들은 접근 지정 변경 없이 파생클래스의 그대로 상속
// protected상속 : 기본클래스의 protected,public 멤버들은 protected로 변경되어 파생클래스에 상속
// private상속 : 기본클래스의 protected,public 멤버들은 private로 변경되어 파생클래스에 상속

//private상속
/*class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { std::cout << a; }
};
class Derived :private Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() { std::cout << b; }
};
int main() {
	Derived x;
	x.a = 5;
	x.setA(10);
	x.showA(10);
	x.b = 10;
	x.setB(10);
	x.showB();
}
//x.showB() 만 빼고 모두 컴파일 오류
//파생클래스에서 기본클래스를 private상속으로 하였기 때문에 기본클래스인 Base는 모두 private로 바뀌어서 사용불가능
*/

//protected상속
/*class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { std::cout << a; }
};
class Derived :protected Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() { std::cout << b; }
};
int main() {
	Derived x;
	x.a = 5; //a는 원래 private멤버이므로 접근불가능
	x.setA(10); //setA()가 protected멤버로 변경되었지만 외부인 main함수에서는 불가능
	x.showA(10);//showA()가 protected멤버로 변경되었지만 외부인 main함수에서는 불가능
	x.b = 10; //b는 원래 private멤버이므로 접근불가능
	x.setB(10);//setB()는 protected멤버여서 외부인 main함수에서는 불가능
	x.showB();////showB()는 public멤버이므로 정상 컴파일 된다.
}*/