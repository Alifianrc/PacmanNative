//aas 4210191028

#include "GhostsFactory.h"

InterfaceGhosts* GhostsFactory::CreateItem(int item, int i, int j) {
	InterfaceGhosts* product;

	switch (item)
	{
	case PINKY:
		product = new Pinky(i, j);
		break;
	case INKY:
		product = new Inky(i, j);
		break;
	default:
		return NULL;
		break;
	}

	return product;
}