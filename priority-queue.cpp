#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }
void max_heap_insert(vector<float>&, int);
void heap_increase_key(vector<float>&, int, float);
void heap_extract_max(vector<float>&);
float heap_maximum(vector<float>&);
void max_heapify(vector<float>&, const int, const int);
void print_vector(const vector<float>&);

int main(int argc, char const *argv[]) {
    float arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    vector<float> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    heap_sort(vec);
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

void max_heapify(vector<float> &vec, const int i, const int heap_size) {
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < heap_size && vec[l] > vec[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r < heap_size && vec[r] > vec[largest]) {
        largest = r;
    }
    if (largest != i) {
        float tmp = vec[i];
        vec[i] = vec[largest];
        vec[largest] = tmp;
        max_heapify(vec, largest, heap_size);
    }
}

float heap_maximum(vector<float> &vec) {
    return vec[0];
}

void heap_extract_max(vector<float> &vec) {

}
