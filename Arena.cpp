// 4210191011   Muhammad Alfian Rizki C.

#include "Arena.h"

Arena::Arena() {
	ArenaSizeI = 20;
	ArenaSizeJ = 80;

	for (int i = 0; i < ArenaSizeI; i++) {
		for (int j = 0; j < ArenaSizeJ; j++) {
			if (i == 0 || i == (ArenaSizeI - 1)) {
				ArenaData[i][j] = "#";
			}
			else if (j == 0 || j == (ArenaSizeJ - 1)) {
				ArenaData[i][j] = "#";
			}
			else {
				ArenaData[i][j] = " ";
			}
		}
	}
}
Arena::Arena(int sizeI, int sizeJ) {
	ArenaSizeI = sizeI;
	ArenaSizeJ = sizeJ;

	for (int i = 0; i < ArenaSizeI; i++) {
		for (int j = 0; j < ArenaSizeJ; j++) {
			if (i == 0 || i == (ArenaSizeI - 1)) {
				ArenaData[i][j] = "#";
			}
			else if (j == 0 || j == (ArenaSizeJ - 1)) {
				ArenaData[i][j] = "#";
			}
			else {
				ArenaData[i][j] = " ";
			}
		}
	}
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

void Arena::DrawArena() {
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
		std::cout << "\n";
	}
}