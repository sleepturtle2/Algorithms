#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

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
