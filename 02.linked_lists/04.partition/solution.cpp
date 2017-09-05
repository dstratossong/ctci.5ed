#include "../02.return_kth_to_last/single_linked_list.h"

void partition(List* list, int value) {

  List* lower = new List;
  List* higher = new List;

  if (list == NULL || list->length == 0) return;
  Node* node = list->head;

  while (node != NULL) {
    if (node->value >= value) {
      higher->append(node->value);
    } else {
      lower->append(node->value);
    }
    node = node->next;
  }
  lower->connect(higher);

  list->head->implode();
  list->head = lower->head;
  list->tail = lower->tail;

  delete higher;
  delete lower;
}

int main() {

  List* list = new List;

  list->append(3);
  list->append(10);
  list->append(3);
  list->append(2);
  list->append(5);
  list->append(9);
  list->append(1);
  list->append(8);
  list->print();

  partition(list, 5);
  list->print();

  partition(list, 3);
  list->print();

  list->implode();
  delete list;

  return 0;
}
