#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

// Helper function to find largest
// subtree sum recursively.
int findLargestSubtreeSumUtil(node *root, int &ans)
{
  // If current node is null then
  // return 0 to parent node.
  if (root == NULL)
    return 0;

  // Subtree sum rooted at current node.
  int currSum = root->data +
                findLargestSubtreeSumUtil(root->left, ans) + findLargestSubtreeSumUtil(root->right, ans);

  // Update answer if current subtree
  // sum is greater than answer so far.
  ans = max(ans, currSum);

  // Return current subtree sum to
  // its parent node.
  return currSum;
}

// Function to find largest subtree sum.
int findLargestSubtreeSum(node *root)
{
  // If tree does not exist,
  // then answer is 0.
  if (root == NULL)
    return 0;

  // Variable to store maximum subtree sum.
  int ans = INT_MIN;

  // Call to recursive function to
  // find maximum subtree sum.
  findLargestSubtreeSumUtil(root, ans);

  return ans;
}

int main()
{
  node *root = tree();
  cout << findLargestSubtreeSum(root) << endl;
  return 0;
}
