#pragma once
// 4210191011   Muhammad Alifian Rizki C.

#include <string>

class InterfaceGhosts {
public:
	virtual int GetPositionI() = 0;
	virtual int GetPositionJ() = 0;
	virtual void SetPosition(int i, int j) = 0;

	virtual void Move(int i, int j) = 0;

	virtual std::string GetShape() = 0;
};
