#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


void findMinMax(vector<int>& nums, int lowLeft, int highLeft, int highRight, vector<int>& minmax) {
    int lowRight = highLeft + 1;

    while (lowLeft <= highLeft && lowRight <= highRight) {
        if (nums[lowLeft] < nums[lowRight]) {
            if (nums[lowLeft] < minmax[0])
                minmax[0] = nums[lowLeft];
            if (nums[lowRight] > minmax[1])
                minmax[1] = nums[lowRight];
            lowLeft++;
        }
        else {
            if (nums[lowRight] < minmax[0])
                minmax[0] = nums[lowRight];
            if (nums[lowLeft] > minmax[1])
                minmax[1] = nums[lowLeft];
            lowRight++;
        }
    }

    while (lowLeft <= highLeft) {
        if (nums[lowLeft] < minmax[0])
            minmax[0] = nums[lowLeft];
        if (nums[lowLeft] > minmax[1])
            minmax[1] = nums[lowLeft];
        lowLeft++;
    }
        
    while (lowRight <= highRight) {
        if (nums[lowRight] < minmax[0])
            minmax[0] = nums[lowRight];
        if (nums[lowRight] > minmax[1])
            minmax[1] = nums[lowRight];
        lowRight++;
    }
}

void divideNconquer(vector<int>& nums, int start, int end, vector<int>&  minmax){
    int mid;
    if (start == end) {
        if (nums[start] < minmax[0])
            minmax[0] = nums[start];
        if (nums[start] > minmax[1])
            minmax[1] = nums[start];
        return;
    }
    
    else {
        mid = (start + end) / 2;
        divideNconquer(nums, start, mid,  minmax);
        divideNconquer(nums, mid+1, end,  minmax);
        findMinMax(nums, start, mid, end,  minmax);
    }
}

void divideNconquer(vector<int>& data, vector<int>&  minmax) {
    minmax[0] = data[0];
    minmax[1] = data[0];
    divideNconquer(data, 0, data.size() -1,  minmax);
}

void printVector(const vector<int>& data) {
    cout << "[";
    for (int i = 0; i < data.size(); ++i) {
        cout << data[i];
        if (i != data.size() - 1)
            cout << ", ";
    }
    cout << "]\n";
}

int main() {
    srand(time(0));
    vector<int> data(11);
    vector<int> result(2);

    for (int i = 0; i < 11; i++)
        data[i] = rand()%100;
    
    cout << "Vector: \n";
    printVector(data);
    divideNconquer(data, result);
    cout << "\nMin and Max of Vector: \n";
    printVector(result);
    
    return 0;
}