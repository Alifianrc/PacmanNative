#pragma once
// 4210191011   Muhammad Alifian Rizki C.

#include <string>
#include "InterfaceItem.h"

class Fruit : public InterfaceItem {
private:
	int position[2];
	std::string shape;

public:
	Fruit();
	Fruit(int i, int j);

	int GetPositionI();
	int GetPositionJ();
	void SetPosition(int i, int j);

	std::string GetShape();
	std::string GetName();
};