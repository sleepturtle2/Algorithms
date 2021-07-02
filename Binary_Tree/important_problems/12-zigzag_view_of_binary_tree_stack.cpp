#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void zigzagtraversal(node *root)
{
  if (!root)
    return;
  stack<node *> currentLevel;
  stack<node *> nextLevel;

  currentLevel.push(root);
  bool left_to_right = true;
  while (!currentLevel.empty())
  {
    node *temp = currentLevel.top();
    currentLevel.pop();

    if (temp)
    {
      cout << temp->data << " ";

      if (left_to_right)
      {
        if (temp->left)
          nextLevel.push(temp->left);
        if (temp->right)
          nextLevel.push(temp->right);
      }
      else
      {
        if (temp->right)
          nextLevel.push(temp->right);
        if (temp->left)
          nextLevel.push(temp->right);
      }
    }
    if (currentLevel.empty())
    {
      left_to_right = !left_to_right;
      swap(currentLevel, nextLevel);
    }
  }
}

int main()
{
  node *root = tree();
  zigzagtraversal(root);
  return 0;
}
