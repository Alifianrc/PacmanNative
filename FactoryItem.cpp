// 4210191011   Muhammad Alifian Rizki C.

#include "FactoryItem.h"

InterfaceItem* FactoryItem::CreateItem(int item, int i, int j) {
	InterfaceItem *product;

	switch (item)
	{
	case FOOD:
		product = new Food(i, j);
		break;
	case FRUIT:
		product = new Fruit(i, j);
		break;
	default:
		return NULL;
		break;
	}

	return product;
}