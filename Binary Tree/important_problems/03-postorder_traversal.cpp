#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void postorder_recursive(node *root)
{
  if (root == NULL)
    return;

  postorder_recursive(root->left);
  postorder_recursive(root->right);
  cout << root->data << " ";
}

void postorder_iterative(node *root)
{
  //stack to push the root node
  stack<node *> Stack;
  Stack.push(root);

  //to store postorder traversal
  stack<int> out;

  while (!Stack.empty())
  {
    node *curr = Stack.top();
    Stack.pop();

    out.push(curr->data);

    if (curr->left)
      Stack.push(curr->left);

    if (curr->right)
      Stack.push(curr->right);
  }

  //print postorder
  while (!out.empty())
  {
    cout << out.top() << " ";
    out.pop();
  }
}

int main()
{
  node *root = tree();
  cout << "Recursive\n";
  postorder_recursive(root);
  cout << endl;
  cout << "Iterative\n";
  postorder_iterative(root);
  cout << endl;
}
