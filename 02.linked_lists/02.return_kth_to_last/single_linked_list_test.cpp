#include "single_linked_list.h"

int main() {
// Using List in favor of Node
//  Node* node = new Node;
//  node->read();
//  node->print();
//  node->implode();

  List* list1 = new List;
  list1->print();
  list1->append(3);
  list1->append(5);
  list1->print();

  List* list2 = new List;
  list2->append(7);
  list2->append(9);
  list2->print();

  list1->connect(list2);
  list1->print();
  list2->print();

  list1->implode();
  delete list1;
  delete list2;

  return 0;
}
