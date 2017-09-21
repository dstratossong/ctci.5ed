#include <iostream>
#include "../stack.h"

using namespace std;

void shift_stack(LinkedStack<int>& dst, LinkedStack<int>& src) {
  while (!src.is_empty()) {
    dst.push(src.pop());
  }
}

void shift_stack(LinkedStack<int>& dst, LinkedStack<int>& src, int extra) {
  // cout << "shift_stack extra-" << extra << endl;
  // dst.print();
  // src.print();

  bool added = false;
  while (!src.is_empty()) {
    int t = src.pop();
    if (!added && (extra > t)) {
      dst.push(extra);
      added = true;
    }
    dst.push(t);
  }

  // add at the end
  if (!added) {
    dst.push(extra);
  }
}

// returns true if sorted
bool sort_stack(LinkedStack<int>& s) {
  if (s.is_empty()) return true;

  LinkedStack<int> t;
  int prev = s.pop();
  t.push(prev);

  while (1) {
    if (s.is_empty()) {
      shift_stack(s, t);
      s.print();
      cout << "sorted" << endl;
      return true;
    }
    if (s.peek() < prev) {
      shift_stack(s, t, s.pop());
      s.print();
      return false;
    } else {
      t.push(s.pop());
    }
  }

  throw "oh nose";
}

int main() {
  
  LinkedStack<int> s;
  s.push(5);
  s.push(1);
  s.push(2);
  s.push(4);
  s.push(3);

  while (!sort_stack(s));

  return 0;
}
