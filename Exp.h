#pragma once
class Exp
{
private:
	int base;
	int index;
public:
	Exp();
	Exp(int b, int i);
	Exp(int b);
	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp b);
	~Exp();
};


