#include <iostream>
#include <string>
using namespace std;

const int LETTER_COUNT = 26;

void countWord(string string);
void countChar(string string);
void printChar(int numChar[]);

int main(){
    string str1;

    cout << "Please enter a line of text:\n";
    getline(cin,str1);

    countWord(str1);
    countChar(str1);

    return 0;
}

void countWord(string string){
    int i = 0, wordCount = 0;
    
    while (i < string.length()){
        //if there is no comma, space, and period, there is only one word
        if (string.find(" ", i) == string::npos && string.find(".", i) == string::npos && string.find(",", i) == string::npos){
            wordCount++;
            i = string.length();
        }
        //if the char is not a delimiter, find the next index of any delimiter.
        else if (string[i] != ' ' && string[i] != ',' && string[i] != '.'){
            int nextSpace = string.length(), nextComma = string.length(), nextPeriod = string.length();
            
            if (string.find(' ', i) != string::npos)
                nextSpace = string.find(' ', i);
            if (string.find(',', i) != string::npos)
                nextComma = string.find(',', i);
            if (string.find('.', i) != string::npos)
                nextPeriod = string.find('.', i);
                
            if (nextSpace <= nextComma && nextSpace <= nextPeriod){
                wordCount++;
                i = nextSpace + 1;
            }
            else if (nextComma <= nextSpace && nextComma <= nextPeriod){
                wordCount++;
                i = nextComma + 1;
            }
            else if (nextPeriod <= nextSpace && nextPeriod <= nextComma){
                wordCount++;
                i = nextPeriod + 1;
            }    
        }
        //if there are consecutive spaces, commas, or periods
        else
            i++;
    }
    cout << wordCount << "\twords\n";
}

void countChar(string string){
    int charCount[LETTER_COUNT] = {0};
    char alphabetLower[LETTER_COUNT] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char alphabetUpper[LETTER_COUNT] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    for (int i = 0; i < string.length(); i++){
        if (string[i] == ' ' || string[i] == '.' || string[i] == ',')
            continue;
        else{
            for (int j = 0; j < LETTER_COUNT; j++){
                if (string[i] == alphabetLower[j] || string[i] == alphabetUpper[j])
                    charCount[j]++;
            }
        }
    }
    printChar(charCount);
}

void printChar(int numChar[]){
    char alphabet[LETTER_COUNT] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (int i = 0; i < LETTER_COUNT; i++){
        if (numChar[i] != 0)
            cout << numChar[i] << "\t" << alphabet[i] << endl;
    }
}