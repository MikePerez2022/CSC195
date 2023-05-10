#pragma once
#include <list>
#include <iostream>
#include <fstream>//
#include <ostream>//
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

	virtual void read(std::ifstream& ifstr);
	virtual void write(std::ofstream& ofstr);

	//[5-3]
	friend bool operator == (const std::unique_ptr<Animal>& animal, const std::string& name) { return (name == animal->GetName()); };

	friend bool operator == (const std::unique_ptr<Animal>& animal, const Animal::eType type) { return (type == animal->GetType()); };

	//
	friend std::istream& operator >> (std::istream& istr, Animal& animal);
	friend std::ostream& operator << (std::ostream& ostr, Animal& animal);

	// Create file write for fostr << animal
	friend std::ofstream& operator << (std::ofstream& ofstr, Animal& animal);
	// Create file read for fistr >> animal
	friend std::ifstream& operator >> (std::ifstream& ifstr, Animal& animal);
};

