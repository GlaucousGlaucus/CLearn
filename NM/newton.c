#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define a 0.01

double func(double x) {
    return 3*x - cos(x) - 1;
}

double derivFunc(double x) {
    return 3 + sin(x);
}

void newton(double x) {
    double h = func(x) / derivFunc(x);
    int iteration = 1;

    while (fabs(h) >= a) {
        h = func(x) / derivFunc(x);
        x = x - h;
        printf("Iteration %d: x = %.6f\n", iteration, x);
        iteration++;
    }

    printf("The root is: %.6f\n", x);
}

int main() {
    double x0;
    printf("x_0: ");
    scanf("%lf", &x0);

    newton(x0);

    return 0;
}
