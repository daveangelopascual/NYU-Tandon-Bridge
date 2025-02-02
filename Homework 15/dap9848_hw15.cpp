#include <iostream>
#include <fstream>
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

class LList;
class LListNode {
    string username;
    float amtPaid;
    float amtDelta;
    LListNode *next;

public:
    LListNode(string newName,float newAmtPaid) :  username(newName), amtPaid(newAmtPaid), amtDelta(0), next(nullptr) {}
    friend class LList;

};

class LList {
private:
    LListNode* head;
public:
    LList() : head(nullptr) {}
    ~LList() { clear(); }
    LListNode* getHead() const { return head; }
    void clear();
    void insertAtTail(string newName,float newAmtPaid);
    int size();
    float totalAmtPaid();
    void findDebitsAndCredits(float evenSplit);
    void zeroBalances();
};

void LList::clear(){
    while (head != nullptr) {
            LListNode* temp = head;
            head = head->next;
            delete temp;
    }
}

void LList::insertAtTail(string newName,float newAmtPaid) {
    LListNode* newNode = new LListNode(newName, newAmtPaid);
    if (head == nullptr) {
        head = newNode; // first node in the list
    }
    else {
        LListNode* current = head;
        while (current->next != nullptr) {
            current = current->next; // move until the end of the list
        }
        current->next = newNode; // insert new node at the end
    }
}

int LList::size() {
    int count = 0;
    LListNode* current = head;
    while (current != nullptr) {
        count++; // increment
        current = current->next; // move until the end of the list
    }
    return count;
}

float LList::totalAmtPaid() {
    float total = 0;
    LListNode* current = head;
    while (current != nullptr) {
        total += current->amtPaid; // summation
        current = current->next; // move until the end of the list
    }
    return total;
}

void LList::findDebitsAndCredits(float evenSplit) {
    LListNode* current = head;
    while (current != nullptr) {
        current->amtDelta = current->amtPaid - evenSplit; // delta amount
        current = current->next; // move until the end of the list
    }
}

void LList::zeroBalances() {

    LListNode* current = head;
    while (current != nullptr) {
        if (current->amtDelta == 0)
            cout << current->username << ", paid the perfect amount!\n";
        current = current->next; // move until the end of the list
    }

    LListNode* debit = head;
    LListNode* credit = head;
    while (debit != nullptr && credit != nullptr) {
        while (debit != nullptr && debit->amtDelta >= 0) { // find the next person that owes money
            debit = debit->next;
        }
        while (credit != nullptr && credit->amtDelta <= 0) { // find the next person that is owed money
            credit = credit->next;
        }

        if (debit == nullptr || credit == nullptr)
            break;

        if (-debit->amtDelta == credit->amtDelta) { // if credit and debit are the same, cancel them out.
            cout << debit->username << ", please pay " << credit->username << " $" << credit->amtDelta << "!\n";
            debit->amtDelta = 0;
            credit->amtDelta = 0;
        }
        else if (-debit->amtDelta > credit->amtDelta){ // if debit is more than credit, find the difference and change credit.
            cout << debit->username << ", please pay " << credit->username << " $" << credit->amtDelta << "!\n";
            debit->amtDelta += credit->amtDelta;
            credit->amtDelta = 0;
        }
        else if (-debit->amtDelta < credit->amtDelta) { // if debit is less than credit, find the difference and change debit.
            cout << debit->username << ", please pay " << credit->username << " $" << -debit->amtDelta << "!\n";
            credit->amtDelta += debit->amtDelta;
            debit->amtDelta = 0;
        }
    }
}

int main() {
    
    ifstream inFile;
    openFileInput(inFile);
    LList bill;
    float tempPaid;
    string tempUser;

    while (inFile >> tempPaid ) {
        inFile.ignore(9,' ');
        getline(inFile, tempUser);
        bill.insertAtTail(tempUser,tempPaid);
    }
    
    float billAmt = bill.totalAmtPaid();
    int numPersons = bill.size();
    float evenShare = billAmt / numPersons;
    bill.findDebitsAndCredits(evenShare);
    cout << endl;
    bill.zeroBalances();
    cout << "\nThe total for the bill was $" << billAmt << ". Each person should have paid $" << evenShare << ".\n";

    return 0;
}
