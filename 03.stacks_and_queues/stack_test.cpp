#include <iostream>

#include "stack.h"

using namespace std;

int main() {
  LinkedStack<int> s;
  s.push(3);
  s.push(5);

  cout << s.is_empty() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.is_empty() << endl;

  return 0;
}
