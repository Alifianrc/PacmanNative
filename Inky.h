#pragma once
#ifndef inky

#include "InterfaceGhosts.h"
#include "Arena.h"
#include <time.h>

//aas 4210191028

class Inky : public InterfaceGhosts {
private :
	Arena* arena;
	int positionI;
	int positionJ;
	int randomize;
	int speed;
	bool MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT;
	std::string shape;

public :
	Inky();
	Inky(Arena* arena,int i, int j, int move);

	int GetPositionI();
	int GetPositionJ();
	void SetPosition(int i, int j);
	int RandomizeMovement();
	void Move(int i, int j);

	std::string GetShape();
};

#endif