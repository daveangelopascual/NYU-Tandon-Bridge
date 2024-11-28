#include <iostream>
using namespace std;

int fib(int n);

int main(){
    int input, fibValue;
    cout << "Please enter a positive integer: ";
    cin >> input;

    fibValue = fib(input);
    cout << fibValue <<endl;

    return 0;
}

int fib(int n) {
    int nValue, n1Value = 1, n2Value = 1;

    for (int i = 1; i <= n; i++){
            if (i == 1 || i == 2)
                nValue = 1;

            else {
                nValue = n1Value + n2Value;
                n1Value = n2Value;
                n2Value = nValue;
            }
        }
    return nValue;
}
