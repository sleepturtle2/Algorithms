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
