// Data_Types.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    const unsigned short MAX_DAYS = 14;
    const float TAX = 0.3f;


    string name; // get name ZZ


    unsigned int dCount = 0; //get days worked ZZ
    unsigned short hours[MAX_DAYS]; //get days hours
    unsigned int totalHours = 0;
    float fGrossPay = 0; // cals gross pay - total hours * wager
    float netPay = 0; // calc net pay - grosspay - (grosspay * tax)
    float fWage = 0; //get wage ZZ

    std::cout << "Hello World!\n";

    cout << "\n Enter your name: ";
    cin >> name;

    cout << "\n Enter your wage - Pay per hour: ";
    cin >> fWage;

    cout << "\n Enter the number of days worked: ";
    cin >> dCount;


    for (int iCount = 0; iCount < dCount; iCount++) {
        //get values for hours worked
        cout << "\n Enter your hours worked for day " << iCount + 1 <<": ";
        cin >> hours[iCount];

        totalHours += hours[iCount];

        fGrossPay += hours[iCount] * fWage;
    }

    //Calculate taxes and output

    netPay = fGrossPay - (fGrossPay * TAX);

    cout << "\n" << name << " Worked for " << dCount << " days: " << totalHours << " hours at $" << fWage << " Per hour. \n";

    cout << "Gross Pay: " << fGrossPay << "\n";
    cout << "Net Pay: " << netPay << "\n";
    cout << "Tax payed: " << (fGrossPay * TAX);

    cout << "\n\n End of App";


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
