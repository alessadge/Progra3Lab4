#include "Pieza.h"

Pieza::Pieza(int pX,int pY, int pjugador)
{
	 x=pX;
	 y=pY;
	 jugador=pjugador;
}

	
int getJugador()
{
	return jugador; 
}

void setJugador(int tjugador)
{
	jugador=tjugador;
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