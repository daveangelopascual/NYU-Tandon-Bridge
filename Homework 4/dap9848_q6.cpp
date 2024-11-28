#include <iostream>
using namespace std;

int main(){
    int input, currentInteger;

    cout << "Please enter a positive integer: ";
    cin >> input;

    for (int i = 1; i <= input; i++){
        //resets even and odd counter
        int numEven = 0, numOdd = 0;
        //assigns next value of i to check the digits
        currentInteger = i;

        while (currentInteger > 0){
            //Increments Even Counter if Digit is Even
            if (currentInteger % 2 == 0)
                numEven++;
            //Increments Odd Counter if Digit is Odd
            else
                numOdd++;
            //Moves on to the next digit (next group of 10s)
            currentInteger /= 10;
        }
        //Outputs if Even digits is greater than Odd digits, otherwise will move to next value of i
        if (numEven > numOdd)
            cout << i << endl;
        else
            continue;
    }
    return 0;
}
