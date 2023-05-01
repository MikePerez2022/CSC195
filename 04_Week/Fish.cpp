#include "Fish.h"

void Fish::Read(std::ostream& ostr, std::istream& istr) {
	Animal::Read(ostr, istr); //get animal values

	ostr << "Enter number of Fins: \n";
	istr >> _numFins;
	ostr << "Enter the number of Teeth: \n";
	istr >> _numTeeth;
	ostr << "Enter the Habitat: \n";
	istr >> _habitat;

}


// /////////////////////////////////////////////////////
void Fish::Write(std::ostream& ostr) {
	Animal::Write(ostr); //get animal values

	ostr << "Num Fins: " << this->_numFins << "\n";
	ostr << "Num Teeth: " << this->_numTeeth << "\n";
	ostr << "Habitat: " << this->_habitat << "\n";
}

/// /////////////////////////////////////////
void Fish::read(std::ifstream& ifstr) {
	Animal::read(ifstr);
	ifstr >> this->_numFins;
	ifstr >> this->_numTeeth;
	ifstr >> this->_habitat;
}

/// /////////////////////////////////////
void Fish::write(std::ofstream& ofstr) {
	Animal::write(ofstr);
	ofstr << "\n" << this->_numFins;
	ofstr << "\n" << this->_numTeeth;
	ofstr << "\n" << this->_habitat << "\n";
}