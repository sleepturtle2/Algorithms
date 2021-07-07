/*
Iterative Algorithm:

Create a stack
Push the root nodes of both the trees onto the stack.
While the stack is not empty, perform following steps :
  Pop a node pair from the top of the stack
  For every node pair removed, add the values corresponding to the two nodes and update the value of the corresponding node in the first tree
  If the left child of the first tree exists, push the left child(pair) of both the trees onto the stack.
  If the left child of the first tree doesn’t exist, append the left child of the second tree to the current node of the first tree
  Do same for right child pair as well.
  If both the current nodes are NULL, continue with popping the next nodes from the stack.
Return root of updated Tree
*/

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
  int data;
  struct Node *left, *right;
};

// Structure to store node pair onto stack
struct snode
{
  Node *l, *r;
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
  stack<snode> s;
  snode temp;
  temp.l = t1;
  temp.r = t2;
  s.push(temp);
  snode n;
  while (!s.empty())
  {
    n = s.top();
    s.pop();
    if (n.l == NULL || n.r == NULL)
      continue;
    n.l->data += n.r->data;
    if (n.l->left == NULL)
      n.l->left = n.r->left;
    else
    {
      snode t;
      t.l = n.l->left;
      t.r = n.r->left;
      s.push(t);
    }
    if (n.l->right == NULL)
      n.l->right = n.r->right;
    else
    {
      snode t;
      t.l = n.l->right;
      t.r = n.r->right;
      s.push(t);
    }
  }
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
  /*
  he Merged Binary Tree is:
7 3 5 5 2 10 12
Complexity Analysis:

Time complexity : O(n)
A total of n nodes need to be traversed. Here, n represents the minimum number of nodes from the two given trees.
Auxiliary Space : O(n)
The depth of the stack can go upto n in case of a skewed tree.*/
}
