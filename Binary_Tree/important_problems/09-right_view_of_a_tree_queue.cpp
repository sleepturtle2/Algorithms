//practice link
//https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void rightView(node *root)
{
  if (!root)
    return;

  queue<node *> queue;
  queue.push(root);

  while (!queue.empty())
  {
    int n = queue.size();

    for (int i = 1; i <= n; i++)
    {
      node *temp = queue.front();
      queue.pop();

      if (i == n)
        cout << temp->data << " ";

      if (temp->left)
        queue.push(temp->left);
      if (temp->right)
        queue.push(temp->right);
    }
  }
}

int main()
{
  node *root = tree();
  rightView(root);
  return 0;
}
