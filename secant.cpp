#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Function for which we are finding the root
double f(double x) {
    return x*x - 4; // Example: x^2 - 4 = 0
}

// Secant method function
double secantMethod(double x0, double x1, int maxIter, double tol) {
    if (maxIter <= 0) {
        throw invalid_argument("Maximum iterations must be positive");
    }
    if (tol <= 0) {
        throw invalid_argument("Tolerance must be positive");
    }

    double x2;
    int iterUsed = 0;
    
    cout << fixed << setprecision(10);
    cout << "Iteration\tApproximation\tf(x)\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < maxIter; i++) {
        iterUsed = i + 1;
        
        // Check for division by zero
        double denominator = f(x1) - f(x0);
        if (fabs(denominator) < tol) {
            cout << "\nWarning: Denominator became too small at iteration " << iterUsed << endl;
            break;
        }

        x2 = x1 - f(x1) * (x1 - x0) / denominator;
        
        // Print iteration info
        cout << iterUsed << "\t\t" << x2 << "\t" << f(x2) << endl;
        
        // Check convergence
        if (fabs(x2 - x1) < tol) {
            break;
        }
        
        // Update values
        x0 = x1;
        x1 = x2;
    }
    
    cout << "\nConverged after " << iterUsed << " iterations\n";
    return x2;
}

int main() {
    try {
        double x0, x1;
        int maxIter;
        double tol;

        cout << "Enter first initial guess (x0): ";
        cin >> x0;
        cout << "Enter second initial guess (x1): ";
        cin >> x1;
        cout << "Enter maximum number of iterations: ";
        cin >> maxIter;
        cout << "Enter tolerance level: ";
        cin >> tol;

        double root = secantMethod(x0, x1, maxIter, tol);
        cout << "\nFinal root found: " << setprecision(15) << root << endl;
        cout << "Function value at root: " << f(root) << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}