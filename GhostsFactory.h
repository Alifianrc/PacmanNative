#pragma once
#ifndef ghost

#include "Pinky.h"
#include "Inky.h"

#define PINKY 2000
#define INKY 2001

//aas 4210191028

class GhostsFactory {

public:
    static InterfaceGhosts* CreateItem(int item, int i, int j);
};
#endif