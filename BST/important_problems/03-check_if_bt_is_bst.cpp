/*METHOD 1 (Simple but Wrong)
Following is a simple program. For each node, check if the left node of it is smaller than the node and right node of it is greater than the node.
int isBST(struct node* node)
{
  if (node == NULL)
    return 1;

  // false if left is > than node
  if (node->left != NULL && node->left->data > node->data)
    return 0;

  // false if right is < than node
  if (node->right != NULL && node->right->data < node->data)
    return 0;

  // false if, recursively, the left or right is not a BST
  if (!isBST(node->left) || !isBST(node->right))
    return 0;

  // passing all that, it's a BST
  return 1;
}*/

/*METHOD 2 (Correct but not efficient)
For each node, check if max value in left subtree is smaller than the node and min value in right subtree greater than the node.int isBST(struct node *node)*/
/*
{
  if (node == NULL)
    return 1;

  // false if the max of the left is > than us
  if (node->left != NULL && maxValue(node->left) > node->data)
    return 0;

  // false if the min of the right is <= than us
  if (node->right != NULL && minValue(node->right) < node->data)
    return 0;

  // false if, recursively, the left or right is not a BST
  if (!isBST(node->left) || !isBST(node->right))
    return 0;

  // passing all that, it's a BST
  return 1;
}*/

/*METHOD 3 (Correct and Efficient):
Method 2 above runs slowly since it traverses over some parts of the tree many times. A better solution looks at each node only once. The trick is to write a utility helper function isBSTUtil(struct node* node, int min, int max) that traverses down the tree keeping track of the narrowing min and max allowed values as it goes, looking at each node only once. The initial values for min and max should be INT_MIN and INT_MAX — they narrow from there.

Note: This method is not applicable if there are duplicate elements with value INT_MIN or INT_MAX.*/

#include <bits/stdc++.h>

using namespace std;

/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class node
{
public:
  int data;
  node *left;
  node *right;

  /* Constructor that allocates
    a new node with the given data
    and NULL left and right pointers. */
  node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

int isBSTUtil(node *node, int min, int max);

/* Returns true if the given
tree is a binary search tree
(efficient version). */
int isBST(node *node)
{
  return (isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(node *node, int min, int max)
{
  /* an empty tree is BST */
  if (node == NULL)
    return 1;

  /* false if this node violates
    the min/max constraint */
  if (node->data < min || node->data > max)
    return 0;

  /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
  return isBSTUtil(node->left, min, node->data - 1) && // Allow only distinct values
         isBSTUtil(node->right, node->data + 1, max);  // Allow only distinct values
}

/* Driver code*/
int main()
{
  node *root = new node(4);
  root->left = new node(2);
  root->right = new node(5);
  root->left->left = new node(1);
  root->left->right = new node(3);

  if (isBST(root))
    cout << "Is BST";
  else
    cout << "Not a BST";

  return 0;
}

/*Time Complexity: O(n)
Auxiliary Space: O(1) if Function Call Stack size is not considered, otherwise O(n)*/
