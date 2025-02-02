#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

void openFileInput(ifstream& file) {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;
    file.open(filename);
    while (!file) {
        cout << "Unable to open file!\n";
        cout << "Enter file name: ";
        cin >> filename;
        file.clear();
        file.open(filename);
    }
}

bool pascalPairs(ifstream& file) {
    stack<char> charStack;
    char symbol;
    while (file.get(symbol)) {
        if (symbol != '{' && symbol != '}' && symbol != '(' && symbol != ')' && symbol != '[' && symbol != ']') 
            continue;
        
        if (symbol == '{' || symbol == '(' || symbol == '[') 
            charStack.push(symbol);
        
        else if (symbol == '}') {
            if (charStack.empty() || charStack.top() != '{')
                return false;
            else
                charStack.pop();
        }
        
        else if (symbol == ')') {
            if (charStack.empty() || charStack.top() != '(')
                return false;
            else
                charStack.pop();
        }

        else if (symbol == ']') {
            if (charStack.empty() || charStack.top() != '[')
                return false;
            else
                charStack.pop();
        }
    }
    if (charStack.empty())
        return true;

    else
        return false;
}

int main() {
    ifstream inFile;
    openFileInput(inFile);

    if (pascalPairs(inFile))
        cout << "File has successful Pascal Pairs!" << endl;
    else
        cout << "File has failed Pascal Pairs!" << endl;
}



