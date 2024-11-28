#include <iostream>
using namespace std;


int main() {

    int daysJohn, hoursJohn, minutesJohn, daysBill, hoursBill, minutesBill;

    //Inputs for John's Days, Hours, and Minutes
    cout << "Please enter the number of days John has worked: ";
    cin >> daysJohn;
    cout << "Please enter the number of hours John has worked: ";
    cin >> hoursJohn;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> minutesJohn;
    cout << "\n\n";

    //Inputs for Bill's Days, Hours, and Minutes
    cout << "Please enter the number of days Bill has worked: ";
    cin >> daysBill;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> hoursBill;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> minutesBill;
    cout << "\n\n";

    int totalDays, totalHours, totalMinutes, convertedDays, convertedHours;
    const int MINUTES_IN_HOUR = 60, HOURS_IN_DAY = 24;

    //Conversions and Calcualtions for Minutes
    totalMinutes = minutesJohn + minutesBill;
    convertedHours = totalMinutes / MINUTES_IN_HOUR;
    totalMinutes -= convertedHours * MINUTES_IN_HOUR;
    
    //Conversions and Calcualtions for Hours
    totalHours = hoursJohn + hoursBill + convertedHours;
    convertedDays = totalHours / HOURS_IN_DAY;
    totalHours -= convertedDays * HOURS_IN_DAY;

    //Calculations for Days
    totalDays = daysJohn + daysBill + convertedDays;

    cout << "The total time both of them worked together is: " << totalDays << " days, " << totalHours << " hours and " << totalMinutes <<" minutes.\n";

    return 0;
    
}
