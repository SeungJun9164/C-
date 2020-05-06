#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

//1번
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

//2번
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
	
	if (equalArrays(x, y, 5)) std::cout << "같다\n";
	else std::cout << "다르다\n";

	if (equalArrays(a, b, 5)) std::cout << "같다\n";
	else std::cout << "다르다\n";
}*/

//3번
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

//4번
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

//5번
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
	n.setNation("한국", "서울");
	v.push_back(n);
	n.setNation("중국", "베이징");
	v.push_back(n);
	n.setNation("일본", "도쿄");
	v.push_back(n);
	n.setNation("베트남", "하노이");
	v.push_back(n);
	n.setNation("인도", "뉴델리");
	v.push_back(n);
	n.setNation("필리핀", "마닐라");
	v.push_back(n);
	n.setNation("타이", "방콕");
	v.push_back(n);
	n.setNation("몰디브", "몰레");
	v.push_back(n);
	n.setNation("미국", "워싱턴");
	v.push_back(n);

	int num;
	std::string na, ca, ans;
	srand((unsigned)time(0));
	bool check = false;


	std::cout << "*****나라의 수도 맞추기 게임을 시작합니다*****\n";
	while (1) {
		std::cout << "1 : 정보 입력 2 : 퀴즈 3 : 종료 ";
		std::cin >> num;
		if (num == 3)
			break;
		switch (num)
		{
		case 1:
			std::cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다.\n나라와 수도를 입력하세요(no no 이면 입력끝)\n";
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
				std::cout << v.at(ran).getNation() << "의 수도는 ? ";
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