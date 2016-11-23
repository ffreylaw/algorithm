#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void counting_sort(vector<float>&, int);
void print_vector(const vector<float>&);

int main(int argc, char const *argv[]) {
    float arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
    vector<float> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    counting_sort(vec, 5);
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

void counting_sort(vector<float> &vec, int k) {
    vector<float> output(vec.size());
    vector<float> count(k + 1, 0);
    for (int i = 0; i < vec.size(); i++) {
        count[vec[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }
    for (int i = vec.size() - 1; i >= 0; i--) {
        output[count[vec[i]] - 1] = vec[i];
        count[vec[i]]--;
    }
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = output[i];
    }
}
