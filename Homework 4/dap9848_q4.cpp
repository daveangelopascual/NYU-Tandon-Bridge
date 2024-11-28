#include <iostream>
#include <cmath>
using namespace std;

int main(){

    cout << "Section A\n";
    int lengthSequenceA, inputA, productA = 1;
    double geoMeanA;
    
    cout << "Please enter length of sequence: \n"; 
    cin >> lengthSequenceA;
    cout << "Please enter your sequence:\n";

    //Calculates product of the sequence
    for (int i = 0; i < lengthSequenceA; i++){
        cin >> inputA;
            productA *= inputA;
    }
    geoMeanA = pow(productA, 1.0/lengthSequenceA);

    cout << "The geometric mean is: " << geoMeanA << endl;





    cout << "Section B\n";
    int lengthSequenceB = 0, inputB = 0, productB = 1;
    double geoMeanB;
    
    cout << "Please enter a non-empty sequence of positive integers, each on in a separate line. End your sequence by typing -1:\n";

    //Calculates product of the sequence and increments sequence length counter
    while (inputB != -1){
        cin >> inputB;
        if (inputB != -1){
            productB *= inputB;
            lengthSequenceB++;
        }
        //Stops loop when -1 is provided as the value
        else if (inputB == -1)
            break;
        }
    geoMeanB = pow(productB, 1.0/lengthSequenceB);

    cout << "The geometric mean is: " << geoMeanB << endl;

    return 0;
}
