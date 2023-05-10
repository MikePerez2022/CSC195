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

	//[5-3]

	//friend std::istream& operator >> (std::istream& istr, Bird& animal);
	//friend std::ostream& operator << (std::ostream& ostr, Bird& animal);

	// Create file write for fostr << animal
	//friend std::ofstream& operator << (std::ofstream& ofstr, Bird& animal);
	// Create file read for fistr >> animal
	//friend std::ifstream& operator >> (std::ifstream& ifstr, Bird& animal);



protected:
	unsigned int _numEggs = 0;
	unsigned int _wingspan = 0;
};

