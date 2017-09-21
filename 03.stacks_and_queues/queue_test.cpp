#include <iostream>
#include "queue.h"

using namespace std;

int main() {
  LinkedQueue<int> q;

  q.push(1);
  q.push(2);
  cout << q.pop() << endl;
  q.push(3);
  q.push(4);
  q.print();
  cout << q.pop() << endl;
  cout << q.is_empty() << endl;
  cout << q.peek() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.is_empty() << endl;

  return 0;
}
