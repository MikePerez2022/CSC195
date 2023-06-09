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

    while (iMenu != 8) {
        cout << "Enter a menu option: \n";
        cout << "1) Add an Animal \n";
        cout << "2) Display All Animals \n";
        cout << "3) Display by name \n";
        cout << "4) Display by type \n";
        cout << "5) Remove all \n";
        cout << "6) Load from file \n";
        cout << "7) Save to file \n";
        cout << "8) Quit\n";

        iMenu = input.GetUserInt("asdf", 1, 8);
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

            cin >> *animal;
            db.Add(animal);
            break;

        case 2:
            db.DisplayAll(cout);
            break;
        case 3:
            
            cout << "What is the name: " << "\n";
            cin >> searchName;

            db.DisplayByName(cout, searchName);
            break;
        case 4:
            cout << "What animal type: " << "\n";
            cin >> animalType;
            db.DisplayByType(cout, animalType);
            break;
        case 5:
            db.remove();
            break;
        case 6:
            db.Load(db.FILE_NAME);
            cout << "\n";
            break;

        case 7:
            //save to file

            db.Save(db.FILE_NAME);
            cout << "Saved.... \n";
            break;

        }

    }//while
}
