#include "node.h"
#include <iostream>

using namespace std;

int main() {
  Node<int>* one = new Node<int>;
  Node<int>* two = new Node<int>(2);
  Node<int>* tre = new Node<int>;

  one->value = 1;
  tre->value = 3;

  one->next = two;
  two->next = tre;
  two->prev = one;
  tre->prev = two;

  cout << one->value << endl;
  cout << one->next->value << endl;
  cout << one->next->next->value << endl;

  delete one;
  delete two;
  delete tre;

  return 0;
}
