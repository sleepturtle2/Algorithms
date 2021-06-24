#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void printLevelOrder(node *root)
{
  if (root == nullptr)
    return;

  queue<node *> queue;
  queue.push(root);
  while (!queue.empty())
  {
    node *front = queue.front();
    cout << front->data << " ";
    queue.pop();

    if (front->left)
      queue.push(front->left);
    if (front->right)
      queue.push(front->right);
  }
}

int main()
{
  node *root = tree();
  printLevelOrder(root);
}

//25 15 50 10 22 35 70 4 12 18 24 31 44 66 90
/*
Time Complexity: O(n) where n is the number of nodes in the binary tree
Space Complexity: O(n) where n is the number of nodes in the binary tree

*/
