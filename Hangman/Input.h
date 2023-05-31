#pragma once
#include <iostream>

using namespace std;

class Input
{
public:
	int GetUserInt(string promt, unsigned short low, unsigned short high);
	int GetUserInt(unsigned short low, unsigned short high);

	string GetUserString(string promt);
	
	char GetUserChar(string promt);
};

