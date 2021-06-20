#include <bits/stdc++.h>
using namespace std;

// structure of a node in binary tree
struct Node
{
  int data;
  struct Node *left, *right;
};

// Utility function to create and return
// a new node for a binary tree
struct Node *newNode(int data)
{
  struct Node *temp = new Node();
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

// function to check whether the two binary trees
// are mirrors of each other or not
string areMirrors(Node *root1, Node *root2)
{
  stack<Node *> st1, st2;
  while (1)
  {
    // iterative inorder traversal of 1st tree and
    // reverse inoder traversal of 2nd tree
    while (root1 && root2)
    {
      // if the corresponding nodes in the two traversal
      // have different data values, then they are not
      // mirrors of each other.
      if (root1->data != root2->data)
        return "No";

      st1.push(root1);
      st2.push(root2);
      root1 = root1->left;
      root2 = root2->right;
    }

    // if at any point one root becomes null and
    // the other root is not null, then they are
    // not mirrors. This condition verifies that
    // structures of tree are mirrors of each other.
    if (!(root1 == NULL && root2 == NULL))
      return "No";

    if (!st1.empty() && !st2.empty())
    {
      root1 = st1.top();
      root2 = st2.top();
      st1.pop();
      st2.pop();

      /* we have visited the node and its left subtree.
               Now, it's right subtree's turn */
      root1 = root1->right;

      /* we have visited the node and its right subtree.
               Now, it's left subtree's turn */
      root2 = root2->left;
    }

    // both the trees have been completely traversed
    else
      break;
  }

  // tress are mirrors of each other
  return "Yes";
}

// Driver program to test above
int main()
{
  // 1st binary tree formation
  Node *root1 = newNode(1);         /*         1          */
  root1->left = newNode(3);         /*       /   \        */
  root1->right = newNode(2);        /*      3     2       */
  root1->right->left = newNode(5);  /*          /   \     */
  root1->right->right = newNode(4); /*         5     4    */

  // 2nd binary tree formation
  Node *root2 = newNode(1);        /*         1          */
  root2->left = newNode(2);        /*       /   \        */
  root2->right = newNode(3);       /*      2     3       */
  root2->left->left = newNode(4);  /*    /   \           */
  root2->left->right = newNode(5); /*   4    5           */

  cout << areMirrors(root1, root2);
  return 0;
}
