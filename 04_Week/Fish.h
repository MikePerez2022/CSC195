#pragma once
#include "Animal.h"
class Fish : public Animal
{
public:
	eType GetType() override { return eType::Fish; }

	void Read(std::ostream& ostr, std::istream& istr) override;
	void Write(std::ostream& ostr) override;

	virtual void read(std::ifstream& ifstr) override;
	virtual void write(std::ofstream& ofstr) override;

	//[5-3]

	//friend std::istream& operator >> (std::istream& istr, Fish& animal);
	//friend std::ostream& operator << (std::ostream& ostr, Fish& animal);

	// Create file write for fostr << animal
	//friend std::ofstream& operator << (std::ofstream& ofstr, Fish& animal);
	// Create file read for fistr >> animal
	//friend std::ifstream& operator >> (std::ifstream& ifstr, Fish& animal);



protected:
	unsigned int _numFins = 0;
	unsigned int _numTeeth = 0;
	string _habitat = " ";
};

