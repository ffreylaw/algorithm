#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void rand_quick_sort(vector<float>&, int, int);
int rand_partition(vector<float>&, int, int);
int partition(vector<float>&, int, int);
void print_vector(const vector<float>&);

int main(int argc, char const *argv[]) {
    float arr[] = {5, 2, 7, 4, 9, 1, 3, 6, 8};
    vector<float> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    rand_quick_sort(vec, 0, vec.size() - 1);
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

void rand_quick_sort(vector<float> &vec, int p, int r) {
    if (p < r) {
        int q = rand_partition(vec, p, r);
        rand_quick_sort(vec, p, q - 1);
        rand_quick_sort(vec, q + 1, r);
    }
}

int partition(vector<float> &vec, int p, int r) {
    float x = vec[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (vec[j] <= x) {
            i++;
            float tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
        }
    }
    float tmp = vec[i + 1];
    vec[i + 1] = vec[r];
    vec[r] = tmp;
    return i + 1;
}

int rand_partition(vector<float> &vec, int p, int r) {
    int i = p + (rand() % (r - p + 1));
    float tmp = vec[r];
    vec[r] = vec[i];
    vec[i] = tmp;
    return partition(vec, p, r);
}
