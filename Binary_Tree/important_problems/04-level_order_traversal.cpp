//https://www.geeksforgeeks.org/level-order-tree-traversal/
//practice link
//https://practice.geeksforgeeks.org/problems/level-order-traversal/1

#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void printCurrentLevel(node *root, int level)
{
  if (root == nullptr)
    return;

  if (level == 1)
    cout << root->data << " ";
  else if (level > 1)
  {
    printCurrentLevel(root->left, level - 1);
    printCurrentLevel(root->right, level - 1);
  }
}

int height(node *root)
{
  if (root == nullptr)
    return 0;

  else
  {
    int lheight = height(root->left);
    int rheight = height(root->right);

    if (lheight > rheight)
      return lheight + 1;
    else
      return rheight + 1;
  }
}

void printLevelOrder(node *root)
{
  int h = height(root);
  for (int i = 1; i <= h; i++)
    printCurrentLevel(root, i);
}

int main()
{
  node *root = tree();
  printLevelOrder(root);
}
//25 15 50 10 22 35 70 4 12 18 24 31 44 66 90
/*
Time Complexity: O(n^2) in worst case. For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes in the skewed tree. So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).
Space Complexity: O(n) in worst case. For a skewed tree, printGivenLevel() uses O(n) space for call stack. For a Balanced tree, the call stack uses O(log n) space, (i.e., the height of the balanced tree).
*/
