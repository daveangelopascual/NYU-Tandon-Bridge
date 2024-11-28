#include <iostream> 
using namespace std;


int main() {

    cout << "Section A" << endl;
    int numEvenA, i = 1, j = 1;

    cout << "Please enter a positive integer: ";
    cin >> numEvenA;
    
    //j is incremented for all integers
    //i is only incremented when output is even
    while (i <= numEvenA) {
        if (j % 2 == 0) {
            cout << j << endl;
            i++;
            j++;
        }
        else
            j++;  
    }


    cout << "Section B" << endl;
    int numEvenB, x = 1;

    cout << "Please enter a positive integer: ";
    cin >> numEvenB;

    for (int x = 1; x <= 2 * numEvenB; x++) {
        if (x % 2 == 0)
            cout << x << endl;
        
        else
            continue;
    }

    return 0;
}
