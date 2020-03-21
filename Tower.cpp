#include "Tower.h"

Tower::Tower()
{
	h = 1;
}
Tower::Tower(int m)
{
	h = m;
}
int Tower::getHeight()
{
	return h;
}