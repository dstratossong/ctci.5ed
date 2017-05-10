#include <iostream>

using namespace std;


void zero(int** matrix, int m, int n) {
  bool rows[m] = { false };
  bool columns[n] = { false };

  // mark
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 0) {
        rows[i] = true;
        columns[j] = true;
      }
    }
  }

  // modify
  for (int i = 0; i < m; i++) {
    if (rows[i]) {
      for (int j = 0; j < n; j++) {
        matrix[i][j] = 0;
      }
    }
  }


  for (int j = 0; j < n; j++) {
    if (columns[j]) {
      for (int i = 0; i < m; i++) {
        matrix[i][j] = 0;
      }
    }
  }

}

int main() {
  int m, n;
  int** matrix;

  cin >> m >> n;

  matrix = new int*[m];

  for (int i = 0; i < m; i++) {
    matrix[i] = new int[n];
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  zero(matrix, m, n);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
