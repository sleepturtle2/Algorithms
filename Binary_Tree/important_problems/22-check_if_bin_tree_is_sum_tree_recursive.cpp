#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

// A utility function to get the sum
// of values in tree with root as root
int sum(node *root)
{
  if (root == NULL)
    return 0;

  return sum(root->left) + root->data +
         sum(root->right);
}

// Returns 1 if sum property holds for
// the given node and both of its children
int isSumTree(node *node)
{
  int ls, rs;

  // If node is NULL or it's a leaf
  // node then return true
  if (node == NULL ||
      (node->left == NULL &&
       node->right == NULL))
    return 1;

  // Get sum of nodes in left and
  // right subtrees
  ls = sum(node->left);
  rs = sum(node->right);

  // If the node and both of its
  // children satisfy the property
  // return 1 else 0
  if ((node->data == ls + rs) &&
      isSumTree(node->left) &&
      isSumTree(node->right))
    return 1;

  return 0;
}

int main()
{
  node *root = tree();

  isSumTree(root) ? cout << "Is a sum tree\n" : cout << "Not a sum tree\n";
  return 0;
}
