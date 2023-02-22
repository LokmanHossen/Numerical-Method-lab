#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void gauss_seidel(vector<vector<double>> &A, vector<double> &b, vector<double> &x, double tolerance) {
  int n = A.size();
  int max_iterations = 1000;
  
  for (int k = 0; k < max_iterations; k++) {
    double max_error = 0.0;
    for (int i = 0; i < n; i++) {
      double new_xi = b[i];
      for (int j = 0; j < n; j++) {
        if (i != j) {
          new_xi -= A[i][j] * x[j];
        }
      }
      new_xi /= A[i][i];
      double error = fabs(new_xi - x[i]);
      if (error > max_error) {
        max_error = error;
      }
      x[i] = new_xi;
    }
    if (max_error < tolerance) {
      break;
    }
  }
  
  // Print the solution
  cout << "Solution: ";
  for (int i = 0; i < n; i++) {
    cout << x[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<vector<double>> A = {
    {20, 1, -2},
    {2, 20, -1},
    {2, -3, 20}
  };
  
  vector<double> b = {17, -18, 25};
  vector<double> x = {0, 0, 0}; // initial guess
  
  double tolerance = 1e-6; // desired level of accuracy
  
  gauss_seidel(A, b, x, tolerance);
  
  return 0;
}
