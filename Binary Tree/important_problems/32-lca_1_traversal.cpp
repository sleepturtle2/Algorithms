#include <iostream>
#include "../00-binary_tree.h"
using namespace std;

// This function returns pointer to LCA of two given values n1 and n2.
// v1 is set as true by this function if n1 is found
// v2 is set as true by this function if n2 is found
node *findLCAUtil(node *root, int n1, int n2, bool &v1, bool &v2)
{
  // Base case
  if (root == NULL)
    return NULL;

  // If either n1 or n2 matches with root's key, report the presence
  // by setting v1 or v2 as true and return root (Note that if a key
  // is ancestor of other, then the ancestor key becomes LCA)
  if (root->data == n1)
  {
    v1 = true;
    return root;
  }
  if (root->data == n2)
  {
    v2 = true;
    return root;
  }

  // Look for keys in left and right subtrees
  node *left_lca = findLCAUtil(root->left, n1, n2, v1, v2);
  node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

  // If both of the above calls return Non-NULL, then one key
  // is present in once subtree and other is present in other,
  // So this node is the LCA
  if (left_lca && right_lca)
    return root;

  // Otherwise check if left subtree or right subtree is LCA
  return (left_lca != NULL) ? left_lca : right_lca;
}

// Returns true if key k is present in tree rooted with root
bool find(node *root, int k)
{
  // Base Case
  if (root == NULL)
    return false;

  // If key is present at root, or in left subtree or right subtree,
  // return true;
  if (root->data == k || find(root->left, k) || find(root->right, k))
    return true;

  // Else return false
  return false;
}

// This function returns LCA of n1 and n2 only if both n1 and n2 are present
// in tree, otherwise returns NULL;
node *findLCA(node *root, int n1, int n2)
{
  // Initialize n1 and n2 as not visited
  bool v1 = false, v2 = false;

  // Find lca of n1 and n2 using the technique discussed above
  node *lca = findLCAUtil(root, n1, n2, v1, v2);

  // Return LCA only if both n1 and n2 are present in tree
  if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
    return lca;

  // Else return NULL
  return NULL;
}

// Driver program to test above functions
int main()
{
  // Let us create binary tree given in the above example
  node *root = tree();
  node *lca = findLCA(root, 4, 5);
  if (lca != NULL)
    cout << "LCA(4, 5) = " << lca->data;
  else
    cout << "Keys are not present ";

  lca = findLCA(root, 4, 10);
  if (lca != NULL)
    cout << "nLCA(4, 10) = " << lca->data;
  else
    cout << "nKeys are not present ";

  return 0;
}
