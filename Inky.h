#pragma once
#ifndef inky
#define inky
#include "GhostFactory.h"
//aas 4210191028

class Inky {
private :
	int positionI;
	int positionJ;

	int speed;

	std::string shape;

public :
	Inky();
	Inky(int i, int j);

	int GetPositionI();
	int GetPositionJ();
	void SetPosition(int i, int j);

	void Move();

	std::string GetShape();
};

#endif