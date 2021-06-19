#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void printLeftView(node *root)
{
  if (!root)
    return;

  queue<node *> queue;
  queue.push(root);

  while (!queue.empty())
  {
    int n = queue.size(); //number of nodes at the current level

    for (int i = 1; i <= n; i++)
    {
      node *temp = queue.front();
      queue.pop();

      if (i == 1) //print only the left most element
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
  printLeftView(root);
  return 0;
}
