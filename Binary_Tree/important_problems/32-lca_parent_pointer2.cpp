#include <bits/stdc++.h>
using namespace std;

// A Tree Node
struct Node
{
  Node *left, *right, *parent;
  int key;
};

// A utility function to create a new BST node
Node *newNode(int item)
{
  Node *temp = new Node;
  temp->key = item;
  temp->parent = temp->left = temp->right = NULL;
  return temp;
}

/* A utility function to insert a new node with
given key in Binary Search Tree */
Node *insert(Node *node, int key)
{
  /* If the tree is empty, return a new node */
  if (node == NULL)
    return newNode(key);

  /* Otherwise, recur down the tree */
  if (key < node->key)
  {
    node->left = insert(node->left, key);
    node->left->parent = node;
  }
  else if (key > node->key)
  {
    node->right = insert(node->right, key);
    node->right->parent = node;
  }

  /* return the (unchanged) node pointer */
  return node;
}

// A utility function to find depth of a node
// (distance of it from root)
int depth(Node *node)
{
  int d = -1;
  while (node)
  {
    ++d;
    node = node->parent;
  }
  return d;
}

// To find LCA of nodes n1 and n2 in Binary Tree
Node *LCA(Node *n1, Node *n2)
{
  // Find depths of two nodes and differences
  int d1 = depth(n1), d2 = depth(n2);
  int diff = d1 - d2;

  // If n2 is deeper, swap n1 and n2
  if (diff < 0)
  {
    Node *temp = n1;
    n1 = n2;
    n2 = temp;
    diff = -diff;
  }

  // Move n1 up until it reaches the same level as n2
  while (diff--)
    n1 = n1->parent;

  // Now n1 and n2 are at same levels
  while (n1 && n2)
  {
    if (n1 == n2)
      return n1;
    n1 = n1->parent;
    n2 = n2->parent;
  }

  return NULL;
}

// Driver method to test above functions
int main(void)
{
  Node *root = NULL;

  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);
  root = insert(root, 14);

  Node *n1 = root->left->right->left;
  Node *n2 = root->right;

  Node *lca = LCA(n1, n2);
  printf("LCA of %d and %d is %d \n", n1->key, n2->key, lca->key);

  return 0;
}
/*
A O(h) time and O(1) Extra Space Solution:
The above solution requires extra space because we need to use a hash table to store visited ancestors. We can solve the problem in O(1) extra space using following fact : If both nodes are at same level and if we traverse up using parent pointers of both nodes, the first common node in the path to root is lca.
The idea is to find depths of given nodes and move up the deeper node pointer by the difference between depths. Once both nodes reach same level, traverse them up and return the first common node.*/
