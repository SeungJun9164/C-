#include "Exp.h"

Exp::Exp()
{
	base = index = 1;
}
Exp::Exp(int b, int i)
{
	base = b;
	index = i;
}
Exp::Exp(int b)
{
	base = b;
	index = 1;
}

int Exp::getValue()
{	
	int mul = 1;
	for (int j = 0; j < index; j++)
		mul *= base;
	return mul;
}

int Exp::getBase()
{
	return base;
}
int Exp::getExp()
{
	return index;
}

bool Exp::equals(Exp b)
{
	if (getValue() == b.getValue())
		return 1;
	else
		return false;
}
Exp::~Exp()
{

}