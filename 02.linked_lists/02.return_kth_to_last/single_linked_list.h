#include <iostream>

using namespace std;

class Node {
public:
  // defaults
  Node() {};
  ~Node() {};

  // fields
  int value;
  Node* next = NULL;
  
  // methods
  void print();
  void read();
  void implode();
};

// Prints the whole list
void Node::print() {
  cout << value;

  if (next != NULL) {
    cout << " ";
    next->print();
  } else {
    cout << endl;
  }
}

// Reads from STDIN until exhausted or first error
// reads at least once, blocks until done
// stores data into nodes appended to this
void Node::read() {
  if (next != NULL) {
    throw "already have children";
  }

  cin >> value;

  Node* current = this;
  int next_value;

  while (cin >> next_value) {
    Node* next_node = new Node;
    next_node->value = next_value;
    // next_node->next = NULL;

    current->next = next_node;
    current = next_node;
  }
}

// Deletes all nodes that comes after and itself.
void Node::implode() {
  if (next != NULL) {
    next->implode();
  }
  delete this;
}

