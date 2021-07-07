//https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;
/*A tree where no leaf is much farther away from the root than any other leaf. Different balancing schemes allow different definitions of “much farther” and different amounts of work to keep them balanced.
Consider a height-balancing scheme where following conditions should be checked to determine if a binary tree is balanced.
An empty tree is height-balanced. A non-empty binary tree T is balanced if:
1) Left subtree of T is balanced
2) Right subtree of T is balanced
3) The difference between heights of left subtree and right subtree is not more than 1.
The above height-balancing scheme is used in AVL trees. The diagram below shows two trees, one of them is height-balanced and other is not. The second tree is not height-balanced because height of left subtree is 2 more than height of right subtree.*/
bool isBalanced(node *root, int *height)
{
  int lheight = 0, rheight = 0;

  bool lbalanced = false, rbalanced = false;

  if (!root)
  {
    *height = 0;
    return 1;
  }

  lbalanced = isBalanced(root->left, &lheight);
  rbalanced = isBalanced(root->right, &rheight);
  /* Height of current node is max of heights of left and
    right subtrees plus 1*/
  *height = (lheight > rheight ? lheight : rheight) + 1;

  if (abs(lheight - rheight) >= 2)
    return 0;

  else
    return lbalanced && rbalanced;
}

int main()
{
  node *root = tree();
  int height = 0;
  isBalanced(root, &height) ? cout << "Tree is balanced\n" : cout << "Tree is not balanced\n";
  return 0;
}
//o(n)
