#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

int height(node *root)
{
  if (root == nullptr)
    return 0;

  return 1 + max(height(root->left), height(root->right));
}

int diameter(node *root)
{
  if (root == nullptr)
    return 0;

  int lheight = height(root->left);
  int rheight = height(root->right);

  int ldiameter = diameter(root->left);
  int rdiameter = diameter(root->right);

  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int main()
{
  node *root = tree();
  cout << diameter(root) << endl;
  return 0;
}
