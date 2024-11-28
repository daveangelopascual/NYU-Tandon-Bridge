#include <iostream>
using namespace std;

int main(){

    int input;
    cout << "Please enter a postive integer:\n";
    cin >> input;

    for (int i = 1; i <= input; i++) {
        
        for (int j = 1; j <= input; j++) {
            
            int product = i * j;
            cout << product << "\t";
        }
        cout << endl;
    }
    return 0;
}
