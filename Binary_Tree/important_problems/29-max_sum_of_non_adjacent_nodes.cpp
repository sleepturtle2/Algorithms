#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

//  Declaration of methods
int sumOfGrandChildren(node *node);
int getMaxSum(node *node);
int getMaxSumUtil(node *node, map<struct node *, int> &mp);

// method returns maximum sum possible from subtrees rooted
// at grandChildrens of node 'node'
int sumOfGrandChildren(node *node, map<struct node *, int> &mp)
{
  int sum = 0;

  //  call for children of left child only if it is not NULL
  if (node->left)
    sum += getMaxSumUtil(node->left->left, mp) +
           getMaxSumUtil(node->left->right, mp);

  //  call for children of right child only if it is not NULL
  if (node->right)
    sum += getMaxSumUtil(node->right->left, mp) +
           getMaxSumUtil(node->right->right, mp);

  return sum;
}

//  Utility method to return maximum sum rooted at node 'node'
int getMaxSumUtil(node *node, map<struct node *, int> &mp)
{
  if (node == NULL)
    return 0;

  // If node is already processed then return calculated
  // value from map
  if (mp.find(node) != mp.end())
    return mp[node];

  //  take current node value and call for all grand children
  int incl = node->data + sumOfGrandChildren(node, mp);

  //  don't take current node value and call for all children
  int excl = getMaxSumUtil(node->left, mp) +
             getMaxSumUtil(node->right, mp);

  //  choose maximum from both above calls and store that in map
  mp[node] = max(incl, excl);

  return mp[node];
}

// Returns maximum sum from subset of nodes
// of binary tree under given constraints
int getMaxSum(node *node)
{
  if (node == NULL)
    return 0;
  map<struct node *, int> mp;
  return getMaxSumUtil(node, mp);
}

int main()
{
  node *root = tree();

  cout << getMaxSum(root) << endl;
  return 0;
}
