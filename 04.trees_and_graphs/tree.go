package main

import (
  "fmt"
  "math/rand"
  "strings"
)

type TreeNode struct {
  Value int
  Parent *TreeNode
  Children []*TreeNode
}

type Tree struct {
  Root *TreeNode
}

func (t Tree) DFS(ch chan int) {
  dfs(t.Root, ch)
  close(ch)
}

func dfs(node *TreeNode, ch chan int) {
  if node == nil {
    return
  }
  ch <- node.Value
  for _, v := range node.Children {
    dfs(v, ch)
  }
  ch <- -1
}

func Make(size int) *Tree {
  if (size <= 0) {
    return nil
  }

  tree := new(Tree)
  r := rand.New(rand.NewSource(42))
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
  t := Make(1000)
  PrintTraversal(t.DFS)
}
