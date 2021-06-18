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
