#include "single_linked_list.h"



Node* kth_to_last(Node* list, int k) {
  Node* front = list;
  Node* back = list;

  for (; k > 1; k--) {
    if (front->next == NULL) {
      throw "not enough elements";
    } else {
      front = front->next;
    }
  }

  while (front->next != NULL) {
    front = front->next;
    back = back->next;
  }

  return back;
}

int main() {
  int k;
  cin >> k;

  Node* list = new Node;
  list->read();

  cout << kth_to_last(list, k)->value << endl;
  list->implode();

  return 0;
}
