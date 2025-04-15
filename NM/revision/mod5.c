// Module V: ODE Solvers
#include <stdio.h>

// dy/dx = x + y, y(0) = 1 → Exact: y = -x - 1 + 2e^x (used just for checking)
float f(float x, float y) { return x + y; }

void euler() {
    float x = 0, y = 1, h = 0.1;
    for (int i = 0; i < 10; i++) {
        y += h * f(x, y);
        x += h;
    }
    printf("Euler y(1): %.4f\n", y);
}

void mod_euler() {
    float x = 0, y = 1, h = 0.1;
    for (int i = 0; i < 10; i++) {
        float k1 = f(x, y);
        float k2 = f(x + h, y + h * k1);
        y = y + h * (k1 + k2) / 2;
        x += h;
    }
    printf("Modified Euler y(1): %.4f\n", y);
}

void rk2() {
    float x = 0, y = 1, h = 0.1;
    for (int i = 0; i < 10; i++) {
        float k1 = h * f(x, y);
        float k2 = h * f(x + h, y + k1);
        y = y + (k1 + k2) / 2;
        x += h;
    }
    printf("RK2 y(1): %.4f\n", y);
}

void rk4() {
    float x = 0, y = 1, h = 0.1;
    for (int i = 0; i < 10; i++) {
        float k1 = h * f(x, y);
        float k2 = h * f(x + h/2, y + k1/2);
        float k3 = h * f(x + h/2, y + k2/2);
        float k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x += h;
    }
    printf("RK4 y(1): %.4f\n", y);
}

int main() {
    euler();
    mod_euler();
    rk2();
    rk4();
    return 0;
}