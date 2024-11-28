#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main(){
    int input = 0;

    cout << "Please enter a positive integer >= 2: ";
    while (input < 2){
        cin >> input;
        if (input < 2)
            cout << "Try again! Please enter a positive integer >= 2: ";
    }
    
    cout << "All the perfect numbers between 2 and " << input << " are: \n";
    for (int i = 2; i <= input; i++){
        if (isPerfect(i) == true){
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "All pairs of amicable numbers that are between 2 and " << input << " are: \n";
    for (int i = 2; i <= input; i++){
        int numDivisorsA = 0, sumDivisorsA = 0, numDivisorsB = 0, sumDivisorsB = 0;
        analyzeDividors(i, numDivisorsA, sumDivisorsA);
        analyzeDividors(sumDivisorsA, numDivisorsB, sumDivisorsB);
        if (i == sumDivisorsB && i < sumDivisorsA && sumDivisorsA < input){
            cout << i << " & " << sumDivisorsA << "\t";
        }
    }
    cout << endl;
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){
    double runtime = sqrt(num);
    for (int i = 1; i < runtime; i++){
        if (num % i == 0){
            outCountDivs++;
            outSumDivs += i;
        }
    }
    for (int j = runtime; j > 1; j--){
        if (num % j == 0){
            outCountDivs++;
            outSumDivs += (num / j);
        }
    }
}

bool isPerfect(int num){
    int numDivisors = 0, sumDivisors = 0;
    analyzeDividors(num, numDivisors, sumDivisors);
    if (num == sumDivisors){
        return true;
    }
    else
        return false;
}
