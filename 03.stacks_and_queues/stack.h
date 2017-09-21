#ifndef STACK_H
#define STACK_H

#include "list.h"

template <class T>
class ArrayStack {

};

template <class T>
class LinkedStack {
  public:
    LinkedStack() {
      this->list = new List<T>();
    }

    ~LinkedStack() {
      delete this->list;
    }

    void push(T element) {
      this->list->push_r(element);
    }

    T pop() {
      return this->list->pop_r();
    }

    T peek() {
      return this->list->last();
    }

    void print() {
      this->list->print();
    }

    bool is_empty() {
      return this->list->size() == 0;
    }

  private:
    List<T>* list;
};

#endif /* STACK_H */
