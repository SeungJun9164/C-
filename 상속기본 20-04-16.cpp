#include<iostream>

/*class Base {//���Ŭ����
	std::string s;
public:
	Base(std::string s = "���") { 
		std::cout << "��� Ŭ����" << std::endl; 
	}
	void what() {
		std::cout << s << std::endl;
	}

};
class Derived :public Base {//�Ļ�Ŭ��
	std::string s;
public:
	Derived(std::string s = "�Ļ�") {
		std::cout << "�Ļ� Ŭ����" << std::endl;

		what();
	}
};
int main() {
	std::cout << " === ��� Ŭ���� ���� ===" << std::endl;
	Base p;
	std::cout << " === �Ļ� Ŭ���� ���� ===" << std::endl;
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
//PointŬ������ x,y�� ColorPoint�� ��ӵ����� x, y�� PointŬ������ set,showPoint�� ��� �����ϴ�.
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
	//�� ĳ����
	//pBase�� Point������ * �̹Ƿ� ColorPoint���� �Ұ�
	//pBase�� pDer�� ����Ű��� ������ ���� �ִ� ���� �⺻Ŭ������ �͸� ��밡��
	//�Ļ�Ŭ���� �����Ͱ� �⺻Ŭ���� �����Ϳ� ġȯ
	//�Ļ�Ŭ���� �������� ����������� �ʿ��� ��� ���

	pDer->set(3, 4);
	pBase->showPoint();
	pDer->setColor("Red");
	pDer->showColorPoint();
	//pBase->showColorPoint(); �����Ͽ���, pBase�� �⺻Ŭ������ ���ٰ����ϹǷ�

	pDer = (ColorPoint*)pBase;
	//�ٿ� ĳ����
	//Ÿ�Ը�� �߿�
	//�⺻Ŭ������ �����Ͱ� ����Ű�� ��ü�� �Ļ�Ŭ������ �����ͷ� ����Ű�°�
	//�⺻Ŭ���� �����Ͱ� �Ļ�Ŭ���� �����Ϳ� ġȯ(����->�����, ������)
	//�ڽ� ��ü���� �ִ� ����Լ��� ȣ���� ��� ���
	//��ĳ������ ���� �ٽ� ������� ����
	//���� Ÿ���� �˰��־�� �ϴµ�, instanceof�����ڸ� ���� ����Ÿ���� �� �� �ִ�.
	pDer->setColor("Red");
	pDer->showColorPoint();
}

