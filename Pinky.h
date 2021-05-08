#pragma once
#ifndef pinky
#define pinky
#include "GhostFactory.h"
//aas 4210191028

class Pinky {
private:
	int positionI;
	int positionJ;

	int speed;

	std::string shape;

public:
	Pinky();
	Pinky(int i, int j);

	int GetPositionI();
	int GetPositionJ();
	void SetPosition(int i, int j);

	void Move();

	std::string GetShape();
};

#endif
