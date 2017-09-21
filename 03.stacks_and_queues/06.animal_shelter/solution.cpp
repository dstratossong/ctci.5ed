#include <iostream>

#include "../queue.h"

using namespace std;

class AnimalShelter {
  public:
    AnimalShelter() {
      this->id = 0;
      this->dogs = new LinkedQueue<int>();
      this->cats = new LinkedQueue<int>();
    }

    ~AnimalShelter() {
      delete this->dogs;
      delete this->cats;
    }

    int next_id() {
      return this->id++;
    }

    void enqueue_cat() {
      this->cats->push(this->next_id());
    }

    void enqueue_dog() {
      this->dogs->push(this->next_id());
    }

    int dequeue_cat() {
      return this->cats->pop();
    }

    int dequeue_dog() {
      return this->dogs->pop();
    }

    int dequeue_any() {
      if (this->cats->is_empty() && this->dogs->is_empty()) 
        throw "empty";
      if (this->cats->is_empty())
        return this->dogs->pop();
      if (this->dogs->is_empty())
        return this->cats->pop();

      if (this->cats->peek() < this->dogs->peek()) 
        return this->cats->pop();
      else 
        return this->dogs->pop();
    }

    void print() {
      cout << "this->dogs: ";
      this->dogs->print();
      cout << "this->cats: ";
      this->cats->print();
    }

  private:
    LinkedQueue<int>* dogs;
    LinkedQueue<int>* cats;
    int id;
};


int main() {
  AnimalShelter s;

  s.print();
  s.enqueue_cat();
  s.enqueue_dog();
  s.enqueue_dog();
  s.enqueue_cat();
  s.print();

  cout << s.dequeue_cat() << endl;
  cout << s.dequeue_any() << endl;
  cout << s.dequeue_cat() << endl;
  cout << s.dequeue_any() << endl;

  return 0;
}
