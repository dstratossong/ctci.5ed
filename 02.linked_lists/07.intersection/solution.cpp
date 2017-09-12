#include <iostream>
#include <map>

using namespace std;

class Node {
public:
  int value;
  Node* next;

  Node(int value) {
    this->value = value;
    this->next = NULL;
  }
  
  ~Node() {}
};

void print(Node* node) {
  if (node == NULL) {
    cout << endl;
    return;
  }
  cout << node->value;
  return print(node->next);
}

bool is_intersect(Node* list1, Node* list2) {
  map<Node*, bool> discovered;
  
  while (list1 != NULL) {
    discovered[list1] = true;
    list1 = list1->next;
  }
  while (list2 != NULL) {
    if (discovered.find(list2) != discovered.end())
      return true;
    discovered[list2] = true;
    list2 = list2->next;
  }
  return false;
}

int main() {
  // create
  Node* x = new Node(1);
  Node* y = new Node(2);
  Node* z = new Node(3);
  Node* m = new Node(4);
  Node* n = new Node(5);
  Node* p = new Node(6);
  Node* q = new Node(7);
  Node* r = new Node(8);

  // connect
  x->next = y;
  y->next = z;
  z->next = m;
  m->next = n;

  p->next = q;
  q->next = r;
  //r->next = m;
  

  // print
  print(p);
  print(x);
  cout << "is_intersect: " << is_intersect(p, x) << endl;

  // delete
  delete x;
  delete y;
  delete z;
  delete m;
  delete n;
  delete p;
  delete q;
  delete r;

  return 0;
}
