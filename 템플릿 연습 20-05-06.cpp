#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

//1��
/*template <class T>
T biggest(T x[],int size) {
	x[size];
	T max;
	max = x[0];
	for (int i = 1; i < size; i++) {
		if (max < x[i])
			max = x[i];
	}
	return max;
}
int main() {
	int x[] = { 1,10,100,5,4 };
	double y[] = { 0.1,0.2,0.3,0.4,0.5 };
	std::cout << biggest(x, 5) << std::endl;
	std::cout << biggest(y, 5) << std::endl;
}*/

//2��
/*template <class T>
T equalArrays(T x[], T y[], int size) {	
	for (int i = 0; i < size; i++) {
		if (x[i] == y[i]) {
			if (i == (size - 1))
				return true;
			else
				continue;
		}
		else
			return false;
	}
}
int main() {
	int x[] = { 1,10,100,5,4 };
	int y[] = { 1,10,100,5,4 };
	double a[] = { 0.1,0.2,0.3,0.4,0.5 };
	double b[] = { 0.1,0.2,0.3,0.4,0.6 };
	
	if (equalArrays(x, y, 5)) std::cout << "����\n";
	else std::cout << "�ٸ���\n";

	if (equalArrays(a, b, 5)) std::cout << "����\n";
	else std::cout << "�ٸ���\n";
}*/

//3��
/*template<class T>
void reverseArray(T x[], int size) {
	T temp;
	for (int i = 0; i < size / 2; i++) {
		temp = x[i];
		x[i] = x[size - i - 1];
		x[size - i - 1] = temp;
	}
}
int main() {
	int x[] = { 1,10,100,5,4,8 };
	reverseArray(x, 6);
	for (int i = 0; i < 6; i++)
		std::cout << x[i] << ' ';
}*/

//4��
/*template<class T>
T *concat(T a[], T sizea, T b[], T sizeb) {
	T* sum = new T[sizea + sizeb];
	for (int i = 0; i < sizea; i++)
		sum[i] = a[i];
	for (int i = sizea; i < sizeb + sizea; i++)
		sum[i] = b[i - sizea];
	return sum;
}
int main() {
	int x[] = { 1,2,3,4,5 };
	int y[] = { 6,7,8,9 };
	int* a = concat(x, 5, y, 4);
	for (int i = 0; i < 9; i++)
		std::cout << a[i] << ' ';
}*/

//5��
class Nation {
	std::string nation;
	std::string capital;
public:
	Nation() { ; }
	void setNation(std::string nation, std::string capital) {
		this->nation = nation; this->capital = capital;
	}
	std::string getNation() { return nation; }
	std::string getCapital() { return capital; }
};

int main() {
	std::vector<Nation> v;
	Nation n;
	n.setNation("�ѱ�", "����");
	v.push_back(n);
	n.setNation("�߱�", "����¡");
	v.push_back(n);
	n.setNation("�Ϻ�", "����");
	v.push_back(n);
	n.setNation("��Ʈ��", "�ϳ���");
	v.push_back(n);
	n.setNation("�ε�", "������");
	v.push_back(n);
	n.setNation("�ʸ���", "���Ҷ�");
	v.push_back(n);
	n.setNation("Ÿ��", "����");
	v.push_back(n);
	n.setNation("�����", "����");
	v.push_back(n);
	n.setNation("�̱�", "������");
	v.push_back(n);

	int num;
	std::string na, ca, ans;
	srand((unsigned)time(0));
	bool check = false;


	std::cout << "*****������ ���� ���߱� ������ �����մϴ�*****\n";
	while (1) {
		std::cout << "1 : ���� �Է� 2 : ���� 3 : ���� ";
		std::cin >> num;
		if (num == 3)
			break;
		switch (num)
		{
		case 1:
			std::cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�.\n����� ������ �Է��ϼ���(no no �̸� �Է³�)\n";
			while (1) {
				check = false;
				std::cout << v.size() + 1 << ">>";
				std::cin >> na >> ca;
				if (na == "no" && ca == "no") break;
				for (int i = 0; i < v.size(); i++) {
					if (na == v.at(i).getNation()) {
						std::cout << "already exists!!\n";
						check = true;
						break;
					}
				}	
				if (check == false) {
					n.setNation(na, ca);
					v.push_back(n);
				}
			}
			break;
		case 2:
			while (1) {
				int ran = rand() % v.size();
				std::cout << v.at(ran).getNation() << "�� ������ ? ";
				std::cin >> ans;
				if (ans == "exit" || ans == "EXIT")
					break;
				if (ans == v.at(ran).getCapital())
					std::cout << "Correct!\n";
				else
					std::cout << "NO!\n";
			}
			break;
		case 3:
			break;
		default:
			break;
		}
	}
}