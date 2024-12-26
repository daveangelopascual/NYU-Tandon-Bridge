#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
void printArray(string arr[], int arrSize);
void countWord(string string, int& wordCount);


int main(){
string input = "";

cout << "Please enter a sentence with no delimiters beside a space between the words:\n";
getline(cin, input);

int wordsInSentence = 0;
string* sentenceInArr = createWordsArray(input, wordsInSentence);
printArray(sentenceInArr, wordsInSentence);
delete [] sentenceInArr;

}

string* createWordsArray(string sentence, int& outWordsArrSize){
    int start = 0, finish, words = 0;
    string *sentenceArr = new string[words];

    while (start < sentence.length()){
        if (sentence.find(" ", start) == string::npos) //if space is not found, there is only one word
            finish = sentence.length();
        else
            finish = sentence.find(" ", start);

        string word = "";
        word = sentence.substr(start, finish - start); //slices sentence into a word.
        
        *(sentenceArr + outWordsArrSize) = word; //index word into an array
        outWordsArrSize++;

        start = finish + 1;
    }
    return sentenceArr;
}

void printArray(string arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        if (i == 0)
            cout << "[" << arr[i] << ", ";
        else if (i == arrSize - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    cout << endl;
}  