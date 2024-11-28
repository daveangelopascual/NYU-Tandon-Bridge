#include <iostream>
using namespace std;

void printShiftedTriangle(int lines, int shift, char symbol);
void printPineTree(int triangleCount, char symbol);

int main(){
    int triangleCount;
    char character;
    cout << "Please enter how many triangles in the tree: ";
    cin >> triangleCount;
    cout << "Please enter a character filling the tree: ";
    cin >> character;

    printPineTree(triangleCount, character);

    return 0;
}

void printShiftedTriangle(int lines, int shift, char symbol){
    int length = 2 * lines - 1;
    int numSpaces = lines - 1;
    int numChar = 1;

    for (int i = 1; i <= lines; i++){
        for (int j = 0; j < shift; j++)
            cout << " ";

        for (int k = 0; k < numSpaces; k++)
            cout << " ";

        for (int l = 0; l < numChar; l++)
            cout << symbol;
        
        numSpaces -= 1;
        numChar += 2;
        cout << endl;
    }
}
void printPineTree(int triangleCount, char symbol){
    int shift = triangleCount, lines = 2;
    for (int i = 0; i < triangleCount; i++){
        printShiftedTriangle(lines, shift, symbol);
        lines++;
        shift--;
    }
}
