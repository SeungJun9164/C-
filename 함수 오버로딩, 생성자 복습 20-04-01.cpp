#include<iostream>

typedef struct Animal {
	char name[30];
	int age;
	int health;
	int food;
	int clean;
}Animal;

void set_Animal(Animal *animal) {
	std::cout << "������ ���� �̸��� ���Ͻʽÿ�. ";
	std::cin >> animal->name;

	std::cout << animal->name << "���̸� ���Ͻʽÿ�. ";
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
	std::cout << animal->name << "�� �ǰ����� \n";
	std::cout << "���� :" << animal->age << "\n";
	std::cout << "ü�� :" << animal->health << "\n";
	std::cout << "����� :" << animal->food << "\n";
	std::cout << "û���� :" << animal->clean << "\n";
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
		std::cout << "1. ���� �߰�\n";
		std::cout << "2. ���\n";
		std::cout << "3. ���� ���� ����\n";
		std::cin >> Input;
		switch (Input) {
		case 1:
			list[cnt] = new Animal;
			set_Animal(list[cnt]);
			cnt++;
			break;
		case 2:
			std::cout << "�� ������ �����Ͻʽÿ�.\n";
			std::cin >> cnt_ani;
			if (cnt_ani < cnt) play(list[cnt_ani]);
			break;
		case 3:
			std::cout << "���¸� �� ������ �����Ͻʽÿ�.\n";
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