#pragma once
#include "MyConfig.h"
class MyBase
{
public:
	virtual int AddSomething(int initVal);
	Config conf; // Encapsulated
};

