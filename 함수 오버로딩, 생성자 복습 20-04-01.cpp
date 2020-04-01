#include<iostream>

typedef struct Animal {
	char name[30];
	int age;
	int health;
	int food;
	int clean;
}Animal;

void set_Animal(Animal *animal) {
	std::cout << "관리할 동물 이름을 정하십시오. ";
	std::cin >> animal->name;

	std::cout << animal->name << "나이를 정하십시오. ";
	std::cin >>  animal->age;

	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void play(Animal *animal) {
	animal->health += 20;
	animal->food -= 15;
	animal->clean -= 10;	
}
void show_set(Animal* animal) {
	std::cout << animal->name << "의 건강상태 \n";
	std::cout << "나이 :" << animal->age << "\n";
	std::cout << "체력 :" << animal->health << "\n";
	std::cout << "배고픔 :" << animal->food << "\n";
	std::cout << "청결함 :" << animal->clean << "\n";
}
void one_day_pass(Animal* animal) {
	animal->health -= 10;
	animal->food -= 10;
	animal->clean -= 5;
}

int main() {
	Animal* list[10];
	int Input, cnt = 0, cnt_ani = 0;
	while (1) {
		std::cout << "1. 동물 추가\n";
		std::cout << "2. 놀기\n";
		std::cout << "3. 동물 상태 보기\n";
		std::cin >> Input;
		switch (Input) {
		case 1:
			list[cnt] = new Animal;
			set_Animal(list[cnt]);
			cnt++;
			break;
		case 2:
			std::cout << "놀 동물을 선택하십시오.\n";
			std::cin >> cnt_ani;
			if (cnt_ani < cnt) play(list[cnt_ani]);
			break;
		case 3:
			std::cout << "상태를 볼 동물을 선택하십시오.\n";
			std::cin >> cnt_ani;
			if (cnt_ani < cnt) show_set(list[cnt_ani]);
			break;
		}
		for (int i = 0; i != cnt_ani; i++)
			one_day_pass(list[i]);
	}
	for (int i = 0; i < cnt_ani; i++)
		delete list[i];
	return 0;
}