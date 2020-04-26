//다중상속 : 하나의 파생클라스가 여러 클래스를 동시에 상속받는 것

#include<iostream>

/*class Adder {
protected:
	int add(int a, int b) { return a + b; }
};
class Subtractor {
protected:
	int minus(int a, int b) { return a - b; }
};
class Calculator :public Adder, public Subtractor { //다중상속 선언
public:
	int calc(char op, int a, int b) {
		int res = 0;
		switch (op)
		{
		case '+': res = add(a, b); break;
		case'-':res = minus(a, b); break;
		}
		return res;
	}
};

int main() {
	Calculator handCalculator;
	std::cout << "2 + 4 = " << handCalculator.calc('+', 2, 4) << std::endl;
	std::cout << "100 - 8 = " << handCalculator.calc('-', 100, 8) << std::endl;

	return 0;
}*/

/*다중상속의 문제점은
class BaseIO {
public:
	int mode;
};
class In :public BaseIO {
public:
	int readPos;
};
class Out :public BaseIO {
public:
	int writePos;
};
class InOut :public In, public Out {
public:
	bool safe;
};
int main() {
	InOut ioObj;
	ioObj.readPos = 10;
	ioObj.writePos = 20;
	ioObj.safe = true;
	ioObj.mode = 5; <<<<<<<<<<여기서 오류가 발생한다. mode가 In의 mode인지 Out의 mode인지 모호하기 때문이다. 
							  이러한 문제를 해결하려는 것이 가상상속 virtual
}*/

class BaseIO {
public:
	int mode;
};
class In : virtual public BaseIO {
public:
	int readPos;
};
class Out : virtual public BaseIO {
public:
	int writePos;
};
class InOut :public In, public Out {
public:
	bool safe;
};
int main() {
	InOut ioObj;
	ioObj.readPos = 10;
	ioObj.writePos = 20;
	ioObj.safe = true; 
	ioObj.mode = 5; 
}
virtual 키워드를 사용하면 파생 클래스의 객체가 생성될 떄 기본클래스의 멤버공간을 한번만 할당한다. 이미 할당되어 있으면 그 공간을 공유하도록 한다.