#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void counting_sort(vector<float>&, vector<float>&, int);
void print_vector(const vector<float>&);

int main(int argc, char const *argv[]) {
    float arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
    vector<float> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    vector<float> result(vec.size());
    counting_sort(vec, result, 5);
    print_vector(result);
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

void counting_sort(vector<float> &A, vector<float> &B, int k) {
    vector<float> C(k + 1);
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }
    for (int j = 0; j < A.size(); j++) {
        C[A[j]] = C[A[j]] + 1;
    }
    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = A.size() - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}
