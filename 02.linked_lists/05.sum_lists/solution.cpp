#include <algorithm>
#include "../02.return_kth_to_last/single_linked_list.h"

List* add_reverse(List* m, List* n) {
  int length = std::max(m->length, n->length);

  List* sum = new List;

  int carry_over = 0;
  Node* m_curr = m->head;
  Node* n_curr = n->head;
  for (int i = 0; i <= length; i++) {
    int result;
    if (m_curr != NULL && n_curr != NULL) {
      result = m_curr->value + n_curr->value + carry_over;
    } else if (m_curr == NULL && n_curr != NULL) {
      result = n_curr->value + carry_over;
    } else if (m_curr != NULL && n_curr == NULL) {
      result = m_curr->value + carry_over;
    } else {
      // Last digit if carry over
      if (carry_over) {
        sum->append(1);
        return sum;
      } else {
        return sum;
      }
    }

    if (result >= 10) {
      sum->append(result - 10);
      carry_over = 1;
    } else {
      sum->append(result);
      carry_over = 0;
    }

    if (m_curr != NULL) m_curr = m_curr->next;
    if (n_curr != NULL) n_curr = n_curr->next;
  }


  return sum;
}

// Adds two digits, m and n, and store it in sum
// Node pointer sum should not be pointing to anything when passed in
// Returns the carry_over of this result
int add_digit(Node* m, Node* n, Node** p_sum) {
  if (m == NULL || n == NULL) {
    return 0;
  }
  
  Node* next = NULL;
  int result = m->value + n->value + add_digit(m->next, n->next, &next);

  *p_sum = new Node;
  (*p_sum)->next = next;
  if (result >= 10) {
    (*p_sum)->value = result - 10;
    return 1;
  } else {
    (*p_sum)->value = result;
    return 0;
  }
}

int increment_recur(Node* n, int k) {
  if (n == NULL) {
    throw "oh no";
  }

  if (k < 0) {
    return 1;
  }

  if (k == 0) {
    if (n->value == 9) {
      n->value = 0;
      return 1;
    } else {
      n->value += 1;
      return 0;
    }
  } else {
    if (increment_recur(n->next, k-1) == 1) {
      return increment_recur(n, 0);
    } else {
      return 0;
    }
  }
}

Node* increment(Node* n, int k) {
  if (increment_recur(n, k) == 1) {
    Node* new_head = new Node(1);
    new_head->next = n;
    return new_head;
  }
  return n;
}

List* add(List* m, List* n) {
  Node* sum = NULL;
  Node* sum_tail = NULL;

  Node* m_node = m->head;
  Node* n_node = n->head;

  int length_diff = m->length - n->length;

  if (length_diff > 0) {
    for (int i = 0; i < length_diff; i++) {
      if (sum == NULL) {
        sum = new Node(m_node->value);
        sum_tail = sum; 
      } else {
        sum_tail->next = new Node(m_node->value);
        sum_tail = sum_tail->next;
      }
      m_node = m_node->next;
    }
  } else if (length_diff < 0) {
    for (int i = 0; i < -length_diff; i++) 
      if (sum == NULL) {
        sum = new Node(n_node->value);
        sum_tail = sum; 
      } else {
        sum_tail = new Node(n_node->value);
      }
      n_node = n_node->next;
  }

  m_node->print();
  n_node->print();

  Node* sum_matching = NULL;
  int carry_over = add_digit(m_node, n_node, &sum_matching);

  sum_matching->print();
  sum_tail->next = sum_matching;
  sum->print();

  if (carry_over != 0) {
    sum = increment(sum, std::abs(length_diff) - 1);
  }

  sum->print();

  sum->implode();

  return NULL;
}

int main() {
  List* a = new List;
  List* b = new List;

  a->append(9);
  a->append(9);
  a->append(2);
  a->append(3);
  a->append(4);

  b->append(8);
  b->append(1);
  b->append(8);
  
  List* sum = add_reverse(a, b);
  sum->print();

  add(a, b);

  a->implode();
  b->implode();
  sum->implode();

  delete a;
  delete b;
  delete sum;
}
