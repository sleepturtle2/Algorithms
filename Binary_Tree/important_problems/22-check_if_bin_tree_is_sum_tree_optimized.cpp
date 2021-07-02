#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

/* Utillity function to check if
the given node is leaf or not */
int isLeaf(node *node)
{
  if (node == NULL)
    return 0;
  if (node->left == NULL && node->right == NULL)
    return 1;
  return 0;
}

int isSumTree(node *node)
{
  int ls; // for sum of nodes in left subtree
  int rs; // for sum of nodes in right subtree

  /* If node is NULL or it's a leaf node then
       return true */
  if (node == NULL || isLeaf(node))
    return 1;

  if (isSumTree(node->left) && isSumTree(node->right))
  {

    // Get the sum of nodes in left subtree
    if (node->left == NULL)
      ls = 0;
    else if (isLeaf(node->left))
      ls = node->left->data;
    else
      ls = 2 * (node->left->data);

    // Get the sum of nodes in right subtree
    if (node->right == NULL)
      rs = 0;
    else if (isLeaf(node->right))
      rs = node->right->data;
    else
      rs = 2 * (node->right->data);

    /* If root's data is equal to sum of nodes in left
           and right subtrees then return 1 else return 0*/
    return (node->data == ls + rs);
  }
  return 0;
}

int main()
{
  node *root = tree();
  isSumTree(root) ? cout << "Is a sum tree\n" : cout << "Not a sum tree\n";
  return 0;
}
