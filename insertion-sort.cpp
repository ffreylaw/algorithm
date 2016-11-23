#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void insertion_sort(vector<T>&);
template <typename T>
void print_vector(vector<T>&);

int main(int argc, char const *argv[]) {
    int arr[] = {5, 2, 7, 4, 9, 1, 3, 6, 8};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    insertion_sort(vec);
    print_vector(vec);
    return 0;
}

template <typename T>
void print_vector(vector<T> &vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

template <typename T>
void insertion_sort(vector<T> &vec) {
    for (int j = 1; j < vec.size(); j++) {
        T key = vec[j];
        int i = j - 1;
        while (i >= 0 && vec[i] > key) {    // compare
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}
