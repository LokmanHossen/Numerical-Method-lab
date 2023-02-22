#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return sqrt(sin(x) + cos(x));
}

double simpsons38(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 3 * f(x);
        }
    }
    return (3 * h / 8) * sum;
}

int main() {
    double a = 0;
    double b = M_PI/2;
    int n = 6;
    double result = simpsons38(a, b, n);
    cout << "The approximate value of the integral is: " << result << endl;
    return 0;
}
