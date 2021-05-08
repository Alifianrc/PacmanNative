//4210191026 siju

#include "Player.h"
using namespace std;

Player::Player() {
    name = "Default Name";
    score = 0;
}

string Player::GetName() {
    return name;
}
void Player::SetName(string name) {
    this->name = name;
}

int Player::GetScore() {
    return score;
}
void Player::SetScore(int value) {
    score = value;
}

void Player::InputName() {
    string pName;
    cout << "Input Player Name : ";
    cin >> pName;
    name = pName;
}


