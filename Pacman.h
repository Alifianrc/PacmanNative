#pragma once
// 4210191011   Muhammad Alfian Rizki C.

#include <string>
#include "Arena.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class Pacman {
private:
	Arena* arena;

	int position[2];
	std::string shape;

	bool MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT;

public:
	Pacman(Arena* source);
	Pacman(Arena* source,int i, int j);

	int GetPosition(int coord);
	void SetPosition(int i, int j);

	void ChangeDirection(int dir);
	void Move();

	std::string GetShape();
};
