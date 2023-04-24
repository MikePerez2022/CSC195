#pragma once
#include <iostream>
using namespace std;

class MyInput
{
public:
	int GetUserInt(string promt, unsigned short low, unsigned short high);
	int GetUserInt(unsigned short low, unsigned short high);
};

