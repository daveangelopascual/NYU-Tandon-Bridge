#include <iostream>
#include <string>
using namespace std;

const int LETTER_COUNT = 26;

void countChar(string string, int numChar[]);
bool compareChar(int arrChar1[], int arrChar2[]);

int main(){
    string str1, str2;
    int char1Count[LETTER_COUNT] = {0}, char2Count[LETTER_COUNT] = {0};
    bool result;

    cout << "Please enter first line of text:\n";
    getline(cin,str1);
    cout << "Please enter second line of text:\n";
    getline(cin,str2);

    countChar(str1, char1Count);
    countChar(str2, char2Count);
    result = compareChar(char1Count, char2Count);

    if (result == false)
        cout << "These two strings are not anagrams!\n";
    else
        cout << "These two strings are anagrams!\n";

    return 0;
}

void countChar(string string, int numChar[]){
    char alphabetLower[LETTER_COUNT] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char alphabetUpper[LETTER_COUNT] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    for (int i = 0; i < string.length(); i++){
        if (string[i] == ' ' || string[i] == '.' || string[i] == ',')
            continue;
        else{
            for (int j = 0; j < LETTER_COUNT; j++){
                if (string[i] == alphabetLower[j] || string[i] == alphabetUpper[j])
                    numChar[j]++;
            }
        }
    }
}

bool compareChar(int arrChar1[], int arrChar2[]){
    for (int i = 0; i < LETTER_COUNT; i++) {
        if (arrChar1[i] != arrChar2[i]) {
            return false;
        }
    }
    return true;
}
    