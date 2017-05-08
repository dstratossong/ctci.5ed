// CTCI 1.6
// UNTIMED

#include <iostream>

using namespace std;

void recur(int** A, int p, int q, int m) {
  if (m <= 1) return;

  for (int i=0; i<m-1; i++) {
    int tmp           = A[p][q+i];
    A[p][q+i]         = A[p+m-1-i][q];
    A[p+m-1-i][q]     = A[p+m-1][q+m-1-i];
    A[p+m-1][q+m-1-i] = A[p+i][q+m-1];
    A[p+i][q+m-1]     = tmp;
  }

  return recur(A, p+1, q+1, m-2);
}

int main() {
  int n;
  cin >> n;

  int** A = new int*[n];
  for (int i=0; i<n; i++)
    A[i] = new int[n];

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> A[i][j];
    }
  }

  recur(A, 0, 0, n);

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
