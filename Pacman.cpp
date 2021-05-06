// 4210191011   Muhammad Alfian Rizki C.

#include "Pacman.h"

Pacman::Pacman(Arena* source) {
	arena = source;

	position[0] = 1;
	position[1] = 1;

	shape = "@";

	MOVE_UP = false;
	MOVE_DOWN = false;
	MOVE_LEFT = false;
	MOVE_RIGHT = true;
}
Pacman::Pacman(Arena* source, int i, int j) {
	arena = source;

	position[0] = i;
	position[1] = j;

	shape = "@";

	MOVE_UP = false;
	MOVE_DOWN = false;
	MOVE_LEFT = false;
	MOVE_RIGHT = true;
}

int Pacman::GetPosition(int coord) {
	return position[coord];
}
void Pacman::SetPosition(int i, int j) {
	position[0] = i;
	position[1] = j;
}

void Pacman::ChangeDirection(int dir) {
	if (dir == UP) {
		MOVE_UP = true;
		MOVE_DOWN = false;
		MOVE_LEFT = false;
		MOVE_RIGHT = false;
	}
	else if (dir == DOWN) {
		MOVE_UP = false;
		MOVE_DOWN = true;
		MOVE_LEFT = false;
		MOVE_RIGHT = false;
	}
	else if (dir == LEFT) {
		MOVE_UP = false;
		MOVE_DOWN = false;
		MOVE_LEFT = true;
		MOVE_RIGHT = false;
	}
	else if (dir == RIGHT) {
		MOVE_UP = false;
		MOVE_DOWN = false;
		MOVE_LEFT = false;
		MOVE_RIGHT = true;
	}
}
void Pacman::Move() {
	if (MOVE_UP) {
		if (arena->GetArenaData(position[0] - 1, position[1]) != "#") {
			position[0]--;
		}
		else
		{
			MOVE_UP = false;
		}
	}
	else if (MOVE_DOWN) {
		if (arena->GetArenaData(position[0] + 1, position[1]) != "#") {
			position[0]++;
		}
		else
		{
			MOVE_DOWN = false;
		}
	}
	else if (MOVE_LEFT) {
		if (arena->GetArenaData(position[0], position[1] - 1) != "#") {
			position[1]--;
		}
		else
		{
			MOVE_LEFT = false;
		}
	}
	else if (MOVE_RIGHT) {
		if (arena->GetArenaData(position[0], position[1] + 1) != "#") {
			position[1]++;
		}
		else
		{
			MOVE_RIGHT = false;
		}
	}
}

std::string Pacman::GetShape() {
	return shape;
}