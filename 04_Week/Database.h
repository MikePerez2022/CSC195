#pragma once
#include <list>

#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
class Database
{
public:
	const string FILE_NAME = "testFile.txt";

private:
	std::list<std::unique_ptr<Animal>> _animal;
	
public:
	std::unique_ptr<Animal> Create(Animal::eType type);
	void Add(std::unique_ptr<Animal>& animal);
	void DisplayAll(std::ostream& ostr);
	void DisplayByName(std::ostream& ostr, string name);
	void DisplayByType(std::ostream& ostr, string type);

	void Save(const string fileName);
	void Load(const string fileName);// & only made this lighter

protected:
	void RemoveAll() { _animal.clear(); };
	
};

