#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <set>
#include <chrono>

#include <iostream>


// Randomly select without bias
// https://stackoverflow.com/a/16421677/
template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
  std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
  std::advance(start, dis(g));
  return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  return select_randomly(start, end, gen);
}

// A tree node has one parent and multiple children
template <class T>
class TreeNode {
  public:
    T value;
    TreeNode* parent;
    std::set<TreeNode<T>*> children;

    TreeNode(T value) {
      this->value = value;
      this->parent = NULL;
    }

    ~TreeNode() {
      for (auto it = children.begin(); it != children.end(); it++) {
        delete *it;
      }
    }

    void connect(TreeNode<T>* child) {
      this->children.insert(child);
      child->parent = this;
    }
};


template <class T>
class Tree {
  public:
    TreeNode<T>* root;

    Tree() {
      this->root = NULL;
    }

    ~Tree() {
      delete this->root;
    }

    // Make a tree of specified size of integers
    static Tree* Make(int size) {
      if (size <= 0) return NULL;

      Tree<T>* tree = new Tree<int>();

      std::vector<int> dst;
      std::vector<TreeNode<int>*> src;

      for (int i = 1; i <= size; i++) {
        dst.push_back(i);
      }

      unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
      std::shuffle(dst.begin(), dst.end(), std::default_random_engine(seed));

      tree->root = new TreeNode<int>(dst.back());
      src.push_back(tree->root);
      dst.pop_back();

      while (!dst.empty()) {
        TreeNode<int>* a = *select_randomly(src.begin(), src.end());
        std::cout << "selected - " << a->value << std::endl;
        TreeNode<int>* new_node = new TreeNode<int>(dst.back());
        dst.pop_back();

        a->connect(new_node);
        src.push_back(new_node);
      }
      return tree;
    }

};

#endif /* TREE_H */
