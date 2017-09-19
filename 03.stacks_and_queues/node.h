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

    // This will delete the inner value
    //   This means if T is a pointer, 
    //   we will call delete T
    ~Node() {
      delete_if_pointer(value);
    }

  private:
    static void delete_if_pointer(const T& t) {
      // not a pointer!
    }
    static void delete_if_pointer(T* t) {
      delete t;
    }
};

#endif /* NODE_H */
