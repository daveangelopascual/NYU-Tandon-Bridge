#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[],int& arrSize);
void splitParity(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main(){
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 1, 6, 1, 12};
    int arr3Size = 5;
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
return 0; 
}

void reverseArray(int arr[], int arrSize){
    int swap;
    for (int i = 0; i < (arrSize / 2); i++){
        swap = arr[i];
        arr[i] = arr[arrSize - i - 1];
        arr[arrSize - i - 1] = swap;
    }
}

void removeOdd(int arr[],int& arrSize){
    int decrement = 0;
    for (int i = 0; i < arrSize; i++){
        if (arr[i + decrement] % 2 == 1){
            for (int j = i; j < arrSize; j++)
                arr[i] = arr[i + 1 + decrement];
            decrement++;
        }
        else
            arr[i] = arr[i + decrement];
    }
    arrSize -= decrement;
}

void splitParity(int arr[], int arrSize){
    int i = 0, j = arrSize, swap;
    while (i != j){
        if (arr[i] % 2 == 1)
            i++;
        else if (arr[j-1] % 2 == 0)
            j--;
        else if (arr[i] % 2 == 0 && arr[j-1] % 2 == 1){
            swap = arr[i];
            arr[i] = arr[j-1];
            arr[j-1] = swap;
        }
    }
}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}