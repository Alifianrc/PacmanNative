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
#include "GhostsFactory.h"
#include "InterfaceGhosts.h"
#include "GameData.h"

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
	std::list <InterfaceGhosts*> ghostList;
	GameData* data;

	int GameUpdateSpeed;

	bool MainLoop;
	bool MenuLoop;
	bool GameLoop;

	int menuValue;

	int foodCount;
	int fruitMax;
	bool FruitIsActive;
	int fruitEffectCount;

	bool GameIsOver;

	char KeyboardInput();

	void MainMenu();
	void DrawMenu(int value);

	void NewGame();
	void InputPlayerName();
	void SetUpArena();
	void GenerateGhosts();
	void GenerateItem();

	void GameInput();
	void GameUpdate();
	void GamePause();

	void CheckCollision();

	void FruitEffect();

	void ArenaUpdate();

	void GameOver();

public:
	GameManager();
	
	void Play();
};