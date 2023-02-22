#include <iostream>

using namespace std;

double f(double x, double y) {
    return y - x / (y + x);
}

double eulerMethod(double y0, double h, double x) {
    double y = y0;
    for (double xi = 0; xi < x; xi += h) {
        y += h * f(xi, y);
    }
    return y;
}
int main() {
    double y0 = 1.0;
    double h = 0.02;
    double x = 0.1;
    double y = eulerMethod(y0, h, x);
    cout << "The approximate value of y for x = " << x << " is: " << y << endl;
    return 0;
}
