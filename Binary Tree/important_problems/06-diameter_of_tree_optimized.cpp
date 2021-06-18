#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

int diameter(node *root, int &height)
{
  int lheight = 0, rheight = 0;

  int ldiameter = 0, rdiameter = 0;

  if (root == nullptr)
  {
    height = 0;
    return 0;
  }

  ldiameter = diameter(root->left, lheight);
  rdiameter = diameter(root->right, rheight);

  height = max(lheight, rheight) + 1;
  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int main()
{
  node *root = tree();
  int height = 0;
  cout << diameter(root, height) << endl;
  return 0;
}
