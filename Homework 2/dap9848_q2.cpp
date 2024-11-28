#include <iostream>
using namespace std;


int main() {

    int centValue;
    int dollarValue, quarterCount, dimeCount, nickelCount, pennyCount;

    cout << "Please enter your amount in the format of dollars and cents separated by a space: \n";
    cin >> dollarValue >> centValue;
    
    //Calculations for Quarters
    quarterCount = centValue / 25;
    centValue -= quarterCount * 25;
    quarterCount += dollarValue * 4;

    //Calculations for Dimes
    dimeCount = centValue / 10;
    centValue -= dimeCount * 10;
    
    //Calculations for Nickels
    nickelCount = centValue / 5;
    centValue -= nickelCount * 5;
    
    //Calculations for Pennies
    pennyCount = centValue / 1;
    centValue -= pennyCount * 1;

    cout << dollarValue << " dollars and " << centValue << " cents are:\n";
    cout << quarterCount << " quarters, " << dimeCount << " dimes, " << nickelCount << " nickels and " << pennyCount << " pennies\n";

    return 0;
    
}
