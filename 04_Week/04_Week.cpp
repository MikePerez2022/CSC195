// 04_Week.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include <iostream>
#include "MyInput.h"
#include "Animal.h"
#include "Database.h"

int main()
{
    MyInput input;

    std::unique_ptr<Animal> animal;

    Database db;

    std::cout << "04 Week Hello World!\n";

    int iMenu = 0;

    while (iMenu != 6) {
        cout << "Enter a menu option: \n";
        cout << "1) Add an Animal \n";
        cout << "2) Display All Animals \n";
        cout << "3) Display by name \n";
        cout << "4) Display by type \n";
        cout << "6) Quit\n";

        iMenu = input.GetUserInt("asdf", 1, 6);
        int iType = 0;
        string searchName = " ";
        string animalType = " ";
        switch (iMenu) {
        case 1:
            cout << "1) Fish \n";
            cout << "2) Bird \n";
            iType = input.GetUserInt(1, 2);
            switch (iType){
            case 1:
                animal = db.Create(Animal::eType::Fish);
                break;
            case 2:
                animal = db.Create(Animal::eType::Bird);
                break;

            }//Inner case

            animal->Read(std::cout, std::cin);
            db.Add(animal);
            break;

        case 2:
            db.DisplayAll(cout);
            break;
        case 3:
            //prompt by name
            //pass through and cout by name
            cout << "What is the name: " << "\n";
            cin >> searchName;
            db.DisplayByName(cout, searchName);
            break;
        case 4:
            cout << "What animal type: " << "\n";
            cin >> animalType;
            //prompt by type
            //pass type and cout by type
            db.DisplayByType(cout, animalType);
            break;

        }

    }//while
}
