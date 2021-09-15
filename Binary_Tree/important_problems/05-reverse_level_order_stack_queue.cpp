//https://www.geeksforgeeks.org/reverse-level-order-traversal/
//practice link
//https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

#include <bits/stdc++.h>
using namespace std;
#include "../00-binary_tree.h"

void reverseLevelOrder(node *root)
{
  stack<node *> stack;
  queue<node *> queue;
  queue.push(root);

  while (!queue.empty())
  {
    root = queue.front();
    queue.pop();
    stack.push(root);

    if (root->right)
      queue.push(root->right);

    if (root->left)
      queue.push(root->left);
  }

  while (!stack.empty())
  {
    root = stack.top();
    cout << root->data << " ";
    stack.pop();
  }
  cout << endl;
}

int main()
{
  node *root = tree();
  reverseLevelOrder(root);
  return 0;
}

/*
4 12 18 24 31 44 66 90 10 22 35 70 15 50 25
Time Complexity: O(n) where n is the number of nodes in the binary tree.
*/
