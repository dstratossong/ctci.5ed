#ifndef LIST_H
#define LIST_H

#include <cstddef>
#include <iostream>

#include "node.h"

template <class T>
class List {
  public:
    List() {
      this->length = 0;
      this->head = NULL;
      this->tail = NULL;
    }

    ~List() {
      for (int i = 0; i < this->length; i++) {
        this->tail = this->head->next;
        delete this->head;
        this->head = this->tail;
      }
    }

    List* print() {
      std::cout << "[";
      this->print_recur(this->head);
      std::cout << "]" << std::endl;
      
      return this;
    }

    List* push_r(T element) {
      Node<T>* new_node = new Node<T>(element);
      if (this->length == 0) {
        this->head = new_node;
        this->tail = new_node;
      } else {
        this->tail->next = new_node;
        this->tail = new_node;
      }
      this->length++;

      return this;
    }

  private:
    int length;
    Node<T>* head;
    Node<T>* tail;

    void print_recur(Node<T>* node) {
      if (node == NULL) return;
      std::cout << node->value;
      if (node->next != NULL) {
        std::cout << " ";
        print_recur(node->next);
      }
    }

    // Might cause a stack overflow if list is too long
    void delete_recur(Node<T>* node) {
      if (node->next != NULL) delete_recur(node->next);
      delete node;
    }
};

#endif /* LIST_H */
