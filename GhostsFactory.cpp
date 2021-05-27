//aas 4210191028

#include "GhostsFactory.h"

InterfaceGhosts* GhostsFactory::CreateItem(Arena* arena, int item, int i, int j, int move) {
	InterfaceGhosts* product;

	switch (item)
	{
	case PINKY:
		product = new Pinky(arena, i, j, move);
		break;
	case INKY:
		product = new Inky(arena, i, j, move);
		break;
	default:
		return NULL;
		break;
	}

	return product;
}