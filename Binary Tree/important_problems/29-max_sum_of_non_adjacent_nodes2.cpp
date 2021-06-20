#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

pair<int, int> maxSumHelper(node *root)
{
  if (root == NULL)
  {
    pair<int, int> sum(0, 0);
    return sum;
  }
  pair<int, int> sum1 = maxSumHelper(root->left);
  pair<int, int> sum2 = maxSumHelper(root->right);
  pair<int, int> sum;

  // This node is included (Left and right children
  // are not included)
  sum.first = sum1.second + sum2.second + root->data;

  // This node is excluded (Either left or right
  // child is included)
  sum.second = max(sum1.first, sum1.second) +
               max(sum2.first, sum2.second);

  return sum;
}

int maxSum(node *root)
{
  pair<int, int> res = maxSumHelper(root);
  return max(res.first, res.second);
}

// Driver code
int main()
{
  node *root = tree();
  cout << maxSum(root) << endl;
  return 0;
}
