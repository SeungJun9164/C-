#include<iostream>

/*class Base {//기반클래스
	std::string s;
public:
	Base(std::string s = "기반") { 
		std::cout << "기반 클래스" << std::endl; 
	}
	void what() {
		std::cout << s << std::endl;
	}

};
class Derived :public Base {//파생클라스
	std::string s;
public:
	Derived(std::string s = "파생") {
		std::cout << "파생 클래스" << std::endl;

		what();
	}
};
int main() {
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;
	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;

	return 0;
}*/

class Point {
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		std::cout << x << "," << y << std::endl;
	}
};
//Point클래스의 x,y는 ColorPoint에 상속되지만 x, y는 Point클래스의 set,showPoint만 사용 가능하다.
class ColorPoint :public Point {
	std::string color;
public:
	void setColor(std::string color) { this->color = color; }
	void showColorPoint() {
		std::cout << color << " : ";
		showPoint();
	}
};
int main() {
	/*Point p;
	ColorPoint cp;
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();*/
	ColorPoint cp;
	ColorPoint* pDer = &cp;
	Point* pBase = pDer; 
	//업 캐스팅
	//pBase는 Point형식의 * 이므로 ColorPoint접근 불가
	//pBase는 pDer를 가르키고는 있지만 쓸수 있는 것은 기본클래스의 것만 사용가능
	//파생클래스 포인터가 기본클래스 포인터에 치환
	//파생클래스 여러개중 공통된형식이 필요할 경우 사용

	pDer->set(3, 4);
	pBase->showPoint();
	pDer->setColor("Red");
	pDer->showColorPoint();
	//pBase->showColorPoint(); 컴파일오류, pBase는 기본클래스만 접근가능하므로

	pDer = (ColorPoint*)pBase;
	//다운 캐스팅
	//타입명시 중요
	//기본클래스의 포인터가 가리키는 객체를 파생클래스의 포인터로 가리키는것
	//기본클래스 포인터가 파생클래스 포인터에 치환(생물->고양이, 강아지)
	//자식 객체에만 있는 멤버함수를 호출할 경우 사용
	//업캐스팅한 것을 다시 원래대로 복구
	//원래 타입을 알고있어야 하는데, instanceof연산자를 쓰면 원래타입을 알 수 있다.
	pDer->setColor("Red");
	pDer->showColorPoint();
}

