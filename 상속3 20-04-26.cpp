//���߻�� : �ϳ��� �Ļ�Ŭ�󽺰� ���� Ŭ������ ���ÿ� ��ӹ޴� ��

#include<iostream>

/*class Adder {
protected:
	int add(int a, int b) { return a + b; }
};
class Subtractor {
protected:
	int minus(int a, int b) { return a - b; }
};
class Calculator :public Adder, public Subtractor { //���߻�� ����
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

/*���߻���� ��������
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
	ioObj.mode = 5; <<<<<<<<<<���⼭ ������ �߻��Ѵ�. mode�� In�� mode���� Out�� mode���� ��ȣ�ϱ� �����̴�. 
							  �̷��� ������ �ذ��Ϸ��� ���� ������ virtual
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
virtual Ű���带 ����ϸ� �Ļ� Ŭ������ ��ü�� ������ �� �⺻Ŭ������ ��������� �ѹ��� �Ҵ��Ѵ�. �̹� �Ҵ�Ǿ� ������ �� ������ �����ϵ��� �Ѵ�.