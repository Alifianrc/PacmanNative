#include "Pinky.h"
//aas 4210191028

Pinky::Pinky() {
	positionI = 5;
	positionJ = 5;

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

void Pinky::Move() {
	// Movement AI
}

std::string Pinky::GetShape() {
	return shape;
}