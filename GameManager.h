#pragma once
// 4210191011   Muhammad Alfian Rizki C.

#include <conio.h>
#include <Windows.h>
#include "Arena.h"
#include "Pacman.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class GameManager {
private:
	Arena* arena;
	Pacman* pacman;

	int GameUpdateSpeed;

	int score;

	bool GameIsOver;

	char KeyboardInput();

	void GameInput();
	void GameUpdate();

	void CheckCollision();

	void ArenaUpdate();

public:
	GameManager();
	
	void Play();
};