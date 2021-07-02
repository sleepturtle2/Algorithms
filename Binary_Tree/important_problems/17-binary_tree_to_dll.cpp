#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

node *binTreeToListUtil(node *root)
{
  if (!root)
    return root;

  //convert the left subtree and link to root
  if (root->left)
  {
    node *left = binTreeToListUtil(root->left);

    //find inorder predecessor
    for (; left->right != NULL; left = left->right)
      ;

    //make root as next of the predecessor
    left->right = root;

    //make predecessor as previous of root
    root->left = left;
  }

  //convert the right subtree and link to root
  if (root->right)
  {
    node *right = binTreeToListUtil(root->right);

    //find inorder successor
    for (; right->left != NULL; right = right->left)
      ;

    //make root as previous of successor
    right->left = root;

    //make successor as next of root
    root->right = right;
  }
  return root;
}

node *binTreeToList(node *root)
{
  if (!root)
    return root;

  root = binTreeToListUtil(root);

  //the util function returns root node of the converted dll.
  //we need pointer to the leftmost node which is the head of the constructed dll
  while (root->left)
    root = root->left;
  return root;
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
