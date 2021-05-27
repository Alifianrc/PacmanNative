#include "Pinky.h"
//aas 4210191028

Pinky::Pinky() {
	positionI = 20;
	positionJ = 8;

	shape = "O";
}
Pinky::Pinky(Arena* arena, int i, int j, int move) {
	this->arena = arena;

	positionI = i;
	positionJ = j;

	shape = "O";

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

void Pinky::Move(int i, int j) {
	if (MOVE_UP) {
		if (arena->GetArenaData(positionI - 1, positionJ) != "#") {
			positionI--;
			if (RandomizeMovement() < 5) {
				if (arena->GetArenaData(positionI, positionJ - 1) != "#") {
					MOVE_LEFT = true;
					positionJ--;
					return;
				}
				else if (arena->GetArenaData(positionI, positionJ + 1) != "#") {
					MOVE_RIGHT = true;
					positionJ++;
					return;
				}
			}
		}
		else
		{
			MOVE_UP = false;
				if (arena->GetArenaData(positionI, positionJ + 1) != "#") {
					MOVE_RIGHT = true;
					positionJ++;
					return;
				}
				else if (arena->GetArenaData(positionI + 1, positionJ) != "#") {
					MOVE_DOWN = true;
					positionI++;
					return;
				}
				else if (arena->GetArenaData(positionI, positionJ - 1) != "#") {
					MOVE_LEFT = true;
					positionJ--;
					return;
				}
		}
	}
	else if (MOVE_DOWN) {
		if (arena->GetArenaData(positionI + 1, positionJ) != "#") {
			positionI++;
			if (RandomizeMovement() < 5) {
				if (arena->GetArenaData(positionI, positionJ + 1) != "#") {
					MOVE_RIGHT = true;
					positionJ++;
					return;
				}
				else if (arena->GetArenaData(positionI, positionJ - 1) != "#") {
					MOVE_LEFT = true;
					positionJ--;
					return;
				}	
			}
		}
		else
		{
			MOVE_DOWN = false;
			if (arena->GetArenaData(positionI, positionJ - 1) != "#") {
				MOVE_LEFT = true;
				positionJ--;
				return;
			}
			else if (arena->GetArenaData(positionI - 1, positionJ) != "#") {
				MOVE_UP = true;
				positionI--;
				return;
			}
			else if (arena->GetArenaData(positionI, positionJ + 1) != "#") {
				MOVE_RIGHT = true;
				positionJ++;
				return;
			}
		}
	}
	else if (MOVE_LEFT) {
		if (arena->GetArenaData(positionI, positionJ - 1) != "#") {
			positionJ--;
			if (RandomizeMovement() < 5) {
				if (arena->GetArenaData(positionI - 1, positionJ) != "#") {
					MOVE_UP = true;
					positionI--;
					return;
				}

				else if (arena->GetArenaData(positionI + 1, positionJ) != "#") {
					MOVE_DOWN = true;
					positionI++;
					return;
				}
			}
		}
		else
		{
			MOVE_LEFT = false;
			
			if (arena->GetArenaData(positionI - 1, positionJ) != "#") {
				MOVE_UP = true;
				positionI--;
				return;
			}

			else if (arena->GetArenaData(positionI + 1, positionJ) != "#") {
				MOVE_DOWN = true;
				positionI++;
				return;
			}

			else if (arena->GetArenaData(positionI, positionJ + 1) != "#") {
				MOVE_RIGHT = true;
				positionJ++;
				return;
			}
		}
	}
	else if (MOVE_RIGHT) {
		if (arena->GetArenaData(positionI, positionJ + 1) != "#") {
			positionJ++;
			if (RandomizeMovement() < 5) {
				if (arena->GetArenaData(positionI + 1, positionJ) != "#") {
					MOVE_DOWN = true;
					positionI++;
					return;
				}
				else if (arena->GetArenaData(positionI - 1, positionJ) != "#") {
					MOVE_UP = true;
					positionI--;
					return;
				}
			}
		}
		else
		{
			MOVE_RIGHT = false;
			
			if (arena->GetArenaData(positionI - 1, positionJ) != "#") {
				MOVE_UP = true;
				positionI--;
				return;
			}

			else if (arena->GetArenaData(positionI + 1, positionJ) != "#") {
				MOVE_DOWN = true;
				positionI++;
				return;
			}

			else if (arena->GetArenaData(positionI, positionJ - 1) != "#") {
				MOVE_LEFT = true;
				positionJ--;
				return;
			}
		}
	}
}

int Pinky::RandomizeMovement()
{
	randomize = 0;
	srand(time(0));
	randomize = rand() % 10;
	return randomize;
}


std::string Pinky::GetShape() {
	return shape;
}