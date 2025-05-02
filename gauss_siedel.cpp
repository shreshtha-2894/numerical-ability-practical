#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function prototypes
double calculateX(double y, double z);
double calculateY(double x, double z);
double calculateZ(double x, double y);
void performGaussSeidel(double tolerableError);
void printIteration(int count, double x, double y, double z);

// Function definitions for Gauss-Seidel method
double calculateX(double y, double z) {
    return (17 - y + 2 * z) / 20;
}

double calculateY(double x, double z) {
    return (-18 - 3 * x + z) / 20;
}

double calculateZ(double x, double y) {
    return (25 - 2 * x + 3 * y) / 20;
}

void printIteration(int count, double x, double y, double z) {
    cout << count << "\t" 
         << fixed << setprecision(4) 
         << x << "\t" << y << "\t" << z << endl;
}

void performGaussSeidel(double tolerableError) {
    double x0 = 0, y0 = 0, z0 = 0;
    double x1, y1, z1;
    double errorX, errorY, errorZ;
    int count = 1;

    cout << "\nCount\tx\ty\tz\n";

    do {
        // Calculate new values using updated values immediately
        x1 = calculateX(y0, z0);
        y1 = calculateY(x1, z0);
        z1 = calculateZ(x1, y1);

        // Print current iteration
        printIteration(count, x1, y1, z1);

        // Calculate errors
        errorX = fabs(x0 - x1);
        errorY = fabs(y0 - y1);
        errorZ = fabs(z0 - z1);

        // Update values for next iteration
        count++;
        x0 = x1;
        y0 = y1;
        z0 = z1;

    } while (errorX > tolerableError || 
             errorY > tolerableError || 
             errorZ > tolerableError);

    // Print final solution
    cout << "\nSolution: x = " << fixed << setprecision(3) << x1
         << ", y = " << y1 << ", z = " << z1 << endl;
}

int main() {
    double tolerableError;

    cout << "Enter tolerable error: ";
    cin >> tolerableError;

    performGaussSeidel(tolerableError);

    return 0;
}