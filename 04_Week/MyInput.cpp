#include "MyInput.h"

int MyInput::GetUserInt(string promt, unsigned short low, unsigned short high) {
	int iTemp = 0;
	do {
		cout << promt << "\n";
		cout << "Enter a number between " << low << " and " << high << "\n";
		cin >> iTemp;
		cout << "\n";

		if (!cin.good()) {
			cin.clear();
			cin.ignore();
			cout << "Inproper input! You little $&*%!";
			iTemp = low - 1;
		}
	} while ((iTemp < low || iTemp > high));

	return iTemp;
}
/// ////////////////////////////////////////
int MyInput::GetUserInt(unsigned short low, unsigned short high) {
	return GetUserInt(" ", low, high);
}