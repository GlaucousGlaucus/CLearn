#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

void gaussElimination(double a[N][N+1]) {
    int i, j, k;
    double factor;

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {.l
            factor = a[j][i] / a[i][i];
            for (k = i; k <= N; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    double x[N];
    for (i = N - 1; i >= 0; i--) {
        x[i] = a[i][N];
        for (j = i + 1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    for (i = 0; i < N; i++) {
        printf("x[%d] = %lf\n", i + 1, x[i]);
    }
}

int main() {
    double a[N][N+1] = {
        {1, 1, 1, 1},
        {4, 3, -1, 6},
        {3, 5, 3, 4}
    };
    gaussElimination(a);
    return 0;
}
