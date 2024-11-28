#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main(){
    int arr1Size = 6;
    int arr1[6] = {5, 2, 11, 7, 6, 4};
    printArray(arr1, arr1Size);
    oddsKeepEvensFlip(arr1, arr1Size);
    printArray(arr1, arr1Size);

    cout << endl;

    int arr2Size = 6;
    int arr2[6] = {5, 2, 6, 4, 11, 7};
    printArray(arr2, arr1Size);
    oddsKeepEvensFlip(arr2, arr1Size);
    printArray(arr2, arr1Size);

    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize){
    int tempArr[arrSize];
    for (int i = 0; i < arrSize; i++)
        tempArr[i] = arr[i];
    
    int j = 0;
    for (int i = 0; i < arrSize; i++){
        if (tempArr[i] %2 == 1){
            arr[j] = tempArr[i];
            j++;
        }
    }
    
    for (int i = arrSize - 1; i > 0 ; i--){
        if (tempArr[i] %2 == 0){
            arr[j] = tempArr[i];
            j++;
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