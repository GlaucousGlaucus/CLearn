#include <stdio.h>

// Define the function to integrate
double f(double x) {
    return 1.0 / (1.0 + x * x);  // Example: f(x) = 1 / (1 + x^2)
}

// Trapezoidal Rule
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++)
        sum += 2 * f(a + i * h);
    return (h / 2.0) * sum;
}

// Simpson's 1/3 Rule
double simpson13(double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Simpson's 1/3 rule requires even number of intervals.\n");
        return -1;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 4 * f(a + i * h);
    }
    return (h / 3.0) * sum;
}

// Simpson's 3/8 Rule
double simpson38(double a, double b, int n) {
    if (n % 3 != 0) {
        printf("Simpson's 3/8 rule requires number of intervals divisible by 3.\n");
        return -1;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 3 * f(a + i * h);
    }
    return (3 * h / 8.0) * sum;
}

int main() {
    double a = 0.0, b = 1.0;
    int n = 6;  // Example: must be even for 1/3, divisible by 3 for 3/8

    printf("Trapezoidal Rule: %.6f\n", trapezoidal(a, b, n));
    printf("Simpson's 1/3 Rule: %.6f\n", simpson13(a, b, n));
    printf("Simpson's 3/8 Rule: %.6f\n", simpson38(a, b, n));

    return 0;
}
