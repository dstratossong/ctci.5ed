#include "tree.h"

int main() {

  Tree<int>* tree = Tree<int>::Make(10);
  delete tree;

  TreeNode<int>* root = new TreeNode<int>(1);

  root->connect(new TreeNode<int>(2));
  root->connect(new TreeNode<int>(3));
  root->connect(new TreeNode<int>(4));


  delete root;

  return 0;
}
