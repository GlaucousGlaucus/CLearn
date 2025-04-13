// Module III: Interpolation
#include <stdio.h>

// Known data points: (1,1), (2,4), (3,9), (4,16)
#define N 4
float x[] = {1, 2, 3, 4};
float y[] = {1, 4, 9, 16};

void lagrange() {
    float X = 2.5, res = 0;
    for (int i = 0; i < N; i++) {
        float term = y[i];
        for (int j = 0; j < N; j++) {
            if (j != i)
                term *= (X - x[j]) / (x[i] - x[j]);
        }
        res += term;
    }
    printf("Lagrange at 2.5: %.2f\n", res);
}

void newton_divided() {
    float f[N][N];
    for (int i = 0; i < N; i++) f[i][0] = y[i];
    for (int j = 1; j < N; j++)
        for (int i = 0; i < N - j; i++)
            f[i][j] = (f[i+1][j-1] - f[i][j-1]) / (x[i+j] - x[i]);

    float X = 2.5, res = f[0][0], term = 1;
    for (int i = 1; i < N; i++) {
        term *= (X - x[i-1]);
        res += f[0][i] * term;
    }
    printf("Newton Divided at 2.5: %.2f\n", res);
}

void inverse_interp() {
    // Use x = f(y) interpolation; swap role of x and y
    float Y = 9.5, res = 0;
    for (int i = 0; i < N; i++) {
        float term = x[i];
        for (int j = 0; j < N; j++) {
            if (j != i)
                term *= (Y - y[j]) / (y[i] - y[j]);
        }
        res += term;
    }
    printf("Inverse Interpolation at y=9.5: x=%.2f\n", res);
}

void finite_diff_interp() {
    // Uniform x: h = 1; f(x) = x^2
    float X = 2.5, h = x[1] - x[0], u = (X - x[0]) / h;
    float f[N] = {1, 4, 9, 16}, diff[N] = {0};
    for (int i = 0; i < N; i++) diff[i] = f[i];
    float res = f[0], term = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - i; j++)
            diff[j] = diff[j+1] - diff[j];
        term *= (u - (i - 1)) / i;
        res += term * diff[0];
    }
    printf("Finite Difference at 2.5: %.2f\n", res);
}

int main() {
    lagrange();
    newton_divided();
    inverse_interp();
    finite_diff_interp();
    return 0;
}