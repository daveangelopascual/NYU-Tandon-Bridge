#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArray(int arr[], int arrSize);

int main(){
    const int arrSize = 6;
    int arr[arrSize] = {3, -1, -3, 0, 6, 4};

    cout << "Array 1\n";
    int outPosArrSize = 0;
    printArray(arr, arrSize);
    int* newArr1 = getPosNums1(arr, arrSize, outPosArrSize);
    //cout << newArr1 << endl;
    printArray(newArr1, outPosArrSize);
    delete [] newArr1;
    cout << endl;

    cout << "Array 2\n";
    outPosArrSize = 0;
    printArray(arr, arrSize);
    int* newArr2 = getPosNums2(arr, arrSize, &outPosArrSize);
    //cout << newArr2 << endl;
    printArray(newArr2, outPosArrSize);
    delete [] newArr2;
    cout << endl;
    
    cout << "Array 3\n";
    int* newArr3 = new int[arrSize];
    outPosArrSize = 0;
    printArray(arr, arrSize);
    getPosNums3(arr, arrSize, newArr3, outPosArrSize);
    printArray(newArr3, outPosArrSize);
    delete [] newArr3;
    cout << endl;

    cout << "Array 4\n";
    int* newArr4 = new int[arrSize];
    outPosArrSize = 0;
    printArray(arr, arrSize);
    getPosNums4(arr, arrSize, &newArr4 ,&outPosArrSize);
    printArray(newArr4, outPosArrSize);
    delete [] newArr4;
    cout << endl;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int *newArr = new int[arrSize];

    for (int i = 0; i < arrSize; i++){
        if (*(arr+i) > 0){
            *(newArr + outPosArrSize) = arr[i];
            outPosArrSize++;
        }
    }
    return newArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int *newArr = new int[arrSize];

    for (int i = 0; i < arrSize; i++){
        if (*(arr+i) > 0){
            *(newArr + *outPosArrSizePtr) = arr[i];
            (*outPosArrSizePtr)++;
        }
    }
    return newArr;

}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int *newArr = new int[arrSize];

    for (int i = 0; i < arrSize; i++){
        if (*(arr+i) > 0){
            *(outPosArr + outPosArrSize) = arr[i];
            (outPosArrSize)++;
        }
    }
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int *newArr = new int[arrSize];

    for (int i = 0; i < arrSize; i++){
        if (*(arr+i) > 0){
            *(*outPosArrPtr + *outPosArrSizePtr) = arr[i];
            (*outPosArrSizePtr)++;
        }
    }
}

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}