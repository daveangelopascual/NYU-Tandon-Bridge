#include <iostream>
using namespace std;

int main(){
    int input;
    cout << "Enter a decimal number:\n";
    cin >> input;

    /*
    let i be the value after the iterations of division by 2
    let j be powers of 2 in binary (in this case powers of 10 to utilize the integer data type)
    */
    int i = input, j = 0, binaryTotal = 0;  
    
    while (i > 0){

        //if it is even, binary digit is 0
        if (i % 2 == 0){
            i /= 2;
        }

        //if it is odd, binary digit is 1
        else if (i % 2 == 1){
            i = (i - 1) / 2;
            int binary = 1;
            //iterating the powers of 10
            for (int k = 0; k < j; k++){
                binary *= 10;
            }
            binaryTotal += binary;
        }
        j++;
    }
    
    cout << "The binary representation of " << input << " is " << binaryTotal << endl;

    return 0;
}
