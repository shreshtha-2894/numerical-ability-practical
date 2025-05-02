#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// f(x) = x^3 - x - 11
double f(double x) {
    return x * x * x - x - 11;
}

int main() {
    double a, b, c;
    int max_iters, iter = 0;

    cout << "Enter the initial guesses a and b (a < b): ";
    cin >> a >> b;
    cout << "Enter the maximum number of iterations: ";
    cin >> max_iters;

    if (f(a) * f(b) > 0) {
        cout << "The function does not have opposite signs at the endpoints a and b." << endl;
        return 1;  // Exit with error code
    }

    // Perform the bisection method loop
    while ((b - a) / 2.0 > 0.001 && iter < max_iters) {  
       
        // Find the midpoint
        c = (a + b) / 2.0;

        // Check if the midpoint is the root
        if (f(c) == 0.0) {
            break;  
        }

        if (f(c) * f(a) < 0) {
            b = c; 
        } else {
            a = c;  
        }

        iter++;
    }

    // Print the result with 4 decimal places
    cout << fixed << setprecision(4);
    cout << "The root of the function is approximately: " << (a + b) / 2.0 << endl;

    return 0;
}