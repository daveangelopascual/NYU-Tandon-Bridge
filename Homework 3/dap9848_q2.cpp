#include <iostream> 
#include <string>
using namespace std;


int main() {

    int gradYear, currentYear;
    string name;

    //User Specified Inputs
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your gradaution year: ";
    cin >> gradYear;
    cout << "Please enter current year ";
    cin >> currentYear;

    //Status Calculation
    if (gradYear <= currentYear)
        cout << name <<", you Graduated.\n";
    
    else if ((gradYear - currentYear) == 4)
        cout << name <<", you are a Freshman.\n";

    else if ((gradYear - currentYear) == 3)
        cout << name <<", you are a Sophomore.\n";

    else if ((gradYear - currentYear) == 2)
        cout << name <<", you are a Junior.\n";

    else if ((gradYear - currentYear) == 1)
        cout << name <<", you are a Senior.\n";

    else if ((gradYear - currentYear) > 4)
        cout << name <<", you are not in college yet.\n";

    return 0;
}
