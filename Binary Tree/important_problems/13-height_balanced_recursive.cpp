//https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

int height(node *root)
{
  if (!root)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(node *root)
{
  int lheight;
  int rheight;
  if (!root)
    return 1;
  lheight = height(root->left);
  rheight = height(root->right);

  if (abs(lheight - rheight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    return true;

  return false;
}

int main()
{
  node *root = tree();
  if (isBalanced(root))
    cout << "Tree is balanced\n";
  else
    cout << "Tree is not balanced\n";
  return 0;
}
//o(n2)
