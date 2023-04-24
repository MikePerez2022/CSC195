#pragma once
#include <list>

#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
class Database
{
protected:
	std::list<std::unique_ptr<Animal>> _animal;

public:
	std::unique_ptr<Animal> Create(Animal::eType type);
	void Add(std::unique_ptr<Animal>& animal);
	void DisplayAll(std::ostream& ostr);
	void DisplayByName(std::ostream& ostr, string name);
	void DisplayByType(std::ostream& ostr, string type);
	
};

