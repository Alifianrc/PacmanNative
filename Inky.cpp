#include "Inky.h"
//aas 4210191028

Inky::Inky() {
	positionI = 6;
	positionJ = 6;

	shape = "Q";
}
Inky::Inky(int i, int j) {
	positionI = i;
	positionJ = j;

	shape = "Q";
}

int Inky::GetPositionI() {
	return positionI;
}
int Inky::GetPositionJ() {
	return positionJ;
}
void Inky::SetPosition(int i, int j) {
	positionI = i;
	positionJ = j;
}

void Inky::Move() {
	// Movement AI
}

std::string Inky::GetShape() {
	return shape;
}