#include <iostream>
#include "Hangman.h"
#include "Input.h"

using namespace std;

/*
No longer a requirement:
You do not need to read words from a file
the Word can be hardcoded
Model, View, Contols (MVC) not required -- OOP is the hardest part
Do not need to prompt user to play again
*/

int main()
{
    bool RestartOn = true;

    while (RestartOn) {

        Input userInput;
        char guess;
        string guessWord;
        bool GameOn = true;
        int Guesses = 6;
        string PlayerName;
        int check = 0;
        int restart = 0;

        PlayerName = userInput.GetUserString("What is your name?");

        cout << "\n";
        cout << "Player: " << PlayerName << "\n \n";

        int choice = 0;

        hm::Hangman<char> OriginWord{ 'h','a','p','p','i','n','e','s','s' };
        hm::Hangman<char> hiddenWord;
        hm::Hangman<char> guessedLetters;
        hm::Hangman<char> letters{ 'a','b','c','d','e','f','g','h','i','j','k','l','m'
                                ,'n','o','p','q','r','s','t','u','v','w','x','y','z' };

        hiddenWord = OriginWord;

        hiddenWord.hideWord("happiness");


        cout << "Welcome to Hangman all words & letters are in lower case" << PlayerName << "\n \n";


        cout << "Hidden Word" << "\n";
        hiddenWord.printList();
        cout << "\n";

        cout << "Guessed Letters" << "\n";
        guessedLetters.printList();
        cout << "\n";

        cout << "Un-Guessed Letters" << "\n";
        letters.printList();
        cout << "\n";


        while (GameOn) {


            if (Guesses <= 0) {
                check = 2;
            }
            else if (hiddenWord.checkWord("happiness")) {
                check = 1;
            }
            else {
                check = 0;
            }


            switch (check) {
            case 0:
                cout << "Enter Choice: \n";
                cout << "1) Guess a Letter \n";
                cout << "2) Guess the Word \n";
                cout << "3) Guesses Left \n";
                cout << "4) Display word & letters \n";
                cout << "5) Quit \n";

                choice = userInput.GetUserInt("What is your choice? ", 1, 5);
                break;
            case 1:
                cout << "Guesses left " << Guesses << "\n";
                cout << "You Win, your friend was saved. \n";
                choice = 5;
                break;
            case 2:
                cout << "Guesses left " << Guesses << "\n";
                cout << "You Lose & your friend is now hanged. \n";
                choice = 5;
                break;
            }

            switch (choice) {
            case 1:

                guess = userInput.GetUserChar("What letter do you guess?");
                if (letters.checkChar(guess, guessedLetters, false)) {

                    if (!OriginWord.checkChar(guess, hiddenWord, true)) {
                        Guesses--;
                        cout << "This letter didn't work. \n";
                    }
                    else {
                        cout << "This letter worked \n";
                    }
                    guessedLetters.push_back(guess);
                    letters.remove(guess);


                    cout << "Hidden Word: \n";
                    hiddenWord.printList();
                    cout << "\n";
                }
                else {
                    cout << "----------------------------------------  \n";
                    cout << "This letter has already been guessed. \n";
                    cout << "----------------------------------------  \n \n";
                }

                break;
            case 2:

                guessWord = userInput.GetUserString("What is the word? [Type answer in lower case]");
                if (OriginWord.checkWord(guessWord)) {
                    hiddenWord = OriginWord;

                    cout << "You Guessed Correct.     |(*v*)| \n \n";
                }
                else {
                    Guesses = 0;

                    cout << "You Guessed Wrong.    |(o_o)| \n \n";
                }

                break;
            case 3:
                cout << "----------------------------------------  \n";
                cout << "Guesses left " << Guesses << "\n";
                cout << "----------------------------------------  \n \n";
                break;
            case 4:
                cout << "Hidden Word \n";
                cout << "----------------------------------------  \n";
                hiddenWord.printList();
                cout << "----------------------------------------  \n \n";

                cout << "Guessed Letters \n";
                cout << "----------------------------------------  \n";
                guessedLetters.printList();
                cout << "----------------------------------------  \n \n";

                cout << "Letters \n";
                cout << "----------------------------------------  \n";
                letters.printList();
                cout << "----------------------------------------  \n \n";
                break;
            case 5:
                cout << "\n";
                cout << "1) Reatart Game \n";
                cout << "2) END GAME \n";
                cout << "\n";
                restart = userInput.GetUserInt("Do you want to restart? ", 1, 2);
                switch (restart) {
                case 1:
                    RestartOn = true;

                    break;
                case 2:
                    RestartOn = false;
                    break;
                }
                GameOn = false;
                break;
            }

        }
    }
    cout << " \n \n Thank you for playing." << " \n Good Bye. \n";

}


