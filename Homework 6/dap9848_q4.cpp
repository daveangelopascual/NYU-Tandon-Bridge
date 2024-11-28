#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main(){
    int input;
    cout << "Please enter a positive integer >= 2: ";
    cin >> input;

    printDivisors(input);

    return 0;
}

void printDivisors(int num) {
    double runtime = sqrt(num);
    for (int i = 1; i <= runtime; i++) {
        if (num % i == 0){
            cout << i << " ";
        }
    }
    for (int j = runtime - 1; j > 0; j--) {
        if (num % j == 0) {
            cout << num / j << " ";
        }
    }
    cout << endl;
}
