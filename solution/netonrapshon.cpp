#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
  return 3*x - cos(x) - 1;
}

double f_prime(double x) {
  return 3 + sin(x);
}

double newton_raphson(double x0, double tolerance) {
  double xn = x0;
  
  while (fabs(f(xn)) > tolerance) {
    xn = xn - f(xn) / f_prime(xn);
  }
  
  return xn;
}

int main() {
  double x0 = 1.0; // initial guess
  double tolerance = 1e-6; // desired level of accuracy
  
  double solution = newton_raphson(x0, tolerance);
  
  cout << "Solution: " << solution << endl;
  return 0;
}
