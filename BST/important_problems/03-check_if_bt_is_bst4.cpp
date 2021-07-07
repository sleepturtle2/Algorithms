/*1) Do In-Order Traversal of the given tree and store the result in a temp array.

2) This method assumes that there are no duplicate values in the tree
3) Check if the temp array is sorted in ascending order, if it is, then the tree is BST.
Time Complexity: O(n)
We can avoid the use of a Auxiliary Array. While doing In-Order traversal, we can keep track of previously visited node. If the value of the currently visited node is less than the previous value, then tree is not BST.. */

/*
bool isBST(node* root)
{
    static node *prev = NULL;

    // traverse the tree in inorder fashion
    // and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
        return false;

        // Allows only distinct valued nodes
        if (prev != NULL &&
            root->data <= prev->data)
        return false;

        prev = root;

        return isBST(root->right);
    }

    return true;
}*/
//The use of a static variable can also be avoided by using a reference to the prev node as a parameter.
// C++ program to check if a given tree is BST.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to
left child and a pointer to right child */
struct Node
{
  int data;
  struct Node *left, *right;

  Node(int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

bool isBSTUtil(struct Node *root, Node *&prev)
{
  // traverse the tree in inorder fashion and
  // keep track of prev node
  if (root)
  {
    if (!isBSTUtil(root->left, prev))
      return false;

    // Allows only distinct valued nodes
    if (prev != NULL && root->data <= prev->data)
      return false;

    prev = root;

    return isBSTUtil(root->right, prev);
  }

  return true;
}

bool isBST(Node *root)
{
  Node *prev = NULL;
  return isBSTUtil(root, prev);
}

/* Driver program to test above functions*/
int main()
{
  struct Node *root = new Node(3);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(4);

  if (isBST(root))
    cout << "Is BST";
  else
    cout << "Not a BST";

  return 0;
}
//not a bst
