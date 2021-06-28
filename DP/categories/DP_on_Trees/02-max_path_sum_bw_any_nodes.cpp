#include <bits/stdc++.h>
#include "00-binary_tree.h"
using namespace std;

int maxSum(node *root, int max_sum)
{
  if (root == nullptr)
    return 0;

  int left = maxSum(root->left, max_sum);
  int right = maxSum(root->right, max_sum);

  // Max path for parent call of root. This path must
  // include at-most one child of root
  int max_single = max(max(left, right) + root->data, root->data);

  // Max Top represents the sum when the Node under
  // consideration is the root of the maxsum path and no
  // ancestors of root are there in max sum path
  int max_top = max(max_single, left + right + root->data);

  max_sum = max(max_sum, max_top); // Store the Maximum Result.

  return max_single;
}

int main()
{
  node *root = tree();
  int max_sum = INT_MIN;
  cout << maxSum(root, max_sum) << endl;
}
