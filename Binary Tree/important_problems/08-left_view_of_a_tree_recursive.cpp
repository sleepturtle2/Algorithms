//https://www.geeksforgeeks.org/print-left-view-binary-tree/
#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void leftViewUtil(node *root, int level, int *max_level)
{
  if (root == nullptr)
    return;
  if (*max_level < level)
  {
    cout << root->data << " ";
    *max_level = level;
  }

  leftViewUtil(root->left, level + 1, max_level);
  leftViewUtil(root->right, level + 1, max_level);
}

void leftView(node *root)
{
  int max_level = 0;
  leftViewUtil(root, 1, &max_level);
}

int main()
{
  node *root = tree();
  leftView(root);
  return 0;
}

//o(n)
//25 15 10 4
