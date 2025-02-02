#include <iostream>
#include <vector>
using namespace std;


template <class T>
class VQueue {
    vector<T> data;
    int head;
public:
    VQueue() : head(0) {}
    void enqueue(T newData) { data.push_back(newData); }
    void dequeue() {}
    T front() const{}
    bool isEmpty() const{ return head >= data.size(); }
    int size() const{ return data.size() - head; }
    void clear() { data.clear(); head = 0; }
};

template <class T>
void VQueue<T>::dequeue() {
    if (!isEmpty()) {
        head++;
        
        if (head == data.size()) {
            data.clear();
            head = 0;
        }
    }
}

template <class T>
T VQueue<T>::front() const{
    if (!isEmpty()) {
        return data[head];
    }
    cout << "Queue is Empty!";
        return;
}

int main() {

    return 0;
}