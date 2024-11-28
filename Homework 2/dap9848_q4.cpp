#include <iostream>
using namespace std;


int main() {

    int integer1, integer2;

    cout << "Please enter two positive integers, separated by a space: \n";
    cin >> integer1 >> integer2;

    cout << integer1 << " + " << integer2 << " = " << integer1 + integer2 << endl << endl;
    
    cout << integer1 << " - " << integer2 << " = " << integer1 - integer2 << endl << endl;

    cout << integer1 << " * " << integer2 << " = " << integer1 * integer2 << endl << endl;

    cout << integer1 << " / " << integer2 << " = " << (float)integer1 / (float)integer2 << endl << endl;

    cout << integer1 << " div " << integer2 << " = " << integer1 / integer2 << endl << endl;

    cout << integer1 << " mod " << integer2 << " = " << integer1 % integer2 << endl;

    return 0;

}
