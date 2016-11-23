#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); }
int max_crossing_sum(int arr[], int l, int m, int h);
int max_subarray_sum(int arr[], int l, int h);

int main(int argc, char const *argv[]) {
    int arr[] = {2, 3, 4, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = max_subarray_sum(arr, 0, n - 1);
    cout << max_sum << endl;
    return 0;
}

int max_crossing_sum(int arr[], int l, int m, int h) {
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }
    int right_sum = INT_MIN;
    sum = 0;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }
    return left_sum + right_sum;
}

int max_subarray_sum(int arr[], int l, int h) {
    if (l == h) return arr[l];
    int m = (l + h)/2;
    return max(max_subarray_sum(arr, l, m),
               max_subarray_sum(arr, m + 1, h),
               max_crossing_sum(arr, l, m, h));
}
