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
	v.push_back(Word("인간", "human"));
	v.push_back(Word("사회", "society"));
	v.push_back(Word("인형", "dall"));
	v.push_back(Word("감정", "emotion"));
	v.push_back(Word("그림", "painting"));
	v.push_back(Word("거래", "trade"));
	v.push_back(Word("곰", "bear"));
	v.push_back(Word("오리", "duck"));
	v.push_back(Word("사과", "apple"));

	std::string bogi[4] = { "" };
	std::string ans;
	int num;
	int number[4];

	std::cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료합니다.\n";
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