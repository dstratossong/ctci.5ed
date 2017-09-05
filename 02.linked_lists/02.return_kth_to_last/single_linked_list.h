#include <iostream>

using namespace std;

class Node {
public:
  // defaults
  Node() {};
  Node(int);
  ~Node() {};

  // fields
  int value;
  Node* next = NULL;
  
  // methods
  void print(bool);
  void read();
  void implode();
};

Node::Node(int value) {
  this->value = value;
}

// Prints the whole list
void Node::print(bool newline = true) {
  cout << value;

  if (next != NULL) {
    cout << " ";
    next->print(newline);
  } else {
    if (newline) cout << endl;
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

class List {
public:

  // defaults
  List();
  ~List() {};

  // fields
  int length;
  Node* head;
  Node* tail;

  // methods
  void print();
  // void read();
  void implode();
  void append(int);
  // void prepend();
  void connect(List*);
};

List::List() {
  this->length = 0;
  this->head = NULL;
  this->tail = NULL;
}

void List::implode() {
  if (this->head != NULL) {
    this->head->implode();
  }
}

void List::print() {
  cout << "[";
  if (this->head != NULL) this->head->print(false);
  cout << "]" << endl;
}

// adds a new node at the end of list with the value
void List::append(int value) {
  Node* new_node = new Node(value);
  if (this->length == 0) {
    this->head = new_node;
    this->tail = new_node;
  } else {
    this->tail->next = new_node;
    this->tail = new_node;
  }
  this->length++;
}

// connects two lists together through pointers
// careful! calling implode on other after connecting
// will cause undefined behavior (shared pointers)
void List::connect(List* other) {
  if (other == NULL) return;

  if (this->length == 0) {
    this->head = other->head;
  } else {
    this->tail->next = other->head;
  }

  if (other->length != 0) {
    this->tail = other->tail;
  }

  this->length += other->length;
}
