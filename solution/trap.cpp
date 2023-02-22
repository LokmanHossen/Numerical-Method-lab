#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return sin(x) - log(x) + exp(x);
}
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    return h * sum;
}
int main() {
    double a = 0.2;
    double b = 1.4;
    int n = 100;
    double result = trapezoidalRule(a, b, n);
    cout << "The approximate value of the integral of sin(x) - ln(x) + e^x over the interval [0.2, 1.4] is: " << result << endl;
    return 0;
}
