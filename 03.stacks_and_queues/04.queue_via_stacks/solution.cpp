#include <iostream>

#include "../stack.h"

using namespace std;

template <class T>
class IdioticQueue {
  public:
  LinkedStack<T> in;
  LinkedStack<T> out;

  void push(T item) {
    in.push(item);
  }

  T pop() {
    if (out.is_empty()) {
      if (in.is_empty()) throw "empty queue";

      while (! in.is_empty()) {
        out.push(in.pop());
      }
    }

    return out.pop();
  }
};


int main() {
  IdioticQueue<int> s;

  s.push(3);
  s.push(4);

  cout << s.pop() << endl;

  s.push(5);
  s.push(6);
  s.push(7);

  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  

  return 0;
}
