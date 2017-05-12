#include "Pieza.h"

Pieza::Pieza(int pX,int pY)
{
	 x=pX;
	 y=pY;
}

int  Pieza::getX()
{
	return x;
}
void Pieza::setX(int tx)
{
	x=tx;
}

int Pieza::getY()
{
	return y;
}
void Pieza::setY(int tY)
{
	y=tY;
}