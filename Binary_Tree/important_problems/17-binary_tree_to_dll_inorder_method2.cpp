#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void binTreeToList(node *root, node **head)
{
  // Base case
  if (root == NULL)
    return;

  // Initialize previously visited node as NULL. This is
  // static so that the same value is accessible in all recursive
  // calls
  static node *prev = NULL;

  // Recursively convert left subtree
  binTreeToList(root->left, head);

  // Now convert this node
  if (prev == NULL)
    *head = root;
  else
  {
    root->left = prev;
    prev->right = root;
  }
  prev = root;

  // Finally convert right subtree
  binTreeToList(root->right, head);
}

void printList(node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->right;
  }
}

int main()
{
  node *root = tree();
  node *head = NULL; //head of dll
  binTreeToList(root, &head);

  printList(head);
  return 0;
}
