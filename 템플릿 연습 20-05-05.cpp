#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

class Word {
	std::string kor;
	std::string eng;
public:
	Word(std::string kor,std::string eng) {
		this->kor = kor;
		this->eng = eng;
	}
	std::string getKor() { return kor; }
	std::string getEng() { return eng; }
};
int main() {
	std::vector<Word> v;
	v.push_back(Word("�ΰ�", "human"));
	v.push_back(Word("��ȸ", "society"));
	v.push_back(Word("����", "dall"));
	v.push_back(Word("����", "emotion"));
	v.push_back(Word("�׸�", "painting"));
	v.push_back(Word("�ŷ�", "trade"));
	v.push_back(Word("��", "bear"));
	v.push_back(Word("����", "duck"));
	v.push_back(Word("���", "apple"));

	std::string bogi[4] = { "" };
	std::string ans;
	int num;
	int number[4];

	std::cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4 �� �ٸ� �Է½� �����մϴ�.\n";
	while (1) {
		srand((unsigned)time(0));
		int ran = rand() % v.size();

		std::cout << v.at(ran).getEng() << "\n";
		int b_ran = rand() % 4;
		bogi[b_ran] = v.at(ran).getKor();
		ans = bogi[b_ran];

		for (int i = 0; i < 4; i++) {
			if (i != b_ran) {
				ran = rand() % v.size();
				bogi[i] = v.at(ran).getKor();
				for (int j = 0; j < i; j++) {
					if (bogi[j] == bogi[i]) i--;
				}
			}
		}
		
		for (int i = 0; i < 4; i++) {
			std::cout << "(" << i + 1 << ") " << bogi[i] << " ";
		}
		std::cout << ":> ";
		std::cin >> num;

		if (num <= 0 || num > 4)
			break;

		if (bogi[num - 1] == ans)
			std::cout << "Excellent!!\n";
		else
			std::cout << "No...!!\n";
		
	}
}