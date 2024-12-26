#include <iostream>
using namespace std;

int moveForward2(int arr[], int index);
int main(){
    int spaces = 6;
    int gameBoard[6] = {0, 33, 55, 52, 17, 19};

    int cost = moveForward2(gameBoard, spaces); 
    cout << "Lowest Cost: " << cost << endl;
}

int moveForward1(int arr[], int index){
    if (index == 1) //when index is 1, there is only one option from index 0.
        return (arr[0] + arr[1]);

    else if (index == 2){ //when index is 2, there are 2 options from index 0. (incrementing twice or skipping)
        if ((arr[0] + arr[1] + arr[2]) < (arr[0] + arr[2]))
            return (arr[0] + arr[1] + arr[2]);

        else
            return (arr[0] + arr[2]);
    }
    else{
        if (arr[index - 1] < arr[index - 2]) //checks if moving adjacent is less costly than skipping
            return (arr[index] + moveForward1(arr, index - 1));//runs adjacent
        else
            return (arr[index] + moveForward1(arr, index - 2));//runs skip
    }
}

int moveForward2(int arr[], int index){
    if (index == 2) //when index is 2, there is only one option from index 0.
        return (arr[0] + arr[1]);

    else if (index == 3){ //when index is 3, there are 2 options from index 0. (incrementing twice or skipping)
        if ((arr[0] + arr[1] + arr[2]) < (arr[0] + arr[2]))
            return (arr[0] + arr[1] + arr[2]);

        else
            return (arr[0] + arr[2]);
    }
    else{
        if (arr[index - 2] < arr[index - 3]) //checks if moving adjacent is less costly than skipping
            return (arr[index - 1] + moveForward2(arr, index - 1));//runs adjacent
        else
            return (arr[index - 1] + moveForward2(arr, index - 2));//runs skip
    }
}