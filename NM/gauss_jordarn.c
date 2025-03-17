#include <stdio.h>

#define N 3

void gaussJordan(double a[N][N+1]) {
    int i, j, k;
    double factor;

    for (i = 0; i < N; i++) {
        factor = a[i][i];
        for (j = 0; j <= N; j++) {
            a[i][j] /= factor;
        }

        for (k = 0; k < N; k++) {
            if (k != i) {
                factor = a[k][i];
                for (j = 0; j <= N; j++) {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }
    }

    for (i = 0; i < N; i++) {
        printf("x[%d] = %lf\n", i + 1, a[i][N]);
    }
}

int main() {
    double a[N][N+1] = {
        {1, 1, 1, 1},
        {4, 3, -1, 6},
        {3, 5, 3, 4}
    };

    gaussJordan(a);
    return 0;
}
