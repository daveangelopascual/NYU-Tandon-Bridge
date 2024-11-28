#include <iostream>
using namespace std;


int main() {

    int quarterCount, dimeCount, nickelCount, pennyCount;
    const double QUARTER_VALUE = 0.25, DIME_VALUE = 0.10, NICKEL_VALUE = 0.05, PENNY_VALUE = 0.01;

    //User Inputs for the different coin quanitites.
    cout << "Please enter number of coins: \n";
    cout << "# of quarters:";
    cin >> quarterCount;
    cout << "# of dimes: ";
    cin >> dimeCount;
    cout << "# of nickels: ";
    cin >> nickelCount;
    cout << "# of pennies: ";
    cin >> pennyCount;

    //Calculating total value based off the coin count times coin value.
    double total = (quarterCount * QUARTER_VALUE) + (dimeCount * DIME_VALUE) + (nickelCount * NICKEL_VALUE) + (pennyCount * PENNY_VALUE);
    
    int dollarValue;
    int centValue;

    //Evalutating dollar value and cent value where 100 cents is equal to 1 dollar.
    dollarValue = total / 1;
    total -= dollarValue;
    centValue = total * 100;

    //Output displayed to user.
    cout << "The total is " << dollarValue << " dollars and " << centValue << " cents.\n";

    return 0;
    
}
