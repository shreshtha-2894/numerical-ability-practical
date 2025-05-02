#include <stdio.h>
#include <math.h>

// f(x) = x^3 - x - 11
double f(double x) {
    return x * x * x - x - 11;
}

// Derivative of f(x): f'(x) = 3x^2 - 1
double f_derivative(double x) {
    return 3 * x * x - 1;
}

int main() {
    double a, c;
    int max_iterations, iteration = 0;

    printf("Enter the initial guess a: ");
    scanf("%lf", &a);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    while (iteration < max_iterations) {
        // Apply the Newton-Raphson method
        c = a - f(a) / f_derivative(a);

        if (fabs(f(c)) < 0.001) {
            break;  
        }

        a = c;

        iteration++;
    }
    printf("The root of the function is approximately: %.3lf\n", c);

    return 0;
}