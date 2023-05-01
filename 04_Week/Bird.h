#pragma once
#include "Animal.h"
class Bird : public Animal
{
public:
	eType GetType() override { return eType::Bird; }

	void Read(std::ostream& ostr, std::istream& istr) override;
	void Write(std::ostream& ostr) override;

	virtual void read(std::ifstream& ifstr) override;
	virtual void write(std::ofstream& ofstr) override;

protected:
	unsigned int _numEggs = 0;
	unsigned int _wingspan = 0;
};

