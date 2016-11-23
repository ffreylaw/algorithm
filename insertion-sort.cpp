#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertion_sort(vector<int>&);
void print_vector(const vector<int>&);

int main(int argc, char const *argv[]) {
    int arr[] = {5, 2, 7, 4, 9, 1, 3, 6, 8};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    insertion_sort(vec);
    print_vector(vec);
    return 0;
}

void print_vector(const vector<int> &vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void insertion_sort(vector<int> &vec) {
    for (int j = 1; j < vec.size(); j++) {
        int key = vec[j];
        int i = j - 1;
        while (i >= 0 && vec[i] > key) {
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}
