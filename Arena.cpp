// 4210191011   Muhammad Alifian Rizki C.

#include "Arena.h"

Arena::Arena() {
	ArenaSizeI = 10;
	ArenaSizeJ = 40;
}
Arena::Arena(int sizeI, int sizeJ) {
	ArenaSizeI = sizeI;
	ArenaSizeJ = sizeJ;
}


int Arena::GetArenaSizeI() {
	return ArenaSizeI;
}
int Arena::GetArenaSizeJ() {
	return ArenaSizeJ;
}

std::string Arena::GetArenaData(int i, int j) {
	return ArenaData[i][j];
}
void Arena::SetArenaData(int i, int j, std::string shape) {
	ArenaData[i][j] = shape;
}

void Arena::DrawArena(int score, bool fruitIsActive, bool gameIsOver) {
	system("cls");

	std::cout << "\n";
	for (int i = 0; i < ArenaSizeJ / 2; i++) {
		std::cout << " ";
	}
	std::cout << "   " << "PACMAN THE GAME\n\n";

	for (int i = 0; i < ArenaSizeI; i++) {
		std::cout << "          ";

		for (int j = 0; j < ArenaSizeJ; j++) {
			std::cout << ArenaData[i][j];
		}

		if (i == (ArenaSizeI / 2) - 1) {
			std::cout << "   Score : " << score;
		}
		if (gameIsOver && i == ArenaSizeI/2) {
			std::cout << "   GAME OVER";
		}
		else if (fruitIsActive && i == ArenaSizeI / 2) {
			std::cout << "   Fruit Effect Is Active";
		}

		std::cout << "\n";
	}

	if (gameIsOver) {
		std::cout << "\n\n";
		for (int i = 0; i < (ArenaSizeJ / 2) - 2; i++) {
			std::cout << " ";
		}
		std::cout << "PRESS ENTER TO CONTINUE";
	}
}