
#include <iostream>
#include <vector>

using namespace std;

void luDecomposition(const vector<vector<double>>& a, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = a.size();
    
    L = vector<vector<double>>(n, vector<double>(n, 0.0));
    U = vector<vector<double>>(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int k = i; k < n; ++k) {
            double sum = 0.0;
            for (int j = 0; j < i; ++j) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = a[i][k] - sum;
        }
        L[i][i] = 1.0;
        for (int k = i + 1; k < n; ++k) {
            double sum = 0.0;
            for (int j = 0; j < i; ++j) {
                sum += L[k][j] * U[j][i];
            }
            L[k][i] = (a[k][i] - sum) / U[i][i];
        }
    }
}

int main() {
    vector<vector<double>> a = {
        {10, 1, 2},
        {1, 10, 1},
        {2, 1, 10}
    };

    vector<vector<double>> L, U;
    luDecomposition(a, L, U);

    cout << "L matrix:" << endl;
    for (const auto& row : L) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "\nU matrix:" << endl;
    for (const auto& row : U) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
