package main

import (
  "fmt"
  "math/rand"
  "strings"
  "time"
)

type TreeNode struct {
  Value int
  Parent *TreeNode
  Children []*TreeNode
}

type Tree struct {
  Root *TreeNode
}

type BinaryTreeNode struct {
  Value int
  Left *BinaryTreeNode
  Right *BinaryTreeNode
}

func (t Tree) DFS(ch chan int) {
  t.Root.dfs(ch)
  close(ch)
}

func (t TreeNode) dfs(ch chan int) {
  ch <- t.Value
  for _, v := range t.Children {
    v.dfs(ch)
  }
  ch <- -1
}

func (b *BinaryTreeNode) DFS(ch chan int) {
  b.dfs(ch)
  close(ch)
}

func (b *BinaryTreeNode) dfs(ch chan int) {
  ch <- b.Value

  if b.Left != nil {
    b.Left.dfs(ch)
  }

  if b.Right != nil {
    b.Right.dfs(ch)
  }
  ch <- -1
}

func dfsp(b *BinaryTreeNode) {
  if b == nil {
    return
  }
  fmt.Println(b.Value)
  dfsp(b.Left)
  dfsp(b.Right)
}


func (t *BinaryTreeNode) SearchParent(value int) *BinaryTreeNode {
  return searchParent(t, value)
}

func searchParent(node *BinaryTreeNode, value int) *BinaryTreeNode {
  if node == nil {
    return nil
  }

  if value == node.Value {
    return node
  }

  if value < node.Value && node.Left != nil {
    return searchParent(node.Left, value)
  }

  if value > node.Value && node.Right != nil {
    return searchParent(node.Right, value)
  }

  return node
}

func Make(size int) *Tree {
  if (size <= 0) {
    return nil
  }

  tree := new(Tree)
  r := rand.New(rand.NewSource(time.Now().Unix()))
  dst := r.Perm(size)
  src := make([]*TreeNode, 0)

  tree.Root = new(TreeNode)
  tree.Root.Value = dst[0]
  src = append(src, tree.Root)

  for i := 1; i < len(dst); i++ {
    s := src[r.Intn(len(src))]
    leaf := new(TreeNode)
    leaf.Value = dst[i]
    leaf.Children = make([]*TreeNode, 0)

    s.Children = append(s.Children, leaf)
    src = append(src, leaf)
  }

  return tree
}

func MakeBST(size int) *BinaryTreeNode {
  if (size <= 0) {
    return nil
  }

  tree := new(BinaryTreeNode)
  r := rand.New(rand.NewSource(time.Now().Unix()))
  dst := r.Perm(size)
  tree.Value = dst[0]

  for i := 1; i < len(dst); i++ {
    node := tree.SearchParent(dst[i])
    fmt.Println("Found", node.Value, "for", dst[i])

    if dst[i] == node.Value {
      continue
    }
    if dst[i] < node.Value {
      node.Left = new(BinaryTreeNode)
      node.Left.Value = dst[i]
    }
    if dst[i] > node.Value {
      node.Right = new(BinaryTreeNode)
      node.Right.Value = dst[i]
    }
  }

  return tree
}


func PrintTraversal(traversal func(chan int)) {
  ch := make(chan int)
  go traversal(ch)
  tabs := 0
  for c := range ch {
    if c == -1 {
      tabs -= 1
      continue
    }
    fmt.Println(strings.Repeat("  ", tabs), c)
    tabs += 1
  }
}

func main() {
  t := Make(5)
  PrintTraversal(t.DFS)

  bt := MakeBST(10)
  dfsp(bt)
  PrintTraversal(bt.DFS)
}
