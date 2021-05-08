#pragma once
// 4210191011   Muhammad Alifian Rizki C.

#include <conio.h>
#include <Windows.h>
#include <list>
#include "Arena.h"
#include "Pacman.h"
#include "Player.h"
#include "FactoryItem.h"
#include "InterfaceItem.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class GameManager {
private:
	Arena* arena;
	Pacman* pacman;
	Player* player;
	std::list <InterfaceItem*> itemList;

	int GameUpdateSpeed;

	bool MainLoop;
	bool MenuLoop;
	bool GameLoop;

	int menuValue;

	bool FruitIsActive;
	int fruitEffectCount;

	char KeyboardInput();

	void MainMenu();
	void DrawMenu(int value);

	void NewGame();
	void InputPlayerName();
	void SetUpArena();
	void GenerateItem();

	void GameInput();
	void GameUpdate();
	void GamePause();

	void CheckCollision();

	void FruitEffect();

	void ArenaUpdate();

public:
	GameManager();
	
	void Play();
};