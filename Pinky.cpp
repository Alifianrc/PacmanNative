#include "Pinky.h"
//aas 4210191028

Pinky::Pinky() {
	positionI = 20;
	positionJ = 8;

	shape = "O";
}
Pinky::Pinky(int i, int j) {
	positionI = i;
	positionJ = j;

	shape = "O";
}

int Pinky::GetPositionI() {
	return positionI;
}
int Pinky::GetPositionJ() {
	return positionJ;
}
void Pinky::SetPosition(int i, int j) {
	positionI = i;
	positionJ = j;
}

void Pinky::Move(int i, int j) {
	// Movement AI
	if (MOVE_UP) {
		if (arena->GetArenaData(positionI - 1, positionJ) != "#") {
			positionI--;
		}
		else
		{
			MOVE_UP = false;
			MOVE_LEFT = true;
		}
	}
	else if (MOVE_DOWN) {
		if (arena->GetArenaData(positionI + 1, positionJ) != "#") {
			positionI++;
		}
		else
		{
			MOVE_DOWN = false;
			MOVE_RIGHT = true;
		}
	}
	else if (MOVE_LEFT) {
		if (arena->GetArenaData(positionI, positionJ - 1) != "#") {
			positionJ--;
		}
		else
		{
			MOVE_LEFT = false;
			MOVE_DOWN = true;
		}
	}
	else if (MOVE_RIGHT) {
		if (arena->GetArenaData(positionI, positionJ + 1) != "#") {
			positionJ++;
		}
		else
		{
			MOVE_RIGHT = false;
			MOVE_UP = true;
		}
	}
}

std::string Pinky::GetShape() {
	return shape;
}