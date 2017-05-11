#include <iostream>
#include <map>

using namespace std;

struct Node {
  int value;
  Node* next;
};

// Complexity O(n)
// Space O(n)
void remove_dup(Node* list) {
  if (list == NULL) {
    return;
  }

  map<int, bool> int_map;
  int_map[list->value] = true;

  while (list->next != NULL) {
    if (int_map.find(list->next->value) != int_map.end() && 
        int_map[list->next->value]) {
      // remove
      Node* tmp = list->next;
      list->next = list->next->next;
      delete tmp;
    } else {
      int_map[list->next->value] = true;

      // increment
      list = list->next;
    }
  }

  return;
}

void print(Node* list) {
  while (list != NULL) {
    cout << list->value << " ";
    list = list->next;
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  
  if (n < 1) {
    return 0;
  }

  Node* list = new Node;
  cin >> list->value;

  Node* current = list;

  for (; n > 1; n--) {
    Node* new_node = new Node;
    cin >> new_node->value;

    current->next = new_node;
    current = new_node;
  }

  remove_dup(list);

  print(list);

  return 0;
}
