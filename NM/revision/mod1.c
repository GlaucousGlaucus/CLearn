#include <stdio.h>
#include <math.h>

#define EPS 1e-6  // Desired precision

// f(x) = x^3 - x - 2 (root near x = 1.5)
float f(float x) { return x*x*x - x - 2; }

// Derivative for Newton-Raphson
float df(float x) { return 3*x*x - 1; }

void bisection() {
    float a = 1, b = 2, c;
    do {
        c = (a + b)/2;
        if(f(c) * f(a) < 0) b = c;
        else a = c;
    } while(fabs(b - a) >= EPS);
    printf("Bisection Root: %.6f\n", c);
}

void regula_falsi() {
    float a = 1, b = 2, c, prev_c = 0;
    do {
        c = (a*f(b) - b*f(a)) / (f(b) - f(a));
        if(f(c) * f(a) < 0) b = c;
        else a = c;
    } while(fabs(c - prev_c) >= EPS && (prev_c = c, 1));
    printf("Regula-Falsi Root: %.6f\n", c);
}

void secant() {
    float x0 = 0, x1 = 2, x2;
    do {
        x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0));
        if(fabs(x2 - x1) < EPS) break;
        x0 = x1;
        x1 = x2;
    } while(1);
    printf("Secant Root: %.6f\n", x2);
}

void newton_raphson() {
    float x = 1.5, prev_x;
    do {
        prev_x = x;
        x = x - f(x)/df(x);
    } while(fabs(x - prev_x) >= EPS);
    printf("Newton-Raphson Root: %.6f\n", x);
}

void general_iterative() {
    float x = 1.5, prev_x;
    do {
        prev_x = x;
        x = pow(x + 2, 1.0/3);
    } while(fabs(x - prev_x) >= EPS);
    printf("Iterative Root: %.6f\n", x);
}

int main() {
    bisection();
    regula_falsi();
    secant();
    newton_raphson();
    general_iterative();
    return 0;
}
