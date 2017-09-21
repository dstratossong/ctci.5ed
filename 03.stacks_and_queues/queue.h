#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

template <class T>
class LinkedQueue {
  public:
    LinkedQueue() {
      this->list = new List<T>();
    }

    ~LinkedQueue() {
      delete this->list;
    }

    void push(T element) {
      this->list->push_r(element);
    }

    T pop() {
      return this->list->pop_l();
    }

    T peek() {
      return this->list->first();
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

#endif /* QUEUE_H */
