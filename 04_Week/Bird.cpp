#include "Bird.h"

void Bird::Read(std::ostream& ostr, std::istream& istr) {
	Animal::Read(ostr, istr); //get animal values

	ostr << "Enter number of Eggs: \n";
	istr >> _numEggs;
	ostr << "Enter Wingspan: \n";
	istr >> _wingspan;
	
}

// /////////////////////////////////////////////////////
void Bird::Write(std::ostream& ostr) {
	Animal::Write(ostr); //get animal values

	ostr << "Num Eggs: " << this->_numEggs << "\n";
	ostr << "Wingspan: " << this->_wingspan << "\n";
}

/// /////////////////////////////////////////
void Bird::read(std::ifstream& ifstr) {
	Animal::read(ifstr);
	ifstr >> this->_numEggs;
	ifstr >> this->_wingspan;
}

/// /////////////////////////////////////
void Bird::write(std::ofstream& ofstr) {
	Animal::write(ofstr);
	ofstr << "\n" << this->_numEggs;
	ofstr << "\n" << this->_wingspan << "\n";
}
