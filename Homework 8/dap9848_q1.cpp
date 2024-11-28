#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
void searchArray(int arr[], int arrSize, int minVal);
int main(){

    const int NUMBERS_SIZE = 20;
    int numbers[NUMBERS_SIZE], minInt;

    cout << "Please enter " << NUMBERS_SIZE << " integers separated by a space:\n";
    for (int i = 0; i < NUMBERS_SIZE; i++)
        cin >> numbers[i];
    
    minInt = minInArray(numbers, NUMBERS_SIZE);

    cout << "The minimum value is " << minInt << ", and it is located in the following indices: ";
    searchArray(numbers, NUMBERS_SIZE, minInt);

    return 0;
 }

int minInArray(int arr[], int arrSize){
    int minValue = arr[0];

    for (int i = 1; i < arrSize; i++){
        if (minValue > arr[i])
            minValue = arr[i];
    }
    return minValue;
 }

void searchArray(int arr[], int arrSize, int minVal){
    for (int i = 0; i < arrSize; i++){
        if (minVal == arr[i])
            cout << i << " ";
    }
    cout << endl;
}