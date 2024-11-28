#include <iostream>
using namespace std;

int main(){
    int input;

    cout << "Please enter a positive integer: ";
    cin >> input;

    int length = 2 * input - 1;
    int numAstericks, numSpaces;
    //let i be the row value
    int i=0;
    
    //Top Half
    while (i < input){
        //Calculates numbers of spaces and astericks based on row value
        numSpaces = 2 * i;
        numAstericks = length - numSpaces;
            
        if (numSpaces != 0){
            for (int j = 0; j < numSpaces / 2; j++){
                cout << " ";
            }
        }
        for (int k = 0; k < numAstericks; k++){
            cout << "*";
        }
        if (numSpaces != 0){
            for (int l = 0; l < numSpaces / 2; l++){
                cout << " ";
            }
        }
        cout << endl;
        
        //breaks the loop when i reaches the expected row value for the top section
        if (i < input-1)
            i++;
        else
            break;
    }

    //Bottom Half
    while (i >= 0){
        //Calculates numbers of spaces and astericks based on row value
        numSpaces = i * 2;
        numAstericks = length - numSpaces;
            
        if (numSpaces != 0){
            for (int x = 0; x < numSpaces / 2; x++){
                cout << " ";
            }
        }
        for (int y = 0; y < numAstericks; y++){
            cout << "*";
        }
        if (numSpaces != 0){
            for (int z = 0; z < numSpaces / 2; z++){
                cout << " ";
            }
        }
        i--;
        cout << endl;

    }
    return 0;
}
