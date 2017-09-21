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

    void each(void (*f)(T)) {
      Node<T>* curr = this->head;
      while (curr != NULL) {
        f(curr->value);
        curr = curr->next;
      }
    }

    List* print() {
      std::cout << "[";
      this->print_recur(this->head);
      std::cout << "]" << std::endl;
      
      return this;
    }

    List* print(void (*f)(T)) {
      std::cout << "[" << std::endl;
      this->print_recur(this->head, f);
      std::cout << "]" << std::endl;

      return this;
    }

    List* push_l(T element) {
      Node<T>* new_node = new Node<T>(element);
      if (this->length == 0) {
        this->head = new_node;
        this->tail = new_node;
      } else {
        this->head->prev = new_node;
        new_node->next = this->head;
        this->head = new_node;
      }
      this->length++;

      return this;
    }

    List* push_r(T element) {
      Node<T>* new_node = new Node<T>(element);
      if (this->length == 0) {
        this->head = new_node;
        this->tail = new_node;
      } else {
        this->tail->next = new_node;
        new_node->prev = this->tail;
        this->tail = new_node;
      }
      this->length++;

      return this;
    }

    T pop_l() {
      if (this->head == NULL) throw "empty";

      Node<T>* first = this->head;
      T popped = first->value;

      this->head = this->head->next;
      delete first;
      if (this->head != NULL) this->head->prev = NULL;
      this->length--;

      return popped;
    }

    T pop_r() {
      if (this->tail == NULL) throw "empty";

      Node<T>* last = this->tail;
      T popped = last->value;

      this->tail = this->tail->prev;
      delete last;
      if (this->tail != NULL) this->tail->next = NULL;
      this->length--;

      return popped;
    }

    T first() {
      if (this->head == NULL) throw "empty";

      return this->head->value;
    }

    T last() {
      if (this->tail == NULL) throw "empty";

      return this->tail->value;
    }

    int size() const {
      return this->length;
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

    void print_recur(Node<T>* node, void (*f)(T)) {
      if (node == NULL) return;
      std::cout << "  ";
      f(node->value);
      std::cout << std::endl;
      print_recur(node->next, f);
    }

    // Might cause a stack overflow if list is too long
    void delete_recur(Node<T>* node) {
      if (node->next != NULL) delete_recur(node->next);
      delete node;
    }
};

#endif /* LIST_H */
