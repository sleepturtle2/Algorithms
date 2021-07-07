/*
The idea is to use the fact the leftmost element (first in inorder traversal) of the tree is the least element in a BST. So we compute this value for both the trees and print the smaller one, now we delete this printed element from the respective tree and update it. Then we recursively call our function with the updated tree. We do this until one of the trees is exhausted. Now we simply print the inorder traversal of the other tree.
*/

#include <bits/stdc++.h>
using namespace std;

// Structure of a BST Node
class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int x)
  {
    data = x;
    left = right = NULL;
  }
};

// A utility function to print
// Inorder traversal of a Binary Tree
void inorder(Node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

// The function to print data
// of two BSTs in sorted order
void merge(Node *root1, Node *root2)
{
  // Base cases
  if (!root1 && !root2)
    return;

  // If the first tree is exhausted
  // simply print the inorder
  // traversal of the second tree
  if (!root1)
  {
    inorder(root2);
    return;
  }

  // If second tree is exhausted
  // simply print the inoreder
  // traversal of the first tree
  if (!root2)
  {
    inorder(root1);
    return;
  }

  // A temporary pointer currently
  // pointing to root of first tree
  Node *temp1 = root1;

  // previous pointer to store the
  // parent of temporary pointer
  Node *prev1 = NULL;

  // Traverse through the first tree until you reach
  // the leftmost element, which is the first element
  // of the tree in the inorder traversal.
  // This is the least element of the tree
  while (temp1->left)
  {
    prev1 = temp1;
    temp1 = temp1->left;
  }

  // Another temporary pointer currently
  // pointing to root of second tree
  Node *temp2 = root2;

  // Previous pointer to store the
  // parent of second temporary pointer
  Node *prev2 = NULL;

  // Traverse through the second tree until you reach
  // the leftmost element, which is the first element of
  // the tree in inorder traversal.
  // This is the least element of the tree.
  while (temp2->left)
  {
    prev2 = temp2;
    temp2 = temp2->left;
  }

  // Compare the least current least
  // elements of both the tree
  if (temp1->data <= temp2->data)
  {

    // If first tree's element is smaller print it
    cout << temp1->data << " ";

    // If the node has no parent, that
    // means this node is the root
    if (prev1 == NULL)
    {

      // Simply make the right
      // child of the root as new root
      merge(root1->right, root2);
    }

    // If node has a parent
    else
    {

      // As this node is the leftmost node,
      // it is certain that it will not have
      // a let child so we simply assign this
      // node's right pointer, which can be
      // either null or not, to its parent's left
      // pointer. This statement is
      // just doing the task of deleting the node

      prev1->left = temp1->right;

      // recursively call the merge
      // function with updated tree
      merge(root1, root2);
    }
  }
  else
  {

    cout << temp2->data << " ";

    // If the node has no parent, that
    // means this node is the root
    if (prev2 == NULL)
    {

      // Simply make the right child
      // of root as new root
      merge(root1, root2->right);
    }

    // If node has a parent
    else
    {
      prev2->left = temp2->right;

      // Recursively call the merge
      // function with updated tree
      merge(root1, root2);
    }
  }
}

// Driver Code
int main()
{
  Node *root1 = NULL, *root2 = NULL;
  root1 = new Node(3);
  root1->left = new Node(1);
  root1->right = new Node(5);
  root2 = new Node(4);
  root2->left = new Node(2);
  root2->right = new Node(6);

  // Print sorted nodes of both trees
  merge(root1, root2);

  return 0;
}

/*1 2 3 4 5 6


Time Complexity: O((M+N)(h1+h2)), where M and N are the number of nodes of the two trees and, h1 and h2 are the heights of tree respectively.
Auxiliary Space: O(1)
 */
