#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void preorder_recursive(node *root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  preorder_recursive(root->left);
  preorder_recursive(root->right);
}

void preorder_iterative(node *root)
{
  if (root == nullptr)
    return;
  stack<node *> stack;
  stack.push(root);

  while (!stack.empty())
  {

    node *curr = stack.top();
    stack.pop();

    cout << curr->data << " ";
    // the right child must be pushed first so that the left child
    // is processed first (LIFO order)
    if (curr->right)
      stack.push(curr->right);
    if (curr->left)
      stack.push(curr->left);
  }
}

int main()
{
  node *root = tree();
  cout << "Recursive\n";
  preorder_recursive(root);
  cout << endl;
  cout << "Iterative\n";
  preorder_iterative(root);
  cout << endl;
}
