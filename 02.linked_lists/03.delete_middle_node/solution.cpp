#include "../02.return_kth_to_last/single_linked_list.h"



// must not be the last of the list
void delete_in_the_middle(Node* node) {
  node->value = node->next->value;
  Node* tmp = node->next;
  node->next = node->next->next;
  delete tmp;
}

int main() {
  Node* list = new Node;

  list->read();

  Node* to_be_deleted = list->next;

  delete_in_the_middle(to_be_deleted);  

  list->print();
  list->implode();

  return 0;
}
