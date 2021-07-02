#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

node *binTreeToListUtil(node *root, node **head, node **tail)
{
  if (!root)
    return root;
  node *left = root->left;
  node *right = root->right;

  binTreeToListUtil(root->left, head, tail);

  if (!*head)
    *head = root;

  root->left = *tail;

  if (*tail)
    (*tail)->right = root;

  *tail = root;

  binTreeToListUtil(root->right, head, tail);

  return root;
}

node *binTreeToList(node *root)
{

  if (!root)
    return root;
  node *head = NULL;
  node *tail = NULL;

  binTreeToListUtil(root, &head, &tail);

  return head;
}

void printList(node *node)
{
  while (node)
  {
    cout << node->data << " ";
    node = node->right;
  }
  cout << endl;
}
int main()
{
  node *root = tree();
  node *head = binTreeToList(root);
  printList(head);
  return 0;
}
