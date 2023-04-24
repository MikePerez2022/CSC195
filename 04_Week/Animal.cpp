#include "Animal.h"

// //////////////////////////////////////
string Animal::GetTypeString() {//TODO: This might need some fixing
	
	switch (this->GetType()) {
	case eType::Fish:
		return "Fish";
		break;
	case eType::Bird:
		return "Bird";
		break;
	}

	return "Undefined Animal";
}

/// /////////////////////////////////////////
void Animal::Read(std::ostream& ostr, std::istream& istr) {
	ostr << "Enter Animal Name: \n";
	istr >> this->_name;
	ostr << "Enter Animal Lifespan: \n";
	istr >> this->_lifespan;
	ostr << "Enter Animal Color: \n";
	istr >> this->_color;
}

/// /////////////////////////////////////
void Animal::Write(std::ostream& ostr) {
	ostr << "\n ----------------------- \n";
	ostr << "Name: " << this->_name<< "\n";
	ostr << "Type: " << this->GetTypeString()<< "\n";
	ostr << "Lifespan: " << this->_lifespan << "\n";
	ostr << "Color: " << this->_color << "\n";
}


