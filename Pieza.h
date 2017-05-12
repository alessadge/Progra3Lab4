#include <vector>
#include <string>

#ifndef PIEZA_H
#define PIEZA_H

using namespace std;

class Pieza
{
	protected:
		int x,y;



	public:
		//Pieza();
		Pieza(int,int);
	//	~Pieza();
	
	int getX();
	void setX(int);

	int getY();
	void setY(int);

};

#endif