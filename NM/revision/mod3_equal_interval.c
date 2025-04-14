#include <stdio.h>

// Build difference table in-place
void build_diff_table(float y[][10], int n, int is_backward) {
    if (is_backward) {
        for (int i = 1; i < n; i++)
            for (int j = n - 1; j >= i; j--)
                y[j][i] = y[j][i-1] - y[j-1][i-1];
    } else {
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n - i; j++)
                y[j][i] = y[j+1][i-1] - y[j][i-1];
    }
}


// Newton Interpolation (No factorial)
float newton_interp(float x[], float y[][10], int n, float val, int is_backward) {
    float h = x[1] - x[0];
    float u = is_backward ? (val - x[n-1]) / h : (val - x[0]) / h;
    float result = is_backward ? y[n-1][0] : y[0][0];
    float term = 1.0f;

    build_diff_table(y, n, is_backward);

    for (int i = 1; i < n; i++) {
        term *= is_backward ? u + i - 1 : u - i + 1;
        result += (term / i) * (is_backward ? y[n-1][i] : y[0][i]);
    }
    return result;
}

// Gauss Interpolation (No factorial)
float gauss_interp(float x[], float y[][10], int n, float val, int is_backward) {
    float h = x[1] - x[0];
    int mid = n / 2;
    float u = (val - x[mid]) / h;
    float result = y[mid][0], term = 1.0;

    for (int i = 1; i < n; i++) {
        if (is_backward)
            for (int j = n - 1; j >= i; j--)
                y[j][i] = y[j][i-1] - y[j-1][i-1];
        else
            for (int j = 0; j < n - i; j++)
                y[j][i] = y[j+1][i-1] - y[j][i-1];
    }

    for (int i = 1; i < n; i++) {
        term *= is_backward ? (u + (i - 1)/2.0) : (u - (i - 1)/2.0);
        result += (term / i) * y[is_backward ? (mid + i/2) : (mid - i/2)][i];
    }
    return result;
}

// Build central difference table for symmetric interpolation
void build_central_diff(float y[][10], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j+1][i-1] - y[j][i-1];
        }
    }
}

// Stirling Interpolation (no factorial)
float stirling(float x[], float y[][10], int n, float val) {
    int i, j, mid = n / 2, k = 1;
    float h = x[1] - x[0], u = (val - x[mid]) / h;
    float res = y[mid][0], p = 1;

    for (i = 1; i < n; i++)
        for (j = 0; j < n - i; j++)
            y[j][i] = y[j+1][i-1] - y[j][i-1];

    for (i = 1; i < n; i++) {
        if (i % 2 == 0) {
            p *= u * u - (k - 1) * (k - 1);
            res += (p / (2 * k)) * y[mid - k][i];
            k++;
        } else {
            p *= u;
            res += (p / i) * (y[mid - k][i] + y[mid - k + 1][i]) / 2.0;
        }
    }
    return res;
}


// Bessel Interpolation (no factorial)
float bessel(float x[], float y[][10], int n, float val) {
    int i, j, mid = n / 2, k = 1;
    float h = x[1] - x[0];
    float u = (val - (x[mid] + x[mid - 1]) / 2) / h;
    float res = (y[mid][0] + y[mid - 1][0]) / 2.0, p = u;

    for (i = 1; i < n; i++)
        for (j = 0; j < n - i; j++)
            y[j][i] = y[j+1][i-1] - y[j][i-1];

    res += u * y[mid - 1][1];

    for (i = 2; i < n; i++) {
        if (i % 2 == 0) {
            p *= u * u - (k - 1) * (k - 1);
            res += (p / (2 * k)) * (y[mid - k][i] + y[mid - k + 1][i]) / 2.0;
            k++;
        } else {
            p *= u;
            res += (p / i) * y[mid - k + 1][i];
        }
    }
    return res;
}


int main() {
    float x[] = {1931, 1941, 1951, 1961, 1971, 1981};
    float y[10][10] = {
        {12}, {15}, {20}, {27}, {39}, {52}
    };
    float val = 1962;
    int n = 5;

    printf("Newton Forward:  %.3f\n", newton_interp(x, y, n, val, 0));
    printf("Newton Backward: %.3f\n", newton_interp(x, y, n, val, 1));
    printf("Gauss Forward:   %.3f\n", gauss_interp(x, y, n, val, 0));
    printf("Gauss Backward:  %.3f\n", gauss_interp(x, y, n, val, 1));
    printf("Stirling: %.3f\n", stirling(x, y, n, val));
    printf("Bessel:   %.3f\n", bessel(x, y, n, val));
}
