#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

class Money {
private:
    long dollars;
    int cents;
public:
    //Constructor
    Money() : dollars(0), cents(0) {}
    Money(long dollars, int cents) : dollars(dollars), cents(cents) {};

    //Accessors
    long getDollars() const {return dollars; };
    int getCents()const {return cents; };

    //Mutators
    void setDollars(long newDollars) {dollars = newDollars; };
    void setCents(int newCents) {cents = newCents; };

    //Overloading Operators
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount);

    //Input & Output
    friend istream& operator>>(istream& ins, Money& amount);
    friend ostream& operator<<(ostream& outs, const Money& amount);
};

istream& operator>>(istream& ins, Money& amount) {
    char dollarSign;
    ins >> dollarSign; 

    double value;
    ins >> value;
    
    amount.dollars = static_cast<long>(value);
    amount.cents = static_cast<int>((value - amount.dollars) * 100);  
    return ins;
}

ostream& operator<<(ostream& outs, const Money& amount) {
    outs << "$" << amount.getDollars() << ".";
    if (amount.getCents() < 10) outs << "0";
    outs << amount.getCents();
    return outs;
}

Money operator +(const Money& amount1, const Money& amount2) {
    long total = ((amount1.dollars + amount2.dollars) * 100) + amount1.cents + amount2.cents;
    return Money(total/100, total%100);
}

Money operator -(const Money& amount1, const Money& amount2) {
    long total = ((amount1.dollars - amount2.dollars) * 100) + amount1.cents - amount2.cents;
    return Money(total/100, total%100);
}

Money operator -(const Money& amount) {
    long total = ((amount.dollars * 100) + amount.cents)* -1 ;
    return Money(total/100, total%100);
}

class Check {
private:
    int checkNum;
    Money checkVal;
    bool cashed;

public:
    //Constructor
    Check(int checkNum = 0, Money checkVal = Money(0, 0), bool cashed = false) : checkNum(checkNum), checkVal(checkVal), cashed(cashed) {};

    //Accessors
    int getCheckNum() const {return checkNum; };
    Money getCheckVal() const {return checkVal; } ;
    bool getBoolCashed() const {return cashed; } ;

    //Mutators
    void setCheckNum(int newCheckNum) {checkNum = newCheckNum; };
    void setCheckVal(Money newCheckVal) {checkVal = newCheckVal; };
    void setBoolCashed(bool newBoolCashed) {cashed = newBoolCashed; };

    //Input & Ouput
    void input() {
        cout << "Enter check number: ";
        cin >> checkNum;
        cout << "Enter check amount (e.g., $XXX.XX): ";
        cin >> checkVal;
        cout << "Has the check been cashed? (1 for yes, 0 for no): ";
        cin >> cashed;
    }
    
    void output() const {
    cout << "Check Number: " << checkNum 
         << ", Amount: " << checkVal 
         << ", Cashed: " << (cashed ? "Yes" : "No") 
         << "\n";
}
};

void sortChecks(Check checks[], int size) {
    Check swap;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (checks[j].getCheckNum() > checks[j + 1].getCheckNum()) {
                swap = checks[j];
                checks[j] = checks[j+1];
                checks[j+1] = swap;
            }
        }
    }
}

int main() {
    int numChecks, numDeposits;
    Money oldBalance, newBalance, totalDeposits(0,0), totalCashedChecks(0,0);

    // Input old balance
    cout << "Enter old account balance: ";
    std::cin >> oldBalance;

    // Input checks
    cout << "Enter the number of checks: ";
    cin >> numChecks;
    Check checks[numChecks]; // Setting array to num of checks

    for (int i = 0; i < numChecks; ++i) {
        cout << "Enter details for check " << i + 1 << ":\n";
        checks[i].input();
    }

    //Sort checks by check number
    sortChecks(checks, numChecks);

    //Input deposits
    cout << "Enter the number of deposits: ";
    cin >> numDeposits;
    Money deposits[numDeposits]; // setting array to num of deposits

    for (int i = 0; i < numDeposits; ++i) {
        cout << "Enter deposit amount " << i + 1 << ": ";
        cin >> deposits[i];
        totalDeposits = totalDeposits + deposits[i];
    }

    //Separate cashed and uncashed checks
    Check cashedChecks[numChecks], uncashedChecks[numChecks];
    int cashedIndex = 0, uncashedIndex = 0;

    for (int i = 0; i < numChecks; ++i) {
        if (checks[i].getBoolCashed()) {
            totalCashedChecks = totalCashedChecks + checks[i].getCheckVal();
            cashedChecks[cashedIndex++] = checks[i];
        } else {
            uncashedChecks[uncashedIndex++] = checks[i];
        }
    }

    //Calculate new balance
    newBalance = oldBalance + totalDeposits - totalCashedChecks;

    //Output results
    cout << "\nOld Balance: " << oldBalance << "\n";
    cout << "Total Deposits: " << totalDeposits << "\n";
    cout << "Total Cashed Checks: " << totalCashedChecks << "\n";
    cout << "New Balance: " << newBalance << "\n";

    //Display cashed and uncashed checks
    cout << "\nCashed Checks:\n";
    for (int i = 0; i < cashedIndex; ++i) {
        cashedChecks[i].output();
    }

    cout << "\nUncashed Checks:\n";
    for (int i = 0; i < uncashedIndex; ++i) {
        uncashedChecks[i].output();
    }

    return 0;
}
