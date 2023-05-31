#include "Input.h"

int Input::GetUserInt(string promt, unsigned short low, unsigned short high) {
	int UserInput = 0;
	do {
		cout << promt << "\n";
		cout << "Enter a number between " << low << " and " << high << "\n";
		cin >> UserInput;
		cout << "\n";

		if (!cin.good()) {
			cin.clear();
			cin.ignore();
			cout << "Inproper input!";
			UserInput = low - 1;
		}
	} while ((UserInput < low || UserInput > high));

	return UserInput;
}


int Input::GetUserInt(unsigned short low, unsigned short high) {
	return GetUserInt(" ", low, high);
}


string Input::GetUserString(string prompt) {
	string answer = "";
	string returnedAnswer = "";
	do {
		bool isNotGood = false;
		cout << prompt << "\n";
		cin >> answer;
		cout << "\n";


		for (char const& character : answer) {
			if (std::isdigit(character)) {
				isNotGood = true;
			}

		}


		if (!cin.good() || isNotGood) {
			cin.clear();
			cin.ignore();
			cout << "Inproper input!";
			answer = "";
		}
	} while (answer.empty());

	for (char const& character : answer) {
		returnedAnswer += tolower(character);
	}

	return returnedAnswer;
}


char Input::GetUserChar(string prompt) {
	string answer = "";
	char convertedAnswer = ' ';
	

	do {
		bool isNotGood = false;
		cout << prompt << "\n";
		cin >> answer;
		cout << "\n";

		int count = 0;
		for (char const& character : answer) {
			if (count > 1 || std::isdigit(character)) {
				isNotGood = true;
			}
			else {
				convertedAnswer = character;
			}
			count++;
		}


		if (!cin.good() || isNotGood) {
			cin.clear();
			cin.ignore();
			cout << "Inproper input!";
			answer = "";
		}

	} while (answer == "");

	return tolower(convertedAnswer);
}


// Use catch statements to stop the use of numbers or more than one character