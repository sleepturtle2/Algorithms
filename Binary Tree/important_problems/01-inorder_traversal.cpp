#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void inorder_recursive(node *root)
{
  if (root == NULL)
    return;

  inorder_recursive(root->left);
  cout << root->data << " ";
  inorder_recursive(root->right);
}

void inorder_iterative(node *root)
{
  stack<node *> stack;

  node *curr = root;

  while (!stack.empty() || curr != NULL)
  {
    if (curr != NULL)
    {
      stack.push(curr);
      curr = curr->left;
    }
    else
    {
      curr = stack.top();
      stack.pop();
      cout << curr->data << " ";
      curr = curr->right;
    }
  }
}

int main()
{
  node *root = tree();
  cout << "Recursive\n";
  inorder_recursive(root);
  cout << endl;
  cout << "Iterative\n";
  inorder_iterative(root);
  cout << endl;
}
