#include <bits/stdc++.h>
#include "00-binary_tree.h"
using namespace std;

int maxSum(node *root, int &max_sum)
{
  if (root == nullptr)
    return 0;

  int left = maxSum(root->left, max_sum);
  int right = maxSum(root->right, max_sum);

  int temp = max(left, right) + root->data;
  if (!root->left && root->right)
    temp = max(temp, root->data);
  int ans = max(temp, left + right + root->data);
  max_sum = max(max_sum, ans);
  return temp;
}

int main()
{
  node *root = tree();
  int max_sum = INT_MIN;
  cout << maxSum(root, max_sum) << endl;
}
