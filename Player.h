//4210191026 siju

#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Player {
    private:
        string name;
        int score;
        
    public:
        Player();

        string GetName();
        void SetName(string name);

        int GetScore();
        void SetScore(int value);
        
        void InputName();
};