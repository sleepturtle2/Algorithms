#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void maxSumInLongestPath(node *root, int sum, int len, int &maxLen, int &maxSum)
{
  // if true, then we have traversed a
  // root to leaf path
  if (!root)
  {
    // update maximum length and maximum sum
    // according to the given conditions
    if (maxLen < len)
    {
      maxLen = len;
      maxSum = sum;
    }
    else if (maxLen == len && maxSum < sum)
      maxSum = sum;
    return;
  }

  // recur for left subtree
  maxSumInLongestPath(root->left, sum + root->data, len + 1, maxLen, maxSum);

  //recur for right subtree
  maxSumInLongestPath(root->right, sum + root->data, len + 1, maxLen, maxSum);
}

int sumUtil(node *root)
{
  if (!root)
    return 0;

  int maxSum = INT_MIN, maxLen = 0;

  maxSumInLongestPath(root, 0, 0, maxLen, maxSum);

  return maxSum;
}

int main()
{
  node *root = tree();
  cout << sumUtil(root) << endl;
  return 0;
}
