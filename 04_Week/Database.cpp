#include "Database.h"

std::unique_ptr<Animal> Database::Create(Animal::eType type) {
	Animal* animal = nullptr;


	switch (type){
	case Animal::eType::Fish:
		animal = new Fish;
		break;
	case Animal::eType::Bird:
		animal = new Bird;
		break;
	}

	return std::unique_ptr<Animal> (animal);
}

/// /////////////////////////////////////

void Database::Add(std::unique_ptr<Animal>& animal){
	this->_animal.push_back(std::move(animal));
	std::cout << "**** List Size = " << this->_animal.size() << "\n";
}
// /////////////////////////////////////
void Database::DisplayAll(std::ostream& ostr){
	for (std::unique_ptr<Animal>& animal : this->_animal) {
		animal->Write(ostr);
		ostr << "\n";
	}
}
// /////////////////////////////////////
void Database::DisplayByName(std::ostream& ostr, string name) {
	for (std::unique_ptr<Animal>& animal : this->_animal) {
		if (animal->GetName() == name) {
			animal->Write(ostr);
			ostr << "\n";
		} else {
			ostr << "Name is non-exsistent in data base" << "\n";
		}
		
	}
}
// /////////////////////////////////////
void Database::DisplayByType(std::ostream& ostr, string type) {
	for (std::unique_ptr<Animal>& animal : this->_animal) {
		if (animal->GetTypeString() == type) {
			animal->Write(ostr);
			ostr << "\n";
		} else {
			ostr << "Type of animal is non-exsistent in data base" << "\n";
		}
		
	}
}

// /////////////////////////////////////

void Database::Save(const string fileName) {
	//Open file
	std::ofstream output(fileName, std::ofstream::out | std::ofstream::app); //Bitwise or

	if (output.is_open()) {// == ture
		for (std::unique_ptr<Animal>& animal : this->_animal) {
			animal->write(output);
			
		}
	}

	if (output.is_open()) {
		output.close();
	}

}

// /////////////////////////////////////
void Database::Load(const string fileName) {
	int iType = 0;
	std::ifstream output(fileName);
	std::unique_ptr<Animal> animal;
	
	this->RemoveAll();

	
	if (output.is_open()) {//output.is_open == ture
		while (!output.eof()) {
			output >> iType;
			if (output.fail()) break;
			animal = this->Create(static_cast<Animal::eType>(iType));

			animal->read(output);
			this->Add(animal);
		}//end while
	}//end if

	if (output.is_open()) {
		output.close();
	}
}

