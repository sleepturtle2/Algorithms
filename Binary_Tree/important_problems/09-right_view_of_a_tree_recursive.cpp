//practice link
//https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void rightViewUtil(node *root, int level, int *max_level)
{
  if (root == nullptr)
    return;

  if (*max_level < level)
  {
    cout << root->data << " ";
    *max_level = level;
  }

  rightViewUtil(root->right, level + 1, max_level);
  rightViewUtil(root->left, level + 1, max_level);
}

void rightView(node *root)
{
  int max_level = 0;
  rightViewUtil(root, 1, &max_level);
}

int main()
{
  node *root = tree();
  rightView(root);
  return 0;
}
