//https://www.geeksforgeeks.org/reverse-level-order-traversal/
#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

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

void printGivenLevel(node *root, int level)
{
  if (root == nullptr)
    return;
  if (level == 1)
    cout << root->data << " ";
  else if (level > 1)
  {
    printGivenLevel(root->left, level - 1);
    printGivenLevel(root->right, level - 1);
  }
}

void reverseLevelOrder(node *root)
{
  int h = height(root);
  for (int i = h; i >= 1; i--) //the only line different from normal level order
    printGivenLevel(root, i);
}

int main()
{
  node *root = tree();
  reverseLevelOrder(root);
}

/*
Time Complexity: The worst-case time complexity of this method is O(n^2). For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes in the skewed tree. So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).
*/
