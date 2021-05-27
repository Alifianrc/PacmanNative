#include "Inky.h"
//aas 4210191028

Inky::Inky() {
	positionI = 21;
	positionJ = 8;

	shape = "Q";
}
Inky::Inky(Arena* arena, int i, int j, int move) {
	this->arena = arena;

	positionI = i;
	positionJ = j;

	shape = "Q";

	switch (move)
	{
	case 1:
		MOVE_UP = true;
		break;
	case 2:
		MOVE_DOWN = true;
		break;
	case 3:
		MOVE_LEFT = true;
		break;
	case 4:
		MOVE_RIGHT = true;
		break;
	default:
		break;
	}
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

void Inky::Move(int i, int j) {
	if (MOVE_UP) {
		if (arena->GetArenaData(positionI - 1, positionJ) != "#") {
			positionI--;
			if (RandomizeMovement() < 5) {
				if (arena->GetArenaData(positionI, positionJ - 1) == "." || arena->GetArenaData(positionI, positionJ - 1) == "*")
					MOVE_LEFT = true;
				else if (arena->GetArenaData(positionI, positionJ + 1) == "." || arena->GetArenaData(positionI, positionJ + 1) == "*")
					MOVE_RIGHT = true;
			}
		}
		else
		{
			MOVE_UP = false;
			if (arena->GetArenaData(positionI, positionJ - 1) == "." || arena->GetArenaData(positionI, positionJ - 1) == "*")
				MOVE_LEFT = true;
			else if (arena->GetArenaData(positionI, positionJ + 1) == "." || arena->GetArenaData(positionI, positionJ + 1) == "*")
				MOVE_RIGHT = true;
			else if (arena->GetArenaData(positionI + 1, positionJ) == "." || arena->GetArenaData(positionI + 1, positionJ) == "*")
				MOVE_DOWN = true;
		}
	}
	else if (MOVE_DOWN) {
		if (arena->GetArenaData(positionI + 1, positionJ) != "#") {
			positionI++; 
			if (RandomizeMovement() < 5) {
				if (arena->GetArenaData(positionI, positionJ - 1) == "." || arena->GetArenaData(positionI, positionJ - 1) == "*")
					MOVE_LEFT = true;
				else if (arena->GetArenaData(positionI, positionJ + 1) == "." || arena->GetArenaData(positionI, positionJ + 1) == "*")
					MOVE_RIGHT = true;
			}
		}
		else
		{
			MOVE_DOWN = false;
			if (arena->GetArenaData(positionI, positionJ - 1) == "." || arena->GetArenaData(positionI, positionJ - 1) == "*")
				MOVE_LEFT = true;
			else if (arena->GetArenaData(positionI, positionJ + 1) == "." || arena->GetArenaData(positionI, positionJ + 1) == "*")
				MOVE_RIGHT = true;
			else if (arena->GetArenaData(positionI - 1, positionJ) == "." || arena->GetArenaData(positionI - 1, positionJ) == "*")
				MOVE_UP = true;
		}
	}
	else if (MOVE_LEFT) {
		if (arena->GetArenaData(positionI, positionJ - 1) != "#") {
			positionJ--;
			if (RandomizeMovement() < 5) {
				if (arena->GetArenaData(positionI - 1, positionJ) == "." || arena->GetArenaData(positionI - 1, positionJ) == "*")
					MOVE_UP = true;
				else if (arena->GetArenaData(positionI + 1, positionJ) == "." || arena->GetArenaData(positionI + 1, positionJ) == "*")
					MOVE_DOWN = true;

			}
		}
		else
		{
			MOVE_LEFT = false;
			if (arena->GetArenaData(positionI - 1, positionJ) == "." || arena->GetArenaData(positionI - 1, positionJ) == "*")
				MOVE_UP = true;
			else if (arena->GetArenaData(positionI + 1, positionJ) == "." || arena->GetArenaData(positionI + 1, positionJ) == "*")
				MOVE_DOWN = true;
			else if (arena->GetArenaData(positionI, positionJ + 1) == "." || arena->GetArenaData(positionI, positionJ + 1) == "*")
				MOVE_RIGHT = true;
		}
	}
	else if (MOVE_RIGHT) {
		if (arena->GetArenaData(positionI, positionJ + 1) != "#") {
			positionJ++; 
			if (RandomizeMovement() < 5) {
				if (arena->GetArenaData(positionI - 1, positionJ) == "." || arena->GetArenaData(positionI - 1, positionJ) == "*")
					MOVE_UP = true;
				else if (arena->GetArenaData(positionI + 1, positionJ) == "." || arena->GetArenaData(positionI + 1, positionJ) == "*")
					MOVE_DOWN = true;
			}
		}
		else
		{
			MOVE_RIGHT = false;
			if (arena->GetArenaData(positionI - 1, positionJ) == "." || arena->GetArenaData(positionI - 1, positionJ) == "*")
				MOVE_UP = true;
			else if (arena->GetArenaData(positionI + 1, positionJ) == "." || arena->GetArenaData(positionI + 1, positionJ) == "*")
				MOVE_DOWN = true;
			else if (arena->GetArenaData(positionI, positionJ - 1) == "." || arena->GetArenaData(positionI, positionJ - 1) == "*")
				MOVE_LEFT = true;
		}
	}
}

int Inky::RandomizeMovement()
{
	randomize = 0;
	srand(time(0));
	randomize = rand() % 10;
	return randomize;
}
std::string Inky::GetShape() {
	return shape;
}