#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge_sort(vector<float>&, int, int);
void merge(vector<float>&, int, int, int);
void print_vector(const vector<float>&);

int main(int argc, char const *argv[]) {
    float arr[] = {5, 2, 7, 4, 9, 1, 3, 6, 8};
    vector<float> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    merge_sort(vec, 0, vec.size() - 1);
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

void merge_sort(vector<float> &vec, int low, int high) {
    if (low < high) {
        int mid = low + ((high - low)/2);
        merge_sort(vec, low, mid);
        merge_sort(vec, mid + 1, high);
        merge(vec, low, mid, high);
    }
}

void merge(vector<float> &vec, int low, int mid, int high) {
    vector<float> tmp(vec.size());
    for (int i = low; i <= high; i++) {
        tmp[i] = vec[i];
    }
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high) {
        if (tmp[i] <= vec[j]) {
            vec[k] = tmp[i];
            i++;
        } else {
            vec[k] = tmp[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        vec[k] = tmp[i];
        k++;
        i++;
    }
}
