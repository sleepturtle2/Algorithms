#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

bool checkrootUtil(node *root,
                   int level, int *leafLevel)
{
  // Base case
  if (root == NULL)
    return true;

  // If a leaf node is encountered
  if (root->left == NULL &&
      root->right == NULL)
  {
    // When a leaf node is found
    // first time
    if (*leafLevel == 0)
    {
      *leafLevel = level; // Set first found leaf's level
      return true;
    }

    // If this is not first leaf node, compare
    // its level with first leaf's level
    return (level == *leafLevel);
  }

  // If this node is not leaf, recursively
  // check left and right subtrees
  return checkrootUtil(root->left, level + 1, leafLevel) &&
         checkrootUtil(root->right, level + 1, leafLevel);
}

bool checkroot(node *root)
{
  int level = 0, leafLevel = 0;
  return checkrootUtil(root, level, &leafLevel);
}

int main()
{
  node *root = tree();
  if (checkroot(root))
    cout << "Leaves are at the same level\n";
  else
    cout << "Leaves are not at the same level\n";
  return 0;
}
