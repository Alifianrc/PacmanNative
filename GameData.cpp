// 4210191011   Muhammad Alifian Rizki C.

#include "GameData.h"

GameData::GameData() {
	Arena = "<Arena>";
	ArenaEnd = "</Arena>";

	fileName = "GameData.txt";
	MAX = 1000;

	LoadData();
}

void GameData::LoadData() {
	std::ifstream file(fileName);
	if (!file) {
		std::cout << "Error In Opening File!!!\n";
		exit(0);
	}

	while (!file.eof()) {
		file.getline(temp, MAX);
		txtData = txtData + temp;
	}

	file.close();
}

std::string GameData::GetArenaData(int dataNumber) {
	int findFront = 0;

	findFront = txtData.find(Arena, findFront + 1) + Arena.size() + dataNumber;
	std::string data = txtData.substr(findFront, 1);

	return data;
}