#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
void printArray(int arr[], int arrSize);

int main(){
    
    int input;
    cout << "Please enter a positive integer: ";
    cin >> input;
    input++;

    int randomArr[input];
    srand(time(0));

    cout << "Your array is:\n";
    for (int i = 0; i < input; i++){
        randomArr[i] = (rand() % input); //creating random array
        cout << randomArr[i] << " ";
    }
    cout << endl << "The missing values in your array from 0 to " << input - 1 << " are:\n";

    int missingArrSize = 0;
    int *missingArr = findMissing(randomArr, input, missingArrSize);
    printArray(missingArr, missingArrSize);
    delete [] missingArr;
}

int* findMissing(int arr[], int n, int& resArrSize){
    int boolArr[n]; // boolArr[] defines if the number was present in the array... 0 = false, 1 = true
    for (int i = 0; i < n; i++)
        boolArr[i] = 0;

    for (int i = 0; i < n; i++)
        boolArr[arr[i]] = 1;
    
    int *newArr = new int[n];
    for (int i = 0; i < n; i++){
        if (boolArr[i] == 0){ //if the value was missing in the original array
            *(newArr + resArrSize) = i;
            resArrSize++;
        }
    }
    return newArr;
}

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}