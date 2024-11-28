#include <iostream> 
#include <cmath>
using namespace std;


int main() {

    //Defined as float because inputs are all real numbers.
    float valueA, valueB, valueC, valueSQRT;
    int option;

    //User Specified Inputs
    cout << "Please enter value of a: ";
    cin >> valueA;
    cout << "Please enter value of b: ";
    cin >> valueB;
    cout << "Please enter value of c: ";
    cin >> valueC;

    valueSQRT = (valueB * valueB) - (4 * (valueA * valueC));
    
    //Determine the number of solutions.
    if (valueA == 0 && valueB == 0) {
        if (valueC == 0)
            option = 4;

        else
            option = 5;
    }
    
    //If the value of A is 0, and the other values are not 0, then the equation is a linear function (y=mx+b) and does not use the quadratic formula.
    else if (valueA == 0 && valueB != 0 && valueC != 0)
        cout << "This equation has a single real solution x=" << -1 * valueC / valueB << endl;

    else if (valueSQRT == 0)
        option = 1;

    else if (valueSQRT > 0)
        option = 2;

    else if (valueSQRT < 0)
        option = 3;
    
    float answer1, answer2;

    //Perform the calculations
    switch (option) {
    case 1:
        answer1 = (-1 * valueB) / (2 * valueA);
        cout << "This equation has a single real solution x=" << answer1 << endl;
        break;

    case 2:
        answer1 = ((-1 * valueB) + (sqrt(valueSQRT))) / (2 * valueA);
        answer2 = ((-1 * valueB) - (sqrt(valueSQRT))) / (2 * valueA);
        cout << "This equation has two real solutions x=" << answer1 << " and x=" << answer2 << endl;
        break;

    case 3:
        cout << "This equation no real solution.\n";
        break;

    case 4:
        cout << "This equation has an infinite number of solutions.\n";
        break;

    case 5:
        cout << "This equation has no solution.\n";
        break;

    default:
        break;
    }

    return 0;
}
