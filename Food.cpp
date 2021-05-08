// 4210191011   Muhammad Alifian Rizki C.

#include "Food.h"

Food::Food() {
	position[0] = 3;
	position[1] = 3;

	shape = ".";
}
Food::Food(int i, int j) {
	position[0] = i;
	position[1] = j;

	shape = ".";
}

int Food::GetPositionI() {
	return position[0];
}
int Food::GetPositionJ() {
	return position[1];
}
void Food::SetPosition(int i, int j) {
	position[0] = i;
	position[1] = j;
}

std::string Food::GetShape() {
	return shape;
}

std::string Food::GetName() {
	return "Food";
}