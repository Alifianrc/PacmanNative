#pragma once
#ifndef ghost
#define ghost
#include <iostream>
//aas 4210191028
class Ghosts {
public:
    virtual int GetPositionI();
    virtual int GetPositionJ();
    virtual void SetPosition();
    virtual std::string GetShape();
};
#endif