#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee() {
    
}

void Employee::Read() {
    cout << "\n Enter their name: ";
    cin >> name;

    cout << "\n Enter their age: ";
    cin >> age;

    cout << "\n Enter their wage - Pay per hour: ";
    cin >> wage;

    cout << "\n Enter the number of days worked: ";
    cin >> daysWorked;

    if (daysWorked > 7) daysWorked = 7;


    for (int iCount = 0; iCount < daysWorked; iCount++) {
        //get values for hours worked
        cout << "\n Enter the hours worked for day " << iCount + 1 << ": ";
        cin >> hoursPerDay[iCount];

        totalHours += hoursPerDay[iCount];

        grossPay += hoursPerDay[iCount] * wage;
    }
}

void Employee::Write() {
    netPay = grossPay - (grossPay * TAX);

    cout << "\n" << name << " (" << age << ") Worked for " << daysWorked << " days: " << totalHours << " hours at $" << wage << " Per hour. \n";

    cout << "Gross Pay: " << grossPay << "\n";
    cout << "Net Pay: " << netPay << "\n";
    cout << "Tax payed: " << (grossPay * TAX) << "\n";
}