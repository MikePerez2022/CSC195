// 2_1_DataTypes.cpp 
//

#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
    const unsigned short MAXEMP = 20;
    unsigned int numEmployees = 0;

    cout << "2_1_DataTypes Hello World\n";
    Employee workers[MAXEMP];

    cout << "\n Please enter the number of employees: ";
    cin >> numEmployees;

    if (numEmployees > MAXEMP) numEmployees = MAXEMP;

    for (int empCount = 0; empCount < numEmployees; empCount++) {

        Employee* empPtr = NULL;
        empPtr = &workers[empCount];

        memset(empPtr->name, '\0', 33);
        
        empPtr->Read();
    }

    for (int empCount = 0; empCount < numEmployees; empCount++) {

        Employee* empPtr = NULL;
        empPtr = &workers[empCount];

        empPtr->Write();
    }
    
    
    //Employee* empPointer = NULL; // new Employee() - heap
    //empPointer = &workers[0];
    //empPointer->age = 42;
    //empPointer->Read();


    //void* ptr = malloc(20);
    //int* intPtr = new int;

    //*intPtr = 42;
    //printf("\n hex %00.x", *intPtr);
    //do stuff with memory
    //cout << sizeof(Employee);
    //delete empPointer; // - only for heap memory
    //delete intPtr;

    //*****!!!!!!*****  -  Useful later on
    //cout << "\n Size 1: " << (sizeof(workers) / sizeof(workers[1]));
    //cout << "\n Size 2: " << std::size(workers);


}
