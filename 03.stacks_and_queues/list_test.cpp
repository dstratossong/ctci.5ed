#include <iostream>

#include "list.h"

void test_int() {
  List<int>* list = new List<int>();
  list->print();
  list->push_r(3);
  list->push_r(4);
  list->push_r(5);
  list->push_r(6);
  list->push_r(7);
  list->print();

  list->pop_r();
  list->print();

  delete list;
}

class Obj {
  public:
    int i, j;
    Obj() {}
    Obj(int i, int j): i(i), j(j) {}
    Obj(const Obj& o): i(o.i), j(o.j) {}
    ~Obj() {}
};

std::ostream& operator<<(std::ostream& os, Obj const & o) {
  return os << "(" << o.i << ", " << o.j << ")";
}

void test_obj() {
  List<Obj> list;
  list.print();
  Obj j(3, 4);
  std::cout << j << std::endl;
  list.push_r(j);
  list.print();
}


int main() {
  test_int();
  test_obj();

  return 0;
}
