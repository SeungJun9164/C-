#include<iostream>

using namespace std;

#include "SelectableRandom.h"

int main()
{
	SelectableRandom n;

	cout << "===========0����" << RAND_MAX << "������ ���� ¦�� ���� 10��===========" << endl;
	for (int i = 0; i < 10; i++)
		cout << n.next() << " ";
	cout << "\n===========2����9������ ���� Ȧ�� ���� 10��===========" << endl;
	for (int i = 0; i < 10; i++)
		cout << n.nextRange(2, 9) << " ";
}