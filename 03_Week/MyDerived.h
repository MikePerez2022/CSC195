#pragma once
#include "MyBase.h"
class MyDerived : public MyBase
{
public:
	int AddSomething(int initVal);

	int SubtractSomething(int initVal) {
		return initVal - 42;
	}
};

