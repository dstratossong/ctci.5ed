#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool one_away(const string& a, const string& b) {
  int length = max(a.length(), b.length());
  int diff = abs((int) (a.length() - b.length()));

  if (diff > 1) {
    return false;
  }

  int i, j;

  // from the left
  for (i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) break;
  }

  if (i == a.length()) {
      return true;
  }

  // from the right
  for (j = 1; j < length - i; j++) {
    if (a[a.length() - j] != b[b.length() - j]) break;
  }

  return i + j == length;
}


int main() {
  string a, b;

  getline(cin, a);
  getline(cin, b);

  if (one_away(a, b)) {
    cout << "one away" << endl;
  } else {
    cout << "not one away" << endl;
  }

  return 0;
}
