#pragma once
// 4210191011   Muhammad Alifian Rizki C.

#include <string>
#include <fstream>
#include <iostream>

class GameData {
private:
	std::string Arena, ArenaEnd;

	std::string fileName, txtData;
	int MAX;
	char temp[1000];

	void LoadData();

public:
	GameData();

	std::string GetArenaData(int dataNumber);
};