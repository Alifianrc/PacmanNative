// 4210191011   Muhammad Alifian Rizki C.

#include "GameManager.h"

GameManager::GameManager() {
	arena = new Arena();
	pacman = new Pacman(arena);
	player = new Player();
	data = new GameData();

	GameUpdateSpeed = 300;

	MainLoop = true;
	MenuLoop = true;
	GameLoop = false;

	menuValue = 0;

	foodCount = 0;
	fruitMax = 6;
	FruitIsActive = false;
	fruitEffectCount = 0;

	GameIsOver = false;

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
	GameIsOver = false;

	if (!itemList.empty()) {
		itemList.clear();
	}
	if (!ghostList.empty()) {
		ghostList.clear();
	}

	pacman->ChangeDirection(RIGHT);

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
	int count = 0;
	for (int i = 0; i < arena->GetArenaSizeI(); i++) {
		for (int j = 0; j < arena->GetArenaSizeJ(); j++) {
			arena->SetArenaData(i, j, data->GetArenaData(count));
			count++;
		}
	}

	GenerateGhosts();

	pacman->SetPosition(1, 1);
	arena->SetArenaData(pacman->GetPositionI(), pacman->GetPositionJ(), pacman->GetShape());

	GenerateItem();
}
void GameManager::GenerateGhosts() {
	InterfaceGhosts* ghostTemp;

	ghostTemp = GhostsFactory::CreateItem(PINKY, 6, 20, 4);
	ghostList.push_back(ghostTemp);
	arena->SetArenaData(ghostTemp->GetPositionI(), ghostTemp->GetPositionJ(), ghostTemp->GetShape());
	ghostTemp = GhostsFactory::CreateItem(PINKY, 5, 20, 3);
	ghostList.push_back(ghostTemp);
	arena->SetArenaData(ghostTemp->GetPositionI(), ghostTemp->GetPositionJ(), ghostTemp->GetShape());

	ghostTemp = GhostsFactory::CreateItem(INKY, 6, 21, 4);
	ghostList.push_back(ghostTemp);
	arena->SetArenaData(ghostTemp->GetPositionI(), ghostTemp->GetPositionJ(), ghostTemp->GetShape());
	ghostTemp = GhostsFactory::CreateItem(INKY, 5, 21, 3);
	ghostList.push_back(ghostTemp);
	arena->SetArenaData(ghostTemp->GetPositionI(), ghostTemp->GetPositionJ(), ghostTemp->GetShape());
}
void GameManager::GenerateItem() {
	srand((unsigned)time(NULL));
	int fruitCount = 0;
	for (int i = 0; i < arena->GetArenaSizeI(); i++) {
		for (int j = 0; j < arena->GetArenaSizeJ(); j++) {
			if (arena->GetArenaData(i, j) == " ") {
				InterfaceItem *itemTemp;

				int temp = (rand() % 100) + 1;
				if (temp <= 7 && fruitCount <= fruitMax) {
					itemTemp = FactoryItem::CreateItem(FRUIT, i, j);
					fruitCount++;
				}
				else {
					itemTemp = FactoryItem::CreateItem(FOOD, i, j);
					foodCount++;
				}
				
				itemList.push_back(itemTemp);
				arena->SetArenaData(i, j, itemTemp->GetShape());
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
	
	if (!ghostList.empty()) {
		for (std::list<InterfaceGhosts*>::iterator iter = ghostList.begin(); iter != ghostList.end(); iter++) {
			InterfaceGhosts* temp = *iter;
			temp->Move(0, 0);
		}
	}
	
	CheckCollision();

	if (FruitIsActive) {
		FruitEffect();
	}

	ArenaUpdate();

	if (GameLoop || GameIsOver) {
		arena->DrawArena(player->GetScore(), FruitIsActive, GameIsOver);
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
	if (!itemList.empty()) {
		for (std::list<InterfaceItem*>::iterator iter = itemList.begin(); iter != itemList.end(); iter++) {
			InterfaceItem* temp = *iter;
			if (temp->GetPositionI() == pacman->GetPositionI() && temp->GetPositionJ() == pacman->GetPositionJ()) {
				if (temp->GetName() == "Food") {
					player->SetScore(player->GetScore() + 10);
					foodCount--;
				}
				else if (temp->GetName() == "Fruit") {
					FruitIsActive = true;
					fruitEffectCount = 0;
				}

				itemList.erase(iter);
				free(temp);

				if (foodCount <= 0) {
					GameOver();
				}
				break;
			}
		}
	}
	
	if (!ghostList.empty()) {
		for (std::list<InterfaceGhosts*>::iterator iter = ghostList.begin(); iter != ghostList.end(); iter++) {
			InterfaceGhosts* temp = *iter;
			if (temp->GetPositionI() == pacman->GetPositionI() && temp->GetPositionJ() == pacman->GetPositionJ()) {
				if (FruitIsActive) {
					if (arena->GetArenaData(6, 20) == " ") {
						temp->SetPosition(6, 20);
					}
					else if (arena->GetArenaData(6, 21) == " ") {
						temp->SetPosition(6, 21);
					}
					else if (arena->GetArenaData(5, 20) == " ") {
						temp->SetPosition(5, 20);
					}
					else if (arena->GetArenaData(5, 21) == " ") {
						temp->SetPosition(5, 21);
					}

					player->SetScore(player->GetScore() + 50);
				}
				else {
					GameOver();
				}
			}
		}
	}
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

			if (!itemList.empty()) {
				for (std::list<InterfaceItem*>::iterator iter = itemList.begin(); iter != itemList.end(); iter++) {
					InterfaceItem* temp = *iter;
					if (temp->GetPositionI() == i && temp->GetPositionJ() == j) {
						arena->SetArenaData(i, j, temp->GetShape());
						break;
					}
				}
			}

			if (pacman->GetPositionI() == i && pacman->GetPositionJ() == j) {
				arena->SetArenaData(i, j, pacman->GetShape());
			}

			if (!ghostList.empty()) {
				for (std::list<InterfaceGhosts*>::iterator iter = ghostList.begin(); iter != ghostList.end(); iter++) {
					InterfaceGhosts* temp = *iter;
					if (temp->GetPositionI() == i && temp->GetPositionJ() == j) {
						if (arena->GetArenaData(i, j) == "@" && FruitIsActive) {
							break;
						}
						else {
							arena->SetArenaData(i, j, temp->GetShape());
						}
						break;
					}
				}
			}
		}
	}
}

void GameManager::GameOver() {
	GameIsOver = true;
	GameLoop = false;
}

void GameManager::Play() {
	while (MainLoop) {
		if (MenuLoop) {
			MainMenu();
		}
		else if (GameLoop) {
			GameUpdate();
		}
		else if (GameIsOver) {
			char input = KeyboardInput();
			if (input == '\r') {
				MenuLoop = true;
				DrawMenu(menuValue);
			}
		}
	}
}
