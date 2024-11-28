#include <iostream> 
using namespace std;

//Constants
const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {

    double input, decimal;
    int option, wholeNumber, roundedNumber;


    //User Specified Inputs
    cout << "Please enter a Real number: \n";
    cin >> input;

    wholeNumber = input / 1;
    decimal = input - wholeNumber;

    //User selects Rounding method.
    cout << "Choose your rounding method:\n";
    cout << "1. Floor round\n";
    cout << "2. Ceiling round\n";
    cout << "3. Round to the nearest whole number\n";
    cin >> option;

    switch (option) {
    case 1:
        //Checks if number is already a whole number.
        if (decimal == 0)
            roundedNumber = wholeNumber;

        //Checks if number is positive
        else if (wholeNumber > 0)
            roundedNumber = wholeNumber;

        //Otherwise is negative.
        else
            roundedNumber = wholeNumber - 1;

        cout << roundedNumber << endl;
        break;

    case 2:
        //Checks if inputted number is already a whole number.
        if (decimal == 0)
            roundedNumber = wholeNumber;

        //Checks if number is positive.
        else if (wholeNumber > 0)
            roundedNumber = wholeNumber + 1;

        //Otherwise is negative.
        else
            roundedNumber = wholeNumber;

        cout << roundedNumber << endl;
        break;

    case 3:
        //Checks if inputted number is already a whole number.
        if (decimal == 0)
            roundedNumber = wholeNumber;

        //Checks if number is positive.
        else if (wholeNumber > 0) {
            if (decimal >= .50)
                roundedNumber = wholeNumber + 1;
            else
                roundedNumber = wholeNumber;
        }

        //Otherwise is negative.
        else {
            if (decimal <= .50)
                roundedNumber = wholeNumber - 1;
            else
                roundedNumber = wholeNumber;
        }

        cout << roundedNumber << endl;
        break;

        
    default:
        // When options 1, 2, or 3 are not chosen.
        cout << "Please try a valid option!\n";
        break;
    }
    return 0;
}
        cout << roundedNumber << endl;
        break;
        
    default:
        // When options 1, 2, or 3 are not chosen.
        cout << "Please try a valid option!\n";
        break;
    }

    return 0;
}
