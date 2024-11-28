#include <iostream>
#include <string>
using namespace std;

void checkStr(string& string);
bool checksChar(string string, int iStart);
int removeDigs(string& string, int iStart);

int main(){
    string str1;
    cout << "Please enter a line of text:\n";
    getline(cin,str1);
    checkStr(str1);
    cout << str1 << endl;

    return 0;
}

void checkStr(string& string){
    int i = 0;
    while (i < string.length()){
        if (checksChar(string, i) == true){
            if (string.find(" ", i) == string::npos)
                i = string.length();
            else
                i = string.find(" ", i);
        }
        else
            i = removeDigs(string, i);
        i++;
    }
}
bool checksChar(string string, int iStart){
    if (string.find(" ", iStart) == string::npos){
        for (int i = iStart; i < string.length(); i++){
            if (string[i] > 57)
                return true;
        }
    }
    else{
        int iFinish = string.find(" ", iStart);
        for (int i = iStart; i < iFinish; i++){
            if (string[i] > 57)
                return true;
        }
    }
    return false;
}

int removeDigs(string& string, int iStart){
    int iFinish;
    if (string.find(" ", iStart) == string::npos){
        for (int i = iStart; i < string.length(); i++)
            string[i] = 'x';
        iFinish = string.length();
    }
    else{
        iFinish = string.find(" ", iStart);
        for (int i = iStart; i < iFinish; i++)
            string[i] = 'x';
    }
    return iFinish;
}