#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

// Finds the path from root node to given root of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false
bool findPath(node *root, vector<int> &path, int k)
{
  // base case
  if (root == NULL)
    return false;

  // Store this node in path vector. The node will be removed if
  // not in path from root to k
  path.push_back(root->data);

  // See if the k is same as root's key
  if (root->data == k)
    return true;

  // Check if k is found in left or right sub-tree
  if ((root->left && findPath(root->left, path, k)) ||
      (root->right && findPath(root->right, path, k)))
    return true;

  // If not present in subtree rooted with root, remove root from
  // path[] and return false
  path.pop_back();
  return false;
}

// Returns LCA if node n1, n2 are present in the given binary tree,
// otherwise return -1
int findLCA(node *root, int n1, int n2)
{
  // to store paths to n1 and n2 from the root
  vector<int> path1, path2;

  // Find paths from root to n1 and root to n1. If either n1 or n2
  // is not present, return -1
  if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
    return -1;

  /* Compare the paths to get the first different value */
  int i;
  for (i = 0; i < path1.size() && i < path2.size(); i++)
    if (path1[i] != path2[i])
      break;
  return path1[i - 1];
}

// Driver program to test above functions
int main()
{
  // Let us create the Binary Tree shown in above diagram.
  node *root = tree();
  cout << "LCA(4, 5) = " << findLCA(root, 4, 5) << endl;
  cout << "nLCA(4, 6) = " << findLCA(root, 4, 6) << endl;
  cout << "nLCA(3, 4) = " << findLCA(root, 3, 4) << endl;
  cout << "nLCA(2, 4) = " << findLCA(root, 2, 4) << endl;
  return 0;
}
//o(n)
