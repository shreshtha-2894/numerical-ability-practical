#include <iostream>
#include <iomanip>
#include <cstdlib>  // For exit()

using namespace std;

const int SIZE = 10;

void inputMatrix(float a[][SIZE + 1], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void gaussElimination(float a[][SIZE + 1], int n) {
    for (int i = 1; i <= n - 1; i++) {
        if (a[i][i] == 0.0) {
            cout << "Mathematical Error! (Zero pivot element)\n";
            exit(0);
        }
        
        for (int j = i + 1; j <= n; j++) {
            float ratio = a[j][i] / a[i][i];
            for (int k = 1; k <= n + 1; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }
}

void backSubstitution(float a[][SIZE + 1], float x[], int n) {
    x[n] = a[n][n + 1] / a[n][n];

    for (int i = n - 1; i >= 1; i--) {
        x[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
}

void displaySolution(float x[], int n) {
    cout << "\nSolution:\n" << fixed << setprecision(3);
    for (int i = 1; i <= n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
}

int main() {
    float a[SIZE][SIZE + 1], x[SIZE];
    int n;
    
    cout << "Enter the number of unknowns: ";
    cin >> n;
    
    inputMatrix(a, n);
    gaussElimination(a, n);
    backSubstitution(a, x, n);
    displaySolution(x, n);

    return 0;
}