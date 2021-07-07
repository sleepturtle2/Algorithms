/*
Given two binary trees. We need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the non-null node will be used as the node of new tree.

Recursive Algorithm:
  Traverse the tree in Preorder fashion
  Check if both the tree nodes are NULL
    If not, then update the value
  Recur for left subtrees
  Recur for right subtrees
  Return root of updated Tree*/
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
  int data;
  struct Node *left, *right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
Node *newNode(int data)
{
  Node *new_node = new Node;
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return new_node;
}

/* Given a binary tree, print its nodes in inorder*/
void inorder(Node *node)
{
  if (!node)
    return;

  /* first recur on left child */
  inorder(node->left);

  /* then print the data of node */
  printf("%d ", node->data);

  /* now recur on right child */
  inorder(node->right);
}

/* Function to merge given two binary trees*/
Node *MergeTrees(Node *t1, Node *t2)
{
  if (!t1)
    return t2;
  if (!t2)
    return t1;
  t1->data += t2->data;
  t1->left = MergeTrees(t1->left, t2->left);
  t1->right = MergeTrees(t1->right, t2->right);
  return t1;
}

// Driver code
int main()
{
  /* Let us construct the first Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */

  Node *root1 = newNode(1);
  root1->left = newNode(2);
  root1->right = newNode(3);
  root1->left->left = newNode(4);
  root1->left->right = newNode(5);
  root1->right->right = newNode(6);

  /* Let us construct the second Binary Tree
           4
         /   \
        1     7
       /     /  \
      3     2    6   */
  Node *root2 = newNode(4);
  root2->left = newNode(1);
  root2->right = newNode(7);
  root2->left->left = newNode(3);
  root2->right->left = newNode(2);
  root2->right->right = newNode(6);

  Node *root3 = MergeTrees(root1, root2);
  printf("The Merged Binary Tree is:\n");
  inorder(root3);
  return 0;
}
/*
The Merged Binary Tree is:
7 3 5 5 2 10 12
Complexity Analysis:

Time complexity : O(n)
A total of n nodes need to be traversed. Here, n represents the minimum number of nodes from the two given trees.
Auxiliary Space : O(n)
The depth of the recursion tree can go upto n in case of a skewed tree. In average case, depth will be O(logn).*/
