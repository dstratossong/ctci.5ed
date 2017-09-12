#include <iostream>

using namespace std;

class Node {
public:
  int value;
  Node* next = NULL;
  Node* prev = NULL;

  Node(int value) {
    this->value = value;
    this->next = NULL;
    this->prev = NULL;
  }

  ~Node() {}
};

void print_forward(Node* node) {
  if (node == NULL) {
    cout << endl;
    return;
  }
  cout << node->value << " ";
  print_forward(node->next);
}

void print_reverse(Node* node) {
  if (node == NULL) {
    cout << endl;
    return;
  }
  cout << node->value << " ";
  print_reverse(node->prev);
}

bool is_palindrome(Node* head, Node* tail) {
  if (head == NULL && tail == NULL) return true;
  if (head == NULL || tail == NULL) throw "uh oh";

  if (head->value == tail->value) return is_palindrome(head->next, tail->prev);
  else return false;
}


int main() {
  // create
  Node* first = new Node(3);
  Node* secnd = new Node(4);
  Node* third = new Node(5);
  Node* forth = new Node(4);
  Node* fifth = new Node(3);

  // connect
  first->next = secnd;
  secnd->prev = first;
  secnd->next = third;
  third->prev = secnd;
  third->next = forth;
  forth->prev = third;
  forth->next = fifth;
  fifth->prev = forth;

  // print
  print_forward(first);
  print_reverse(fifth);
  cout << "is_palindrome: " << is_palindrome(first, fifth) << endl;

  //delete
  delete first;
  delete secnd;
  delete third;
  delete forth;
  delete fifth;

  return 0;
}
