#pragma once
// 4210191011   Muhammad Alifian Rizki C.

#include "Food.h"
#include "Fruit.h"

#define FOOD 1000
#define FRUIT 1001

class FactoryItem {
private:

public:
	static InterfaceItem *CreateItem(int item, int i, int j);
};