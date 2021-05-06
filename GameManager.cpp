// 4210191011   Muhammad Alfian Rizki C.

#include "GameManager.h"

GameManager::GameManager() {
	arena = new Arena();
	pacman = new Pacman(arena);

	GameUpdateSpeed = 200;

	score = 0;

	GameIsOver = false;
}

char GameManager::KeyboardInput() {
	char theInput;
	if (_kbhit()) {
		theInput = _getch();
	}
	else {
		theInput = NULL;
	}
	return theInput;
}

void GameManager::GameInput() {
	char input = KeyboardInput();

	switch (input)
	{
	case KEY_UP:
	case 'w':
		pacman->ChangeDirection(UP);
		break;

	case KEY_DOWN:
	case 's':
		pacman->ChangeDirection(DOWN);
		break;

	case KEY_LEFT:
	case 'a':
		pacman->ChangeDirection(LEFT);
		break;

	case KEY_RIGHT:
	case 'd':
		pacman->ChangeDirection(RIGHT);
		break;

	default:
		break;
	}
}
void GameManager::GameUpdate() {
	GameInput();
	pacman->Move();
	// ghosts->move();
	CheckCollision();

	ArenaUpdate();

	arena->DrawArena();

	Sleep(GameUpdateSpeed);
}

void GameManager::CheckCollision() {

}

void GameManager::ArenaUpdate() {
	for (int i = 0; i < arena->GetArenaSizeI(); i++) {
		for (int j = 0; j < arena->GetArenaSizeJ(); j++) {
			// Ghosts first

			if (pacman->GetPosition(0) == i && pacman->GetPosition(1) == j) {
				arena->SetArenaData(i, j, pacman->GetShape());
			}

			// Fruit and Food here

			else if (i != 0 && i != arena->GetArenaSizeI() - 1 && j != 0 && j != arena->GetArenaSizeJ() - 1) {
				arena->SetArenaData(i, j, " ");
			}
		}
	}
}


void GameManager::Play() {
	while (!GameIsOver) {
		GameUpdate();
	}
}
