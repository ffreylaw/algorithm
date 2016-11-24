#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertion_sort(vector<float>&);
void print_vector(const vector<float>&);

int main(int argc, char const *argv[]) {
    float arr[] = {5, 2, 7, 4, 9, 1, 3, 6, 8};
    vector<float> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    insertion_sort(vec);
    print_vector(vec);
    return 0;
}

void print_vector(const vector<float> &vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void insertion_sort(vector<float> &vec) {
    for (int j = 1; j < vec.size(); j++) {
        float key = vec[j];
        int i = j - 1;
        while (i >= 0 && vec[i] > key) {
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}
