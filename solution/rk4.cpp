#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
    return pow(y, 2) - pow(x, 2) / (pow(y, 2) + pow(x, 2));
}

double rk4Method(double y0, double h, double x) {
    double k1, k2, k3, k4;
    double y = y0;
    for (double xi = 0; xi < x; xi += h) {
        k1 = h * f(xi, y);
        k2 = h * f(xi + h / 2, y + k1 / 2);
        k3 = h * f(xi + h / 2, y + k2 / 2);
        k4 = h * f(xi + h, y + k3);
        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    }
    return y;
}
int main() {
    double y0 = 1.0;
    double h = 0.2;
    double x = 0.4;
    double y = rk4Method(y0, h, x);
    cout << "The approximate value of y for x = " << x << " is: " << y << endl;
    return 0;
}
