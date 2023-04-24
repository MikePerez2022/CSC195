#pragma once
#include <list>
#include <iostream>
using namespace std;

class Animal
{
public:
	enum class eType{ Fish = 1, Bird = 2};

protected:
	string _name = "";
	string _color = "";
	unsigned int _lifespan = 0;

public:
	virtual eType GetType() = 0; //Pure virtual Method
	string GetTypeString();
	string GetName() { return _name; }
	void SetName(string val) { _name = val; }
	unsigned int GetLifespan() { return _lifespan; }
	void SetLifespan(unsigned int val) { _lifespan = val; }
	string GetColor() { return _color; }
	void SetColor(string val) { _color = val; }

	virtual void Read(std::ostream& ostr, std::istream& istr);
	virtual void Write(std::ostream& ostr);
};

