// 03_Week.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyDerived.h"

using namespace std;
#include "MyConfig.h"

struct Person
{
    char name[32];
    int id;

public:
    void read() {
        cout << "What is the persons Name: \n";
        cin >> name;

        cout << "What is the persons ID: \n";
        cin >> id;
    }
    void write() {
        cout << "Name: " << name << "\n ID: " << id << "\n";
        
    }
};

void square(int iParam) {
    iParam = iParam * iParam;
}

void squareRef(int& iParam) {
    iParam = iParam * iParam;
}

void Double(int* iPtr) {
    *iPtr = *iPtr * 2;
}

int main()
{
    Config myConfig;
    myConfig.Version.major = 1;

    // ** REFERENCE **
    //
    // declare an int variable and set the value to some number (less than 10)
    // declare a int reference and set it to the int variable above
    // output the int variable
    // set the int reference to some number
    // output the int variable
    // what happened to the int variable when the reference was changed? 
    // (The int variable has seemed to change it's value or at least the int variable is now referencing the new number)
    // 
    // output the address of the int variable
    // output the address of the int reference
    // are the addresses the same or different? (The adresses are the same)
    int myInt = 5;
    int& intRef = myInt;
    cout << myInt << " - Int variable \n";
    intRef = 20;
    cout << myInt << "\n";

    cout << &myInt << "\n";
    cout << &intRef << "\n\n"; 
    // 
    // ** REFERENCE PARAMETER **
    //
    // create a function above main() called Square that takes in an int parameter
    // in the function, multiply the int parameter by itself and assign it back to the parameter(i = i * i)
    // call the Square function with the int variable created in the REFERENCE section // myInt
    // output the int variable to the console
    // !! notice how the variable has not changed, this is because we only passed the value to the function !!
    // change the Square function to take a int reference
    // !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
    // !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
    square(myInt);
    cout << myInt << " - square function \n"; // The function changed a copy not the source
    squareRef(myInt);
    cout << myInt << " - squareRef function \n\n"; // The function changed the variable and didn't just use a copy
    //
    // ** POINTER VARIABLE **
    //
    // declare an int pointer, set it to nullptr (It points to nothing)
    // set the int pointer to the address of the int variable created in the REFERENCE section
    // output the value of the pointer
    // what is this address that the pointer is pointing to? ( 00000087F4EFFA64 )
    // output the value of the object the pointer is pointing to (dereference the pointer) ////
    int* intPtr = NULL;
    intPtr = &myInt;
    cout << intPtr << " - Value of Pointer \n";
    cout << *intPtr << " - Inital value of ptr \n\n";
    // 
    // ** POINTER PARAMETER **
    //
    // create a function above main() called Double that takes in an int pointer parameter
    // in the function, multiply the int pointer parameter by 2 and assign it back to the parameter(i = i * 2)
    // !! make sure to dereference the pointer to set the value and not set the address !!
    // call the Double function with the pointer created in the POINTER VARIABLE section
    // output the dereference pointer
    // output the int variable created in the REFERENCE section
    // did the int variable's value change when using the pointer? (Yes, the int variable's value chnged.)
    Double(intPtr);
     //Double(&myInt); 
    cout << *intPtr << " - After Double Value \n";
    cout << myInt << " - After Double Value (Ref) \n\n"; // Yes, the int variable's value chnged.
    // 
    // ** ALLOCATION/DEALLOCATION **
    //
    // create an int pointer that points at an int allocated on the heap, set the allocated int value to some number
    // output the pointer value, this should be the address of the int allocated on the heap
    // output the dereference pointer
    // deallocate the int pointer to free up the memory
    // create an int pointer that points at an array of ints allocated on the heap, the array size should be 4 - 6
    // use a for loop and set each int in the array to a random number (use => rand() % 10 to get a random number
    // use a for loop and output each of the ints in the array
    // use a for loop and output the address of each of the ints in the array
    // deallocate the int pointer to free up the memory block (remember it's an array)
    
    int* intPtr2 = new int;
    *intPtr2 = 23;

    cout << intPtr2 << " - second int pointer \n";
    cout << *intPtr2 << " - second int pointer (deref) \n\n";

    delete intPtr2; //Deallocation

    int* intPtr3 = new int[5];

    for (int iCount = 0; iCount < 5; iCount++) {
        intPtr3[iCount] = rand() % 10 + 1;

        cout << intPtr3[iCount] << " - Value of spot " << iCount + 1 << "\n";

        cout << &intPtr3[iCount] << " - Adress of spot " << iCount + 1 << "\n\n";
    }

    delete[] intPtr3; //Deallocation

    
    // 
    // ** STRUCTURE **
    //
    // create a Person pointer that points at an array of Persons allocated on the heap, the array size should be 2
    // read in a name from the console and set it to the person name, do this for the id also, do this for both Persons
    // use a for loop and output the name and id of each person in the array
    // deallocate the person pointer to free up the memory block (remember it's an array)

    Person* personPtr = new Person[2];

    for (int lCount = 0; lCount < 2; lCount++) {
        cout << "Person " << lCount + 1 << "\n";
        personPtr[lCount].read(); //Asks for input for name and id
    }

    for (int jCount = 0; jCount < 2; jCount++) {
        personPtr[jCount].write(); //Prints out the id and name info
    }

    delete[] personPtr; // Deallocation

    //Both the read and write functions are in the Person struct above the main function

}
