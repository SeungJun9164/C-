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
//���� ������ protected �� ������ �˾ƺ��� ���� ������ 
//protected�� ������ Ŭ������ �Ļ�Ŭ���������� ��밡���ϴ�. 
//���� main�Լ����� ���������� ����ϴ°��� �Ұ���
//������ ������ �߻��ϴ� ���� p.x=5; / p.y=5; / cp.x=10; / cp.y=10;

//�Ļ�Ŭ�������� �����ڿ� �Ҹ��ڰ� �ִµ�, �Ļ�Ŭ������ ��ü�� ������ �� �⺻Ŭ������ �����ڰ� ���� ������ �� �Ļ�Ŭ������ �����ڰ� �����ȴ�.
//�⺻������->�Ļ������� ����
//�Ļ�Ŭ������ �����ڸ� ������ �� �Բ� ����� �⺻Ŭ������ �����ڸ� �������־�� �Ѵ�.
//������ �������������� ���������� �⺻Ŭ������ �⺻�����ڸ� ��������
//�����ؼ� �������ִ� ���� �� �����ڵ�
//�Ҹ��ڵ� ���������̴�. ������ �����ڿ� �ݴ�� �� �������� ������ �����ڰ� ����ó���� �Ҹ�ȴ�.

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
	WideTV(int size, bool videoIn) : TV(size) { //TVŬ������ TV(int size)�����ڸ� ��������
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
	std::cout << "videoIn=" << std::boolalpha << htv.getVideoIn() << std::endl; //std::boolalpha  : ���� true,false�� ��µǱ� ����
	std::cout << "Ip=" << htv.getIpAddr() << std::endl;
}*/

// public��� : �⺻Ŭ������ protected,public ������� ���� ���� ���� ���� �Ļ�Ŭ������ �״�� ���
// protected��� : �⺻Ŭ������ protected,public ������� protected�� ����Ǿ� �Ļ�Ŭ������ ���
// private��� : �⺻Ŭ������ protected,public ������� private�� ����Ǿ� �Ļ�Ŭ������ ���

//private���
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
//x.showB() �� ���� ��� ������ ����
//�Ļ�Ŭ�������� �⺻Ŭ������ private������� �Ͽ��� ������ �⺻Ŭ������ Base�� ��� private�� �ٲ� ���Ұ���
*/

//protected���
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
	x.a = 5; //a�� ���� private����̹Ƿ� ���ٺҰ���
	x.setA(10); //setA()�� protected����� ����Ǿ����� �ܺ��� main�Լ������� �Ұ���
	x.showA(10);//showA()�� protected����� ����Ǿ����� �ܺ��� main�Լ������� �Ұ���
	x.b = 10; //b�� ���� private����̹Ƿ� ���ٺҰ���
	x.setB(10);//setB()�� protected������� �ܺ��� main�Լ������� �Ұ���
	x.showB();////showB()�� public����̹Ƿ� ���� ������ �ȴ�.
}*/