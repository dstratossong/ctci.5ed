#include <iostream>
#include <vector>

#include "../list.h"

using namespace std;

class MultiStack {
  public:
    static const int MAX_HEIGHT = 5;
    int cap;
    int len;

    MultiStack() {
      this->cap = 0;
      this->len = 0;
      this->set = new List<int*>();
    }

    ~MultiStack() {
      this->set->each(&delete_pointer);
      delete this->set;
    }

    static void print_pointer(int* p) {
      for (int i = 0; i < MAX_HEIGHT; i++) {
        std::cout << p[i] << " ";
      }
    }

    static void delete_pointer(int* p) {
      delete[] p;
    }

    void print() {
      this->set->print(&print_pointer);
    }

    void push(int value) {
      if (len == cap) {
        this->curr = new int[MAX_HEIGHT];
        for (int i = 0; i < MAX_HEIGHT; i++) curr[i] = 0;
        this->set->push_r(this->curr);
        this->cap += MAX_HEIGHT;
      } else {
        this->curr++;
      }
      *(this->curr) = value;
      this->len++;
    }

    int pop() {
      if (len == 0) return 0;
      *(this->curr) = 0;
      len--;
      if (len == cap - MAX_HEIGHT) {
        int* arr = this->set->pop_r();
        delete[] arr;
        cap = len;
        this->curr = this->set->last() + MAX_HEIGHT - 1;
      } else {
        this->curr--;
      }
    }

  private:
    List<int*>* set;
    int* curr;
};


int main() {
  MultiStack s;
  s.print();

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);
  s.print();

  s.pop();
  s.print();

  s.pop();
  s.pop();
  s.push(7);
  s.push(8);
  s.push(9);
  s.print();

  return 0;
}
