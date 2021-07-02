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
  int ans = max(lheight + rheight + 1, max(ldiameter, rdiameter));
  cout << "node:" << root->data << ", lheight:" << lheight << ", rheight:" << rheight << ", height:" << height << ", ldiameter:" << ldiameter << ", rdiameter:" << rdiameter << ",ans:" << ans << endl;
  return ans;
}

int main()
{
  node *root = tree();
  int height = 0;
  cout << diameter(root, height) << endl;
  return 0;
}
/*
node:4, lheight:0, rheight:0, height:1, ldiameter:0, rdiameter:0,ans:1
node:12, lheight:0, rheight:0, height:1, ldiameter:0, rdiameter:0,ans:1
node:10, lheight:1, rheight:1, height:2, ldiameter:1, rdiameter:1,ans:3
node:18, lheight:0, rheight:0, height:1, ldiameter:0, rdiameter:0,ans:1
node:24, lheight:0, rheight:0, height:1, ldiameter:0, rdiameter:0,ans:1
node:22, lheight:1, rheight:1, height:2, ldiameter:1, rdiameter:1,ans:3
node:15, lheight:2, rheight:2, height:3, ldiameter:3, rdiameter:3,ans:5
node:31, lheight:0, rheight:0, height:1, ldiameter:0, rdiameter:0,ans:1
node:44, lheight:0, rheight:0, height:1, ldiameter:0, rdiameter:0,ans:1
node:35, lheight:1, rheight:1, height:2, ldiameter:1, rdiameter:1,ans:3
node:66, lheight:0, rheight:0, height:1, ldiameter:0, rdiameter:0,ans:1
node:90, lheight:0, rheight:0, height:1, ldiameter:0, rdiameter:0,ans:1
node:70, lheight:1, rheight:1, height:2, ldiameter:1, rdiameter:1,ans:3
node:50, lheight:2, rheight:2, height:3, ldiameter:3, rdiameter:3,ans:5
node:25, lheight:3, rheight:3, height:4, ldiameter:5, rdiameter:5,ans:7
7
Time Complexity: O(n)
*/
