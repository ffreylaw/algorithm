#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<double>>
smmr(const vector<vector<double>>&, const vector<vector<double>>&);
vector<vector<double>>
submatrix(vector<vector<double>>&, int, int);
void print_matrix(const vector<vector<double>>&);

int main(int argc, char const *argv[]) {
    vector<vector<double>> A = {{2, 3}, {4, 5}};
    vector<vector<double>> B = {{6, 7}, {8, 9}};
    vector<vector<double>> C = smm(A, B);
    print_matrix(C);
    return 0;
}

void print_matrix(const vector<vector<double>> &C) {
    int n = C.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<double>>
submatrix(vector<vector<double>> &M, int i, int j) {
    // incomplete...
}

vector<vector<double>>
smmr(const vector<vector<double>> &A, const vector<vector<double>> &B) {
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        // incomplete...
    }
}
