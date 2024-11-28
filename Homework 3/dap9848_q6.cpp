#include <iostream> 
#include <string>
using namespace std;


int main() {

    int hour, minute, callDuration, rate = 0;
    char colon;
    string day;

    //Constants
    const float PEAK_RATE = 0.40, NONPEAK_RATE = 0.25, WEEKEND_RATE = 0.15;

    //User Specified Inputs
    cout << "For Monday, type Mo\n";
    cout << "For Tuesday, type Tu\n";
    cout << "For Wednesday, type We\n";
    cout << "For Thursday, type Th\n";
    cout << "For Friday, type Fr\n";
    cout << "For Saturday, type Sa\n";
    cout << "For Sunday, type Su\n";
    cout << "Please enter the day of the week for the call: ";
    cin >> day;
    cout << "Please enter the start time of the call in 24hr notation, e.g. 13:30 for 1:30PM: ";
    cin >> hour >> colon >> minute;
    cout << "Please enter how long the call will be in minutes: ";
    cin >> callDuration;

    float totalHours, totalCost;

    totalHours = (float)hour + ((float)minute / 60);

    //Determining day of the week
    if (day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr") {
        
        //Determining the time of the day. (Before 6am or after 6pm)
        if (totalHours < 8.0 || totalHours > 18.0)
            rate = 2;
        else
            rate = 1;
    }
    else if (day == "Sa" || day == "Su")
        rate = 3;
    
    else
        cout << "Please enter a valid day as indicated!\n";
    
    // Calculate the total cost
    switch (rate) {
    case 1:
        totalCost = PEAK_RATE * callDuration;
        break;

    case 2:
        totalCost = NONPEAK_RATE * callDuration;
        break;

    case 3:
        totalCost = WEEKEND_RATE * callDuration;
        break;
    
    default:
        break;
    }
    
    if (rate != 0)
        cout << "The total cost of the call is $" << totalCost << endl;

    return 0;
}
