#include<iostream>

using namespace std;

#include "SelectableRandom.h"

int main()
{
	SelectableRandom n;

	cout << "===========0에서" << RAND_MAX << "까지의 랜덤 짝수 정수 10개===========" << endl;
	for (int i = 0; i < 10; i++)
		cout << n.next() << " ";
	cout << "\n===========2에서9까지의 랜덤 홀수 정수 10개===========" << endl;
	for (int i = 0; i < 10; i++)
		cout << n.nextRange(2, 9) << " ";
}