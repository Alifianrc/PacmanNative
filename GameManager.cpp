// 4210191011   Muhammad Alifian Rizki C.

#include "GameManager.h"

GameManager::GameManager() {
	arena = new Arena();
	pacman = new Pacman(arena);
	player = new Player();

	GameUpdateSpeed = 90;

	MainLoop = true;
	MenuLoop = true;
	GameLoop = false;

	menuValue = 0;

	FruitIsActive = false;
	fruitEffectCount = 0;

	DrawMenu(menuValue);
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

void GameManager::MainMenu() {
	char input = KeyboardInput();

	switch (input)
	{
	case KEY_UP:
	case 'w':
		menuValue--;
		if (menuValue < 0) {
			menuValue = 2;
		}
		DrawMenu(menuValue);
		break;
	case KEY_DOWN:
	case 's':
		menuValue++;
		if (menuValue > 2) {
			menuValue = 0;
		}
		DrawMenu(menuValue);
		break;
	case '\r':
		switch (menuValue)
		{
		case 0:
			//ResumeGame();
			menuValue = 0;
			break;
		case 1:
			NewGame();
			menuValue = 0;
			break;
		case 2:
			system("cls");
			exit(0);
			break;
		default:
			break;
		}
	default:
		break;
	}
}
void GameManager::DrawMenu(int value) {
	system("cls");
	switch (value)
	{
	case 0:
		std::cout << "     Resume <<<\n"
			<< "    New Game \n"
			<< "      Quit \n";
		break;
	case 1:
		std::cout << "     Resume \n"
			<< "    New Game <<<\n"
			<< "      Quit \n";
		break;
	case 2:
		std::cout << "     Resume \n"
			<< "    New Game \n"
			<< "      Quit <<<\n";
		break;
	default:
		break;
	}
}

void GameManager::NewGame() {
	InputPlayerName();

	SetUpArena();

	MenuLoop = false;
	GameLoop = true;
}
void GameManager::InputPlayerName() {
	system("cls");

	std::string name;
	std::cout << "\n         Input Player Name\n";
	std::cout << "     Name : "; std::cin >> name;

	player->SetName(name);
}
void GameManager::SetUpArena() {
	// Ghost

	arena->SetArenaData(pacman->GetPositionI(), pacman->GetPositionJ(), pacman->GetShape());

	GenerateItem();
}
void GameManager::GenerateItem() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < arena->GetArenaSizeI(); i++) {
		for (int j = 0; j < arena->GetArenaSizeJ(); j++) {
			if (arena->GetArenaData(i, j) == " ") {
				InterfaceItem *itemTemp;

				int temp = (rand() % 100) + 1;
				if (temp <= 2) {
					itemTemp = FactoryItem::CreateItem(FRUIT, i, j);
					itemList.push_back(itemTemp);
					arena->SetArenaData(i, j, itemTemp->GetShape());
				}
				else if (temp <= 15){
					itemTemp = FactoryItem::CreateItem(FOOD, i, j);
					itemList.push_back(itemTemp);
					arena->SetArenaData(i, j, itemTemp->GetShape());
				}
				// wall
			}
		}
	}
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
	case 'x' :
		GamePause();
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

	if (FruitIsActive) {
		FruitEffect();
	}

	ArenaUpdate();

	if (GameLoop) {
		arena->DrawArena(player->GetScore(), FruitIsActive);
	}

	Sleep(GameUpdateSpeed);
}
void GameManager::GamePause() {
	// Save Data here (optional)

	GameLoop = false;
	MenuLoop = true;

	menuValue = 0;
	DrawMenu(menuValue);
}

void GameManager::CheckCollision() {
	for (std::list<InterfaceItem*>::iterator iter = itemList.begin(); iter != itemList.end(); iter++) {
		InterfaceItem* temp = *iter;
		if (temp->GetPositionI() == pacman->GetPositionI() && temp->GetPositionJ() == pacman->GetPositionJ()) {
			if (temp->GetName() == "Food") {
				player->SetScore(player->GetScore() + 10);
			}
			else if (temp->GetName() == "Fruit") {
				FruitIsActive = true;
				fruitEffectCount = 0;
			}

			itemList.erase(iter);
			free(temp);
			break;
		}
	}

	// Ghosts
}

void GameManager::FruitEffect() {
	fruitEffectCount++;

	if (fruitEffectCount >= (arena->GetArenaSizeI() + arena->GetArenaSizeJ()) / 2) {
		FruitIsActive = false;
		fruitEffectCount = 0;
	}
}

void GameManager::ArenaUpdate() {
	for (int i = 0; i < arena->GetArenaSizeI(); i++) {
		for (int j = 0; j < arena->GetArenaSizeJ(); j++) {
			
			if (arena->GetArenaData(i, j) != "#") {
				arena->SetArenaData(i, j, " ");
			}

			for (std::list<InterfaceItem*>::iterator iter = itemList.begin(); iter != itemList.end(); iter++) {
				InterfaceItem* temp = *iter;
				if (temp->GetPositionI() == i && temp->GetPositionJ() == j) {
					arena->SetArenaData(i, j, temp->GetShape());
					break;
				}
			}

			if (pacman->GetPositionI() == i && pacman->GetPositionJ() == j) {
				arena->SetArenaData(i, j, pacman->GetShape());
			}

			// Ghosts			
		}
	}
}

void GameManager::Play() {
	while (MainLoop) {
		if (MenuLoop) {
			MainMenu();
		}
		else if (GameLoop) {
			GameUpdate();
		}
	}
}
