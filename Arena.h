#pragma once
// 4210191011   Muhammad Alfian Rizki C.

#include <iostream>

class Arena {
private:
	int ArenaSizeI;
	int ArenaSizeJ;
	std::string ArenaData[100][100];

public:
	Arena();
	Arena(int sizeI, int sizeJ);

	int GetArenaSizeI();
	int GetArenaSizeJ();

	std::string GetArenaData(int i, int j);
	void SetArenaData(int i, int j, std::string shape);

	void DrawArena();
};