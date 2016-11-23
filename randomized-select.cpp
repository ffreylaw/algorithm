#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

float rand_select(vector<float>&, int, int, int);
int rand_partition(vector<float>&, int, int);
int partition(vector<float>&, int, int);

int main(int argc, char const *argv[]) {
    float arr[] = {5, 2, 7, 4, 9, 1, 3, 6, 8};
    vector<float> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    cout << rand_select(vec, 0, vec.size() - 1, 5) << endl;
    return 0;
}

float rand_select(vector<float> &vec, int p, int r, int i) {
    if (p == r) {
        return vec[p];
    }
    int q = rand_partition(vec, p, r);
    int k = q - p + 1;
    if (i == k) {
        return vec[q];
    } else if (i < k) {
        return rand_select(vec, p, q - 1, i);
    } else {
        return rand_select(vec, q + 1, r, i - k);
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
