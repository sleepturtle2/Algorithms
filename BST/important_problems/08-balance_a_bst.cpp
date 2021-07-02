/*
An Efficient Solution can construct balanced BST in O(n) time with minimum possible height. Below are steps.

Traverse given BST in inorder and store result in an array. This step takes O(n) time. Note that this array would be sorted as inorder traversal of BST always produces sorted sequence.
Build a balanced BST from the above created sorted array using the recursive approach discussed here. This step also takes O(n) time as we traverse every element exactly once and processing an element takes O(1) time.*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
};

/* This function traverse the skewed binary tree and
   stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node *root, vector<Node *> &nodes)
{
  // Base case
  if (root == NULL)
    return;

  // Store nodes in Inorder (which is sorted
  // order for BST)
  storeBSTNodes(root->left, nodes);
  nodes.push_back(root);
  storeBSTNodes(root->right, nodes);
}

/* Recursive function to construct binary tree */
Node *buildTreeUtil(vector<Node *> &nodes, int start,
                    int end)
{
  // base case
  if (start > end)
    return NULL;

  /* Get the middle element and make it root */
  int mid = (start + end) / 2;
  Node *root = nodes[mid];

  /* Using index in Inorder traversal, construct
       left and right subtress */
  root->left = buildTreeUtil(nodes, start, mid - 1);
  root->right = buildTreeUtil(nodes, mid + 1, end);

  return root;
}

// This functions converts an unbalanced BST to
// a balanced BST
Node *buildTree(Node *root)
{
  // Store nodes of given BST in sorted order
  vector<Node *> nodes;
  storeBSTNodes(root, nodes);

  // Constucts BST from nodes[]
  int n = nodes.size();
  return buildTreeUtil(nodes, 0, n - 1);
}

// Utility function to create a new node
Node *newNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = node->right = NULL;
  return (node);
}

/* Function to do preorder traversal of tree */
void preOrder(Node *node)
{
  if (node == NULL)
    return;
  printf("%d ", node->data);
  preOrder(node->left);
  preOrder(node->right);
}

// Driver program
int main()
{
  /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */

  Node *root = newNode(10);
  root->left = newNode(8);
  root->left->left = newNode(7);
  root->left->left->left = newNode(6);
  root->left->left->left->left = newNode(5);

  root = buildTree(root);

  printf("Preorder traversal of balanced "
         "BST is : \n");
  preOrder(root);

  return 0;
}

/*
sorted array to balanced bst
TNode* sortedArrayToBST(int arr[],
                        int start, int end)
{
    // Base Case
    if (start > end)
    return NULL;

    // Get the middle element and make it root
    int mid = (start + end)/2;
    TNode *root = newNode(arr[mid]);

    // Recursively construct the left subtree
    //and make it left child of root
    root->left = sortedArrayToBST(arr, start,
                                    mid - 1);

    // Recursively construct the right subtree
    and make it right child of root
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}
*/
