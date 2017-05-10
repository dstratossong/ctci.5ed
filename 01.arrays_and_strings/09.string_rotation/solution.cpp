// CTCI 1.8
// START 9:30

#include <iostream>
#include <string>
using namespace std;

// returns true if a[0...n] is a substring of b
bool is_substring(string a, int m, int n, string b) {
  // implementation omitted
  return false;
}



// returns true if a is a rotation of b
bool is_rotation(string a, string b) {
  // for every a[0] in b -- i
  //   if match b[i...n] to a[0...n-i]
  //     return is_substring(a[0...i], b)
  int n = a.length();

  if (n != b.length()) return false;
  for (int i=0; i<n; i++) {
    if (b[i] == a[0]) {
      bool flag = true;
      for (int j=0; j<n-i; j++) {
        if (b[i+j] != a[j]) {
          flag = false;
          break;
        }
      }
      if (flag == true) {
        return is_substring(a, 0, i, b);
      }
    }
  }
}

// END 9:50

// Textbook solution
bool is_rotation_better(string& a, string& b) {
  string c = a + b;
  return is_substring(c, b);
}
