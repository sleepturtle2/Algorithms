#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void printLeaves(node *root)
{
  if (!root)
    return;
  printLeaves(root->left);

  //print if it is a leaf node
  if (!root->left && !root->right)
    cout << root->data << " ";
  printLeaves(root->right);
}

void printBoundaryLeft(node *root)
{
  if (!root)
    return;
  if (root->left)
  {
    //to ensure top down order, print the node before calling itself for left subtree
    cout << root->data << " ";
    printBoundaryLeft(root->left);
  }
  else if (root->right)
  {
    cout << root->data << " ";
    printBoundaryLeft(root->right);
  }
  //do nothing if it is a leaf node, this way we avoid duplicates in output
}

//print all rigt boundary nodes except leaf nodes in bottom up manner
void printBoundaryRight(node *root)
{
  if (!root)
    return;

  if (root->right)
  {
    //to ensure bottom up manner, first call for right subtree then print this node
    printBoundaryRight(root->right);
    cout << root->data << " ";
  }
  else if (root->left)
  {
    printBoundaryRight(root->left);
    cout << root->data << " ";
  }
  //do nothing if it is a leaf node, this way we avoid duplicates in output
}

void printBoundary(node *root)
{
  if (!root)
    return;

  cout << root->data << " ";

  //print the left boundary in top down manner
  printBoundaryLeft(root->left);

  //print all leaf nodes
  printLeaves(root->left);
  printLeaves(root->right);

  //print the right boundary in bottom up manner
  printBoundaryRight(root->right);
}

int main()
{
  node *root = tree();
  printBoundary(root);
  return 0;
}
