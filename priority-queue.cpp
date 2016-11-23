#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T> class PriorityQueue {
private:
    vector<T> vec;
    int heap_size;

public:
    PriorityQueue(vector<T> vec) {
        this->vec = vec;
        build_max_heap();
    }

    void build_max_heap() {
        heap_size = 1;
        for (int i = 1; i < vec.size(); i++) {
            max_heap_insert(vec[i]);
        }
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void max_heapify(const int i) {
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
            swap(i, largest);
            max_heapify(vec, largest, heap_size);
        }
    }

    T heap_maximum() {
        return vec[0];
    }

    T heap_extract_max() {
        if (heap_size < 1) {
            cerr << "heap underflow" << endl;
        }
        max = vec[0];
        vec[0] = vec[heap_size - 1];
        heap_size--;
        max_heapify(0);
        return max;
    }

    void heap_increase_key(int i, T key) {
        if (key < vec[i]) {
            cerr << "new key is smaller than current key" << endl;
            exit(EXIT_FAILURE);
        }
        vec[i] = key;
        while (i > 0 && (vec[parent(i)] < vec[i])) {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    void max_heap_insert(T key) {
        heap_size++;
        vec[heap_size - 1] = INT_MIN;
        heap_increase_key(heap_size - 1, key);
    }

    void swap(int i, int j) {
        T tmp = vec[i];
        vec[i] = vec[j];
        vec[j] = tmp;
    }

    void print() {
        cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i != vec.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main(int argc, char const *argv[]) {
    float arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    vector<float> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));
    PriorityQueue<float> pq(vec);
    pq.print();
    return 0;
}
