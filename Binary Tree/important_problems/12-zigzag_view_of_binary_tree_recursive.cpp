#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

int treeHeight(node *root)
{
  if (!root)
    return 0;
  int lHeight = treeHeight(root->left);
  int rHeight = treeHeight(root->right);
  return max(lHeight, rHeight) + 1;
}

void zigzagtraversalUtil(node *root, int height, bool left_to_right, vector<int> &ans)
{
  if (height == 1 && root)
    ans.push_back(root->data);
  else
  {
    if (left_to_right)
    {
      if (root->left)
        zigzagtraversalUtil(root->left, height - 1, left_to_right, ans);
      if (root->right)
        zigzagtraversalUtil(root->right, height - 1, left_to_right, ans);
    }
    else
    {
      if (root->right)
        zigzagtraversalUtil(root->right, height - 1, left_to_right, ans);
      if (root->left)
        zigzagtraversalUtil(root->left, height - 1, left_to_right, ans);
    }
  }
}

vector<int> zigzagtraversal(node *root)
{
  vector<int> ans;
  bool left_to_right = true;
  int height = treeHeight(root);

  for (int i = 1; i <= height; i++)
  {
    zigzagtraversalUtil(root, i, left_to_right, ans);
    left_to_right = !left_to_right;
  }
  return ans;
}

int main()
{
  node *root = tree();
  vector<int> res = zigzagtraversal(root);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}

//25 50 15 10 22 35 70 90 66 44 31 24 18 12 4
//o(n)
