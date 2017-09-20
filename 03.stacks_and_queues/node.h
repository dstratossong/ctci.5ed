#ifndef NODE_H
#define NODE_H

#include <cstddef>
#include <iostream>

template <class T>
class Node {
  public:
    T value;
    Node* next;
    Node* prev;

    Node() {
      this->next = NULL;
      this->prev = NULL;
    }

    Node(T value) {
      this->value = value;
      this->next = NULL;
      this->prev = NULL;
    }

    // Will not delete inner element
    ~Node() {
    }

  private:
};

#endif /* NODE_H */
