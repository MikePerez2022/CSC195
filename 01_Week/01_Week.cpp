// 01_Week.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


int main()
{
    std::cout << "Hello World!\n";


    int iVal1 = -1;
    int iVal3 = 42;
    short shVal2 = 3;
    long lVal = 123456789;
    float fVale = 23;
    char chVal = 'a';

    std::cout << "\n iVal1 = ";
    std::cout << iVal1 << " address = " << &iVal1;
    std::cout << "\n shval2 = " << shVal2 << " address = " << &shVal2;
    std::cout << "\n iVal3 = " << iVal3 << " address = " << &iVal3;

    std::cout << "\n **** size of char = " << sizeof(chVal);
    std::cout << "\n **** size of short = " << sizeof(shVal2);
    std::cout << "\n **** size of int = " << sizeof(iVal1) << "\n";


    int* iPtr = NULL;
    iPtr = &iVal1;

    std::cout << "\n value of ptr variable = " << iPtr;
    std::cout << "\n iPtr address = " << &iPtr;
    std::cout << "\n size of iPtr = " << sizeof(iPtr);
    std::cout << "\n value iPtr points to is " << *(iPtr + 8) << "\n";

    //Heap memory
    char* chTemp = NULL;
    chTemp = (char*)malloc(20);
    //memset(chTemp, '\0', 20);
    memset(chTemp, 0, 20); // 0, '\0', NULL

    //Do stuff with the memory, then
    free(chTemp);
    chTemp = NULL; // Good Practice

    std::cout << "\n\n End of Program ";

    

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
