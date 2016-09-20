// CTCI 1.4
// UNTIMED

#include <iostream>

using namespace std;

char* replace(char* s, int n) {
  if (s) {
    int nspace = 0;
    for (int i=0; i<n; ++i) {
      if (*(s + i) == ' ') ++nspace;
    }

    char* f = s + n - 1;
    while (nspace != 0) {
      if (*f == ' ') {
        *(f + 2*nspace) = '0';
        *(f + 2*nspace - 1) = '2';
        *(f + 2*nspace - 2) = '%';
        nspace--;
      } else {
        *(f + 2*nspace) = *f;
      }
      f--;
    }
  }

  return s;
}

int main() {
  char s[18] = "Mr John Smithaaaa";

  replace(s, 13);


  for (int i = 0; i < 17; i++) {
    cout << s[i];
  }
  cout << endl;


  return 0;
}
