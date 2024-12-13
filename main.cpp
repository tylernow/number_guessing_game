#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class guessingGame {
    private: 
        int difficulty; 
        int randomNumber;
        bool correct;
        string diff;
    public:
        void getNumber() {
            srand(time(0));
            randomNumber = rand() % 101; // This gets a random number between 1 and 100
        }
        void menu(int count) {
            if(count == 1) {
                cout << endl;
                cout << "Welcome to the Number Guessing Game!" << endl;
                cout << "I am thinking of a number between 1 and 100." << endl;
                cout << endl;
                cout << "Please select the difficulty level:" << endl;
                cout << "1. Easy (10 Chances)" << endl;
                cout << "2. Medium (5 Chances)" << endl;
                cout << "3. Hard (3 Chances)" << endl;
                cout << endl;
                cout << "Enter your choice: ";
                cin >> difficulty;
                cout << endl;
            }
            else {
                cout << endl;
                cout << "I am thinking of a number between 1 and 100." << endl;
                cout << endl;
                cout << "Please select the difficulty level:" << endl;
                cout << "1. Easy (10 Chances)" << endl;
                cout << "2. Medium (5 Chances)" << endl;
                cout << "3. Hard (3 Chances)" << endl;
                cout << endl;
                cout << "Enter your choice: ";
                cin >> difficulty;
                cout << endl;
            }

            cout << "Great you have selected the " << determineDiff(difficulty) << " difficulty level." << endl;
            cout << "Let's start the game!" << endl;
            cout << endl;
        } // end of menu function
        string determineDiff (int level) {
            if (level == 1) {
                diff = "Easy";
            }
            else if (level == 2) {
                diff = "Medium";
            }
            else if (level == 3){
                diff = "Hard";
            }
            else {
                string error = "Please enter a valid selection 1 - 3.";
                return error;
            }
            return diff;
        } // end of determineDiff function
        void hint (int guess) {
            errorMessage(guess);
            if (guess > randomNumber) {
                cout << "Incorrect! The number is less than " << guess << "." << endl;
                cout << endl;
            }
            else {
                cout << "Incorrect! The number is greater than " << guess << "." << endl;
                cout << endl;
            }
            
        } // end of hint function
        void errorMessage(int number) {
            if (number < 1 || number > 100) {
                cout << "This guess is out bounds! Please guess numbers between 1 and 100" << endl;
            }
        }
        void readinGuess() {
            int players_guess;
            int attempts = 0;
            while (players_guess != randomNumber) {
                if(differentLevels(attempts)) {
                    break;
                }
                cout << "Enter your guess: ";
                cin >> players_guess;
                if (players_guess == randomNumber) {
                    attempts++;
                    if(attempts == 1) {
                        cout << "Congratulations! You guessed the correct number in " << attempts << " attempt.\n";
                        break;
                    }
                    else {
                        cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
                        break;
                    }
                }
                else {
                    hint(players_guess);
                    attempts++;
                }
            }
        } // end of readinguess
        
        bool differentLevels(int attempts) {
            bool exit = false;
            if(diff == "Easy" && attempts == 10) {
                cout << "Exceeded amount of attempts (10). The correct number was " << randomNumber << "." << endl;
                exit = true;
            }
            else if(diff == "Medium" && attempts == 5) {
                cout << "Exceeded amount of attempts (5). The correct number was " << randomNumber << "." << endl;
                exit = true;
            }
            else if(diff == "Hard" && attempts == 3) {
                cout << "Exceeded amount of attempts (3). The correct number was " << randomNumber << "." << endl;
                exit = true;
            }
            return exit;
        } // end of differentLevels

        bool playAgain() {
            int decision = 0;
            bool again = false;
            cout << "Do you want to play again?\n";
            cout << "1. Yes\n";
            cout << "2. No\n";
            cout << endl;
            cout << "Enter you choice: ";
            cin >> decision;
            if(decision == 1) { // returns true to start the game again
                again = true;
                return again;
            }
            else { // returns false to quit the game
                cout << "Thank you for playing!\n";
                return again;
            }
        } // end of playagain function

        
}; // End of class guessingGame


int main() {
    guessingGame game;
    int count = 0;
    bool run = true;
    while(run) { // keeps the game runnning until user prompts to quit
        if(count == 0) { // first time running the game
            count++;
            game.getNumber();
            game.menu(count);
            game.readinGuess();
        }
        else {
            count++;
            game.getNumber();
            game.menu(count);
            game.readinGuess();
        }
        run = game.playAgain();
    }
} // End of Main