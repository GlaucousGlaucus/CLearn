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
    // Make 0s
    for (int i = 0; i < N; i++) {  // Pivot row
        for (int j = i+1; j < N; j++) { // Elements in the same column, i + 1 as to start from the element below
            float r = a[j][i]/a[i][i]; // Get ratio to use in row operation
            // Sub the ratio * element from the entire current operating row
            for (int k = 0; k <= N; k++)
                a[j][k] -= r * a[i][k];
        }
    }
    // Backward substitution
    float x[N];
    // This will solve ax + by + cz = d starting from the bottom row to the top
    for (int i = N-1; i >= 0; i--) { // For N = 3, i = 2, 1, 0
        // For any N, the last column will be d
        x[i] = a[i][N];
        // We then take all the other constants on RHS and substitute the value of known variables
        for (int j = i+1; j < N; j++)
            x[i] -= a[i][j]*x[j];
        // We divide the coefficient of the current unknown variable to get the value
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
    // Iterate over all rows
    for (int i = 0; i < N; i++) {
        // Normalization of row i
        float r = a[i][i]; // Take the diagonal element as ratio
        for (int j = 0; j <= N; j++) a[i][j] /= r; // Divide the whole row by that ratio
        // For all the elements above and below the current pivot element, make them 0
        for (int k = 0; k < N; k++) {
            if (k != i) { // Make sure we are not on the pivot element's row
                r = a[k][i]; // Take the element above the pivot element (same column) as ratio
                for (int j = 0; j <= N; j++) // Sub the whole row with = next row * the element above the pivot
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
    // Construct L and U matrices
    // A = LU Decomposition
    // A = [ a11 a12 a13 ]   L = [ 1   0   0  ]   U = [ u11 u12 u13 ]
    //     [ a21 a22 a23 ]       [ l21 1   0  ]       [ 0   u22 u23 ]
    //     [ a31 a32 a33 ]       [ l31 l32 1  ]       [ 0   0   u33 ]
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
    for (int it = 0; it < 10; it++) { // Iteration counter
        for (int i = 0; i < N; i++) {
            x1[i] = b[i];  // B on RHS
            for (int j = 0; j < N; j++) {
                if (j != i) x1[i] -= a[i][j]*x[j]; // Take all elements to RHS except the current
            }
            x1[i] /= a[i][i]; // Divide the coefficient of the current unknown with the RHS
        }
        for (int i = 0; i < N; i++) x[i] = x1[i]; // x1 has final result of one iteration
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
            x[i] = b[i]; // Similar to jacobi but we use x instead of x1
            for (int j = 0; j < N; j++) {
                if (j != i) x[i] -= a[i][j]*x[j];
            }
            x[i] /= a[i][i];
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
