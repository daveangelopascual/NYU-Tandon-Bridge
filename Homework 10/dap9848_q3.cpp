#include <iostream>
#include <vector>
using namespace std;

void main1();
int* resizeArr(int arr[], int &arrSize);
void main2();


int main(){

    cout << "\nmain1() - Using Arrays\n";
    main1();
    cout << "\nmain2() - Using Vectors\n";
    main2();

    return 0;
}

void main1(){
    
    int input1, input1Count = 0, arrSize = 5;
    int* arr = new int[arrSize];
    cout << "Please enter a sequence of positive integers, each in a separate line.\n";
    cout << "End your input by typing -1.\n";
    
    while (input1 != -1){
        cin >> input1;
        while (input1 < -1){ //input validation
            cout << "Please only enter positive integers, or to end the sequence, type -1!\n";
            cin >> input1;
        }
        
        if (input1 != -1){
            arr[input1Count] = input1; //assigining each number to a part of the array
            input1Count++;
        }
        if (input1Count >= arrSize) //if there are more elements than what the array can hold, create new array.
            arr = resizeArr(arr, arrSize);
    }
    int num1, num1Count = 0;
    cout << "Please enter a number you want to search.\n";
    cin >> num1;

    for (int i = 0; i < input1Count; i++){
        if (num1 == arr[i])
            num1Count++;
    }
    if (num1Count == 0)
        cout << num1 << " does not show in lines.\n";

    else{
        int j = 0;
        cout << num1 << " shows in lines ";
        for (int i = 0; i < input1Count; i++){
            if (num1 == arr[i]){
                j++;
                if (j < num1Count)
                    cout << i + 1 << ", ";
                else
                    cout << i + 1 << ".\n";
            }
        }
    }
    delete [] arr;
}

int* resizeArr(int arr[], int &arrSize){
    int newArrSize = arrSize * 2;
    int* newArr = new int[arrSize];
    
    for (int i = 0; i < arrSize; i++)
        *(newArr + i) = arr[i];
    
    delete [] arr;
    arrSize = newArrSize;
    
    return newArr;
}


void main2(){
    int input2, input2Count = 0;
    vector<int> v;
    cout << "Please enter a sequence of positive integers, each in a separate line.\n";
    cout << "End your input by typing -1.\n";
    
    while (input2 != -1){
        cin >> input2;
        while (input2 < -1){ //input validation
            cout << "Please only enter positive integers, or to end the sequence, type -1!\n";
            cin >> input2;
        }

        if (input2 != -1){ //adds number to the end of the vector
            v.push_back(input2);
            input2Count++;
        }
    }
    int num2, num2Count = 0;
    cout << "Please enter a number you want to search.\n";
    cin >> num2;

    for (int i: v){ //ranged for loop checks for value match
        if (num2 == i)
            num2Count++;
    }
    if (num2Count == 0)
        cout << num2 << " does not show in lines.\n";

    else{
        int k = 0;
        cout << num2 << " shows in lines ";
        for (int i = 0; i < input2Count; i++){
            if (num2 == v[i]){
                k++;
                if (k < num2Count)
                    cout << i + 1 << ", ";
                else
                    cout << i + 1 << ".\n";
            }
        }
    }
}
