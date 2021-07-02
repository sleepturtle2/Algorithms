#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;
int toSumTree(node *Node)
{
  // Base case
  if (Node == NULL)
    return 0;

  // Store the old value
  int old_val = Node->data;

  // Recursively call for left and
  // right subtrees and store the sum as
  // old value of this node
  Node->data = toSumTree(Node->left) + toSumTree(Node->right);

  // Return the sum of values of nodes
  // in left and right subtrees and
  // old_value of this node
  return Node->data + old_val;
}

void printInorder(node *Node)
{
  if (Node == NULL)
    return;
  printInorder(Node->left);
  cout << " " << Node->data;
  printInorder(Node->right);
}

int main()
{
  node *root = tree();
  toSumTree(root);

  printInorder(root);
  return 0;
}
