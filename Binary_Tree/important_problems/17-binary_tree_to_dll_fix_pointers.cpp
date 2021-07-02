#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

// Changes left pointers to work as
// previous pointers in converted DLL
// The function simply does inorder
// traversal of Binary Tree and updates
// left pointer using previously visited node
void fixPrevPtr(node *root)
{
  static node *pre = NULL;

  if (root != NULL)
  {
    fixPrevPtr(root->left);
    root->left = pre;
    pre = root;
    fixPrevPtr(root->right);
  }
}

// Changes right pointers to work
// as next pointers in converted DLL
node *fixNextPtr(node *root)
{
  node *prev = NULL;

  // Find the right most node
  // in BT or last node in DLL
  while (root && root->right != NULL)
    root = root->right;

  // Start from the rightmost node,
  // traverse back using left pointers.
  // While traversing, change right pointer of nodes.
  while (root && root->left != NULL)
  {
    prev = root;
    root = root->left;
    root->right = prev;
  }

  // The leftmost node is head
  // of linked list, return it
  return (root);
}

node *binTreeToList(node *root)
{
  // Set the previous pointer
  fixPrevPtr(root);

  // Set the next pointer and return head of DLL
  return fixNextPtr(root);
}

void inorder(node *root)
{
  if (root)
  {
    inorder(root->left);
    cout << " " << root->data;
    inorder(root->right);
  }
}

void printList(node *root)
{
  while (root)
  {
    cout << " " << root->data;
    root = root->right;
  }
}

int main()
{
  node *root = tree();

  cout << "inorder traversal of the tree\n";
  inorder(root);
  cout << endl;
  node *head = binTreeToList(root);
  cout << "dll traversal\n";
  printList(head);
  cout << endl;
  return 0;
}
