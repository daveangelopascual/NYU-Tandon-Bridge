#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
int main(){
    string word;
    bool result;

    cout << "Please enter a word: ";
    cin >> word;

    result = isPalindrome(word);
    if (result == true)
        cout << word << " is a palindrome\n";
    else
        cout << word << " is not a palindrome\n";
    
    return 0;
}

bool isPalindrome(string str){
    string reverse = "";

    for (int i = str.length() - 1; i >= 0; i--){
        reverse += str[i];
    }
    if (str == reverse)
        return true;
    else
        return false;
}