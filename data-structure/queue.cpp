#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T> class Queue {
private:
    vector<T> vec;
    int head;
    int tail;
public:
    Queue(vector<T> &vec) {
        this->vec = vec;
        this->head = 0;
        this->tail = vec.size() - 1;
    }

    void enqueue(T &x) {
        if (tail == vec.size()) {
            tail = 0;
        } else {
            tail++;
        }
        vec.insert(vec.begin() + tail, x);
    }

    T dequeue() {
        T x = vec[head];
        if (head == vec.size()) {
            head = 0;
        } else {
            head++;
        }
        return x;
    }

    void print() {
        cout << "[";
        for (int i = head; i <= tail; i++) {
            cout << vec[i];
            if (i != tail) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main(int argc, char const *argv[]) {
    float arr[] = {5, 2, 7, 4, 9, 1, 3, 6, 8};
    vector<float> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    Queue<float> qu(vec);
    qu.print();
    qu.enqueue(10);
    qu.print();
    cout << qu.dequeue() << endl;
    qu.print();
    return 0;
}
