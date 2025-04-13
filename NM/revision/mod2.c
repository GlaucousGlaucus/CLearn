#include <stdio.h>
    #include <math.h>

    #define N 3

    // Sample equations:
    // 3x + y + z = 5
    // x + 4y + 2z = 6
    // 2x + y + 5z = 7

    void gauss_elimination() {
        float a[N][N+1] = {
            {3, 1, 1, 5},
            {1, 4, 2, 6},
            {2, 1, 5, 7}
        };
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                float r = a[j][i]/a[i][i];
                for (int k = 0; k <= N; k++)
                    a[j][k] -= r * a[i][k];
            }
        }
        float x[N];
        for (int i = N-1; i >= 0; i--) {
            x[i] = a[i][N];
            for (int j = i+1; j < N; j++)
                x[i] -= a[i][j]*x[j];
            x[i] /= a[i][i];
        }
        printf("Gauss-Elimination: ");
        for (int i = 0; i < N; i++) printf("%.2f ", x[i]);
        printf("\n");
    }

    void gauss_jordan() {
        float a[N][N+1] = {
            {3, 1, 1, 5},
            {1, 4, 2, 6},
            {2, 1, 5, 7}
        };
        for (int i = 0; i < N; i++) {
            float r = a[i][i];
            for (int j = 0; j <= N; j++) a[i][j] /= r;
            for (int k = 0; k < N; k++) {
                if (k != i) {
                    r = a[k][i];
                    for (int j = 0; j <= N; j++)
                        a[k][j] -= r * a[i][j];
                }
            }
        }
        printf("Gauss-Jordan: ");
        for (int i = 0; i < N; i++) printf("%.2f ", a[i][N]);
        printf("\n");
    }

    void lu_decomposition() {
        float a[N][N] = {
            {3, 1, 1},
            {1, 4, 2},
            {2, 1, 5}
        };
        float b[N] = {5, 6, 7}, y[N], x[N];
        float L[N][N] = {0}, U[N][N] = {0};
        for (int i = 0; i < N; i++) {
            L[i][i] = 1;
            for (int j = i; j < N; j++) {
                U[i][j] = a[i][j];
                for (int k = 0; k < i; k++)
                    U[i][j] -= L[i][k] * U[k][j];
            }
            for (int j = i+1; j < N; j++) {
                L[j][i] = a[j][i];
                for (int k = 0; k < i; k++)
                    L[j][i] -= L[j][k] * U[k][i];
                L[j][i] /= U[i][i];
            }
        }
        for (int i = 0; i < N; i++) {
            y[i] = b[i];
            for (int j = 0; j < i; j++) y[i] -= L[i][j]*y[j];
        }
        for (int i = N-1; i >= 0; i--) {
            x[i] = y[i];
            for (int j = i+1; j < N; j++) x[i] -= U[i][j]*x[j];
            x[i] /= U[i][i];
        }
        printf("LU-Decomposition: ");
        for (int i = 0; i < N; i++) printf("%.2f ", x[i]);
        printf("\n");
    }

    void gauss_jacobi() {
        float a[N][N] = {
            {3, 1, 1},
            {1, 4, 2},
            {2, 1, 5}
        };
        float b[N] = {5, 6, 7}, x[N] = {0}, x1[N];
        for (int it = 0; it < 10; it++) {
            for (int i = 0; i < N; i++) {
                x1[i] = b[i];
                for (int j = 0; j < N; j++) {
                    if (j != i) x1[i] -= a[i][j]*x[j];
                }
                x1[i] /= a[i][i];
            }
            for (int i = 0; i < N; i++) x[i] = x1[i];
        }
        printf("Gauss-Jacobi: ");
        for (int i = 0; i < N; i++) printf("%.2f ", x[i]);
        printf("\n");
    }

    void gauss_seidel() {
        float a[N][N] = {
            {3, 1, 1},
            {1, 4, 2},
            {2, 1, 5}
        };
        float b[N] = {5, 6, 7}, x[N] = {0};
        for (int it = 0; it < 10; it++) {
            for (int i = 0; i < N; i++) {
                float s = b[i];
                for (int j = 0; j < N; j++) {
                    if (j != i) s -= a[i][j]*x[j];
                }
                x[i] = s / a[i][i];
            }
        }
        printf("Gauss-Seidel: ");
        for (int i = 0; i < N; i++) printf("%.2f ", x[i]);
        printf("\n");
    }

    void power_method() {
        float a[N][N] = {
            {3, 1, 1},
            {1, 4, 2},
            {2, 1, 5}
        };
        float x[N] = {1, 1, 1}, x1[N];
        float lambda = 0;
        for (int k = 0; k < 10; k++) {
            for (int i = 0; i < N; i++) {
                x1[i] = 0;
                for (int j = 0; j < N; j++)
                    x1[i] += a[i][j] * x[j];
            }
            lambda = x1[0];
            for (int i = 0; i < N; i++) x[i] = x1[i]/lambda;
        }
        printf("Power Method lambda: %.4f\n", lambda);
    }

    int main() {
        gauss_elimination();
        gauss_jordan();
        lu_decomposition();
        gauss_jacobi();
        gauss_seidel();
        power_method();
        return 0;
    }
