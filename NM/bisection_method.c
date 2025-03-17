#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
    return x*x*x + 5 * x + 1;
}

double bisection(double a, double b, double tol, int max_iter) {
    if (f(a) * f(b) >= 0) {
        printf("Error: f(a) and f(b) must have opposite signs.\n");
        return NAN;  // Not-a-Number (invalid case)
    }

    double c;
    int iter = 0;

    while ((b - a) / 2 > tol && iter < max_iter) {
        c = (a + b) / 2;  // Midpoint
        double f_c = f(c);

        // Check if midpoint is a root
        if (fabs(f_c) < tol) {
            return c;
        }

        // Update the interval
        if (f(a) * f_c < 0) {
            b = c;  // Root is in [a, c]
        } else {
            a = c;  // Root is in [c, b]
        }

        iter++;
    }

    return (a + b) / 2;  // Approximate root
}

double find_root(double a, double b, double tol, int max_iter) {
    double c;
    int iter = 0;
    while (iter < max_iter) {
        c = (a + b) / 2;
        double f_c = f(c);
        if (f_c == 0) {
            return c;
        }
        if (f_c * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        iter++;
    }
    return (a + b) / 2;
}

int main() {
    printf("%.4lf\n", bisection(-1, 1, 1e-6, 10));
    printf("%.4f", find_root(1, 2, 1e-6, 10));
    return 0;
}
