#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void getValKey(int& validCode);
void checkInput(int user, int valid);

int main(){
    int inputCode, validCode = 0;

    cout << "Please enter your PIN according to the following mapping:\n";
    cout << "PIN: 0 1 2 3 4 5 6 7 8 9\n";
    cout << "NUM: ";
    getValKey(validCode);
    cin >> inputCode;
    checkInput(inputCode,validCode);

    return 0;
}

void getValKey(int& validCode){
    const int PASSWORD_SIZE = 5, PASSWORD[PASSWORD_SIZE]={5,2,9,4,1};
    int randomNum[10];
    srand(time(0));

    for (int i = 0; i < 10; i++) {
        randomNum[i] = (rand() % 3) + 1;
        cout << randomNum[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < PASSWORD_SIZE; i++)
        validCode = (validCode * 10) + randomNum[PASSWORD[i]];
}

void checkInput(int user, int valid){
    if (user == valid)
        cout << "Your PIN is correct\n";
    else
        cout << "Your PIN is not correct\n";
}