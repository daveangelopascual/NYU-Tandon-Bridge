#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {

    srand(time(0));
    int randomNum = (rand()%100)+1;
    int guessNum, userGuess;
    int attempts = 5, rangeLower = 1, rangeUpper = 100;

    cout << "I thought of a number between 1 and 100! Try to guess it.\n";

    for (int i = 1; i <= 5; i++) {
        cout << "Range: [" << rangeLower << "," << rangeUpper << "], Number of guesses left: " << attempts << endl;
        cout << "Your guess: ";
        cin >> userGuess;

        if (userGuess == randomNum) {
            cout << "Congrats! You guessed my number in " << i << " guesses.\n";
            break;
        }       
        else if (userGuess < randomNum && i != 5) {
            cout << "Wrong! My number is bigger.\n\n";
            if (rangeLower < userGuess)
                rangeLower = userGuess + 1;
            attempts--;
        }
        else if (userGuess > randomNum && i != 5) {
            cout << "Wrong! My number is smaller.\n\n";
            if (rangeUpper > userGuess)
                rangeUpper = userGuess - 1;
            attempts--;
        }
        else
            cout << "Out of guesses! My number is " << randomNum << endl;
    }
    return 0;
}
