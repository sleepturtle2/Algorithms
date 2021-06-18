//https://www.geeksforgeeks.org/level-order-tree-traversal/
#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void printCurrentLevel(node *root, int level)
{
  if (root == nullptr)
    return;

  if (level == 1)
    cout << root->data << " ";
  else if (level > 1)
  {
    printCurrentLevel(root->left, level - 1);
    printCurrentLevel(root->right, level - 1);
  }
}

int height(node *root)
{
  if (root == nullptr)
    return 0;

  else
  {
    int lheight = height(root->left);
    int rheight = height(root->right);

    if (lheight > rheight)
      return lheight + 1;
    else
      return rheight + 1;
  }
}

void printLevelOrder(node *root)
{
  int h = height(root);
  for (int i = 1; i <= h; i++)
    printCurrentLevel(root, i);
}

int main()
{
  node *root = tree();
  printLevelOrder(root);
}
