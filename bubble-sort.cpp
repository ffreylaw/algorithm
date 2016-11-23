#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(vector<int>&);
void print_vector(vector<int>&);

int main(int argc, char const *argv[]) {
    int arr[] = {5, 2, 7, 4, 9, 1, 3, 6, 8};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    bubble_sort(vec);
    print_vector(vec);
    return 0;
}

void print_vector(vector<int> &vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void bubble_sort(vector<int> &vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = vec.size() - 1; j > i; j--) {
            if (vec[j] < vec[j - 1]) {
                int tmp = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = tmp;
            }
        }
    }
}
