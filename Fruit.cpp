// 4210191011   Muhammad Alfian Rizki C.

#include "Fruit.h"

Fruit::Fruit() {
	position[0] = 3;
	position[1] = 3;

	shape = "^";
}
Fruit::Fruit(int i, int j) {
	position[0] = i;
	position[1] = j;

	shape = "^";
}

int Fruit::GetPositionI() {
	return position[0];
}
int Fruit::GetPositionJ() {
	return position[1];
}
void Fruit::SetPosition(int i, int j) {
	position[0] = i;
	position[1] = j;
}

std::string Fruit::GetShape() {
	return shape;
}

std::string Fruit::GetName() {
	return "Fruit";
}