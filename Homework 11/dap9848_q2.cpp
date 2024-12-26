#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main(){
    int arrSize = 6;
    int arr[6] = {1,2,3,4,5,6};

    int sumSquares = sumOfSquares(arr, arrSize);
    cout << sumSquares << endl;

    bool sorted = isSorted(arr, arrSize);
    if (sorted == true)
        cout << "Array is sorted!" << endl;
    
    else
        cout << "Array not sorted!" << endl;
}

int sumOfSquares(int arr[], int arrSize){
    if (arrSize == 1)
        return (arr[0] * arr[0]);
    
    else
        return (((arr[arrSize - 1] * arr[arrSize - 1]) + sumOfSquares(arr, arrSize - 1)));
}

bool isSorted(int arr[], int arrSize){
    if (arrSize == 2)
        return (arr[0] <= arr[1]);
    
    else{
        bool res = isSorted(arr, arrSize - 1);
        if (res == true)
            return (arr[arrSize - 2] <= arr[arrSize - 1]);
        
        else
            return false;
        return true;
    }
}