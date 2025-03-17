#include <stdio.h>
#include <math.h>

#define N 6

void forward_table(double target, double x[], int x_len, double val[], int n) {
    double delta[n][N];
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < n - i; j++) {
            if (i == 0) {
                delta[j-1][i] =  val[j] - val[j - 1];
            } else {
                delta[j-1][i] =  delta[j][i-1] - delta[j - 1][i-1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lf ", val[i]);
        for (int j = 0; j < N; j++) {
            printf("%lf\t", delta[i][j]);
        }
        printf("\n");
    }

    // Determine a and u and h
    double a = x[0];
    double h = x[1] - x[0];
    double u = (target - a) / h;

    double ret = val[0];
    for (int i = 0; i < N + 1; i++) {
        ret += facto
    }

}

void newton() {

}

int main() {
    double x[] = {100, 150, 200, 250, 300, 350, 400};
    double y[] = {10.63, 13.01, 15.04, 16.81, 18.42, 19.9, 21.21};
    forward_table(218, x, sizeof(x) / sizeof(x[0]), y, sizeof(y) / sizeof(y[0]));
}
