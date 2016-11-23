#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }
void heap_sort(vector<float>&);
void build_max_heap(vector<float>&);
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

void build_max_heap(vector<float> &vec) {
    int heap_size = vec.size();
    for (int i = vec.size() / 2; i >= 0; i--) {
        max_heapify(vec, i, heap_size);
    }
}

void heap_sort(vector<float> &vec) {
    build_max_heap(vec);
    int heap_size = vec.size();
    for (int i = vec.size() - 1; i > 0; i--) {
        float tmp = vec[0];
        vec[0] = vec[i];
        vec[i] = tmp;
        heap_size--;
        max_heapify(vec, 0, heap_size);
    }
}
