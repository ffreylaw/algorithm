#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T> class Stack {
private:
    vector<T> vec;
    int top;
public:
    Stack(vector<T> &vec) {
        this->vec = vec;
        this->top = vec.size();
    }

    bool stack_empty() {
        if (top == 0) {
            return true;
        } else {
            return false;
        }
    }

    void push(T &x) {
        top++;
        vec.insert(vec.begin() + top - 1, x);
    }

    T pop() {
        if (stack_empty()) {
            cerr << "stack underflow" << endl;
            exit(EXIT_FAILURE);
        } else {
            top--;
            return vec[top];
        }
    }

    void print() {
        cout << "[";
        for (int i = 0; i < top; i++) {
            cout << vec[i];
            if (i != top - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main(int argc, char const *argv[]) {
    float arr[] = {5, 2, 7, 4, 9, 1, 3, 6, 8};
    vector<float> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    Stack<float> st(vec);
    st.print();
    st.push(10);
    st.print();
    cout << st.pop() << endl;
    st.print();
    return 0;
}
