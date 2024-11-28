#include <iostream>
#include <string>
using namespace std;

int main(){
    string first, middle, last;

    cout << "Please enter full name as: (first middle (or initial) last)\n";
    cin >> first >> middle >> last;

    cout << last << ", " << first << " " << middle[0] << ".\n";

    return 0;
}