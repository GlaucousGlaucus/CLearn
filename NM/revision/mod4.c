// Module IV: Differentiation and Integration
#include <stdio.h>

float x[] = {1, 2, 3, 4};
float y[] = {1, 4, 9, 16}; // y = x^2
int n = 4;

void diff_interp() {
    // Forward difference for dy/dx at x=1
    float h = x[1] - x[0];
    float dy = (-y[2] + 4*y[1] - 3*y[0]) / (2*h);
    printf("Differentiation at x=1: %.2f\n", dy);
}

void trapezoidal() {
    float area = 0;
    for (int i = 0; i < n - 1; i++) {
        float h = x[i+1] - x[i];
        area += h * (y[i] + y[i+1]) / 2;
    }
    printf("Trapezoidal Integration: %.2f\n", area);
}

void simpson() {
    // Assumes even intervals, even number of segments
    float h = x[1] - x[0];
    float area = y[0] + y[n-1];
    for (int i = 1; i < n - 1; i++) {
        if (i % 2 == 0) area += 2 * y[i];
        else area += 4 * y[i];
    }
    area *= h / 3;
    printf("Simpson Integration: %.2f\n", area);
}

int main() {
    diff_interp();
    trapezoidal();
    simpson();
    return 0;
}