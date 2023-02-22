#include <iostream>
#include <vector>

using namespace std;

void print_matrix(vector<vector<double>> &matrix) {
  int n = matrix.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void gauss_elimination(vector<vector<double>> &matrix) {
  int n = matrix.size();
  
  // Convert to upper triangular form
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      double factor = matrix[j][i] / matrix[i][i];
      for (int k = i; k <= n; k++) {
        matrix[j][k] = matrix[j][k] - factor * matrix[i][k];
      }
    }
  }
  
  // Back-substitute to solve for x, y, z
  vector<double> solution(n);
  for (int i = n-1; i >= 0; i--) {
    solution[i] = matrix[i][n];
    for (int j = i+1; j < n; j++) {
      solution[i] = solution[i] - matrix[i][j] * solution[j];
    }
    solution[i] = solution[i] / matrix[i][i];
  }
  
  // Print the solution
  cout << "Solution: ";
  for (int i = 0; i < n; i++) {
    cout << solution[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<vector<double>> matrix = {
    {2, 1, -2, 10},
    {3, 2, 2, 1},
    {5, 4, 3, 4}
  };
  
  gauss_elimination(matrix);
  
  return 0;
}
