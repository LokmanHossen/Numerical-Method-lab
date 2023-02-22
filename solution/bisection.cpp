#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return 2 * x - cos(x) - 2;
}
double bisectionMethod(double a, double b, double tol) {
    double fa = f(a);
    double fb = f(b);
    if (fa * fb > 0) {
        cout << "Error: f(a) and f(b) do not have opposite signs." << endl;
        return NAN;
    }
    double c = (a + b) / 2;
    while (fabs(b - a) > tol) {
        double fc = f(c);
        if (fc == 0) {
            return c;
        } else if (fc * fa < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        c = (a + b) / 2;
    }
    return c;
}
int main() {
    double a = 0.58;
    double b = -1;
    double tol = 0.001;
    double result = bisectionMethod(a, b, tol);
    cout << "The approximate root of 2x = cos(x) + 2 is: " << result << endl;
    return 0;
}
