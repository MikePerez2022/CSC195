#pragma once
#include "Animal.h"
class Fish : public Animal
{
public:
	eType GetType() override { return eType::Fish; }

	void Read(std::ostream& ostr, std::istream& istr) override;
	void Write(std::ostream& ostr) override;

protected:
	unsigned int _numFins = 0;
	unsigned int _numTeeth = 0;
	string _habitat = " ";
};

