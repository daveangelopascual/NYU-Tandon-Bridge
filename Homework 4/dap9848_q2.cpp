#include <iostream> 
#include <string>
using namespace std;


int main() {

    int input;

    cout << "Please enter a decimal number: \n";
    cin >> input;
 
    int i = input, numeralM = 0, numeralC = 0, numeralX = 0, numeralI = 0;
    string romanNumeral = "";

    while (i != 0) {
        
        //Calculating number of M
        while (i / 1000 >= 1) {
            i -= 1000;
            numeralM++;
        }
        
        //Adding M to String
        for (int a = 0; a < numeralM; a++) {
            romanNumeral += "M";
        }

        //Calculating D
        if (i / 500 >= 1) {
            i -= 500;
            romanNumeral += "D";
        }

        //Calculating number of C
        while (i / 100 >= 1) {
            if (numeralC<4) {
                 i -= 100;
                numeralC++;
            }
        }

        //Adding C to String
        for (int b = 0; b < numeralC; b++) {
            romanNumeral += "C";
        }

        //Calculating L
        if (i / 50 >= 1) {
            i -= 50;
            romanNumeral += "L";
        }

        //Calculating number of X
        while (i / 10 >= 1) {
            if (numeralX<4) {
                i -= 10;
                numeralX++;
            }
        }
        //Adding X to String
        for (int c = 0; c < numeralX; c++) {
            romanNumeral += "X";
        }

        //Calculating V
        if (i / 5 >= 1) {
            i -= 5;
            romanNumeral += "V";
        }

        //Calculating number of I
        while (i / 1 >= 1) {
            if (numeralI<4) {
                i -= 1;
                numeralI++;
            }
        }
        
        //Adding I to String
        for (int d = 0; d < numeralI; d++) {
            romanNumeral += "I";
        }
    }

    cout << input << " is " << romanNumeral << endl;
    
    return 0;

}
