#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main(){
    int startDay = 0, year;

    cout << "Please enter a calender year: ";
    cin >> year;
    cout << "Please enter the starting day for " << year << " (Mon = 1, Tues = 2, ..., Sun = 7): ";
    while (startDay < 1 || startDay > 7){
        cin >> startDay;
        if (startDay < 1 || startDay > 7)
            cout << "Try Again! Please enter a valid day (Mon = 1, Tues = 2, ..., Sun = 7): ";
    }

    printYearCalender(year, startDay);

    return 0;
}

int printMonthCalender(int numOfDays, int startingDay){
    int currentDay = startingDay;
    cout << "Mon\tTues\tWed\tThr\tFri\tSat\tSun\n";
    for (int i = 1; i < startingDay; i++)
        cout << "\t";
    for (int i = 1; i <= numOfDays; i++){
        if (currentDay >= 7){
            currentDay %= 7;
            cout << i << endl;
        }
        else
            cout << i << "\t";
        currentDay++;
    }
    if (currentDay != 1)
        cout << endl;
        
    return --currentDay;
}

bool isLeapYear(int year){
    if (year % 4 == 0){
        if (year % 400 == 0 || year % 100 != 0)
            return true;
        else
            return false;
    }
    else
        return false;
}

void printYearCalender(int year, int startingDay){
    int numDays;
    for (int i = 1; i <= 12; i++){
        cout << endl;
        switch (i){
        case 1:
            cout << "January " << year << endl;
            numDays = 31;
            startingDay = printMonthCalender(numDays,startingDay);
            break;
    
        case 2:
            cout << "Feburary " << year << endl;
            if (isLeapYear(year) == true)
                numDays = 29;
            else
                numDays = 28;
            startingDay = printMonthCalender(numDays,++startingDay);
            break;

        case 3:
            cout << "March " << year << endl;
            numDays = 31;
            startingDay = printMonthCalender(numDays,++startingDay);
            break;

        case 4:
            cout << "April " << year << endl;
            numDays = 30;
            startingDay = printMonthCalender(numDays,++startingDay);
            break;

        case 5:
            cout << "May " << year << endl;
            numDays = 31;
            startingDay = printMonthCalender(numDays,++startingDay);
            break;

        case 6:
            cout << "June " << year << endl;
            numDays = 30;
            startingDay = printMonthCalender(numDays,++startingDay);
            break;
        
        case 7:
            cout << "July " << year << endl;
            numDays = 31;
            startingDay = printMonthCalender(numDays,++startingDay);
            break;

        case 8:
            cout << "August " << year << endl;
            numDays = 31;
            startingDay = printMonthCalender(numDays,++startingDay);
            break;
        
        case 9:
            cout << "September " << year << endl;
            numDays = 30;
            startingDay = printMonthCalender(numDays,++startingDay);
            break;
        
        case 10:
            cout << "October " << year << endl;
            numDays = 31;
            startingDay = printMonthCalender(numDays,++startingDay);
            break;
        
        case 11:
            cout << "November " << year << endl;
            numDays = 30;
            startingDay = printMonthCalender(numDays,++startingDay);
            break;
        
        case 12:
            cout << "December " << year << endl;
            numDays = 31;
            startingDay = printMonthCalender(numDays,++startingDay);
            break;
        }
    }
}
