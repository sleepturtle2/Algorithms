/* For Binary search tree, while traversing the tree from top to bottom the first node which lies in between the two numbers n1 and n2 is the LCA of the nodes, i.e. the first node n with the lowest depth which lies in between n1 and n2 (n1<=n<=n2) n1 < n2. So just recursively traverse the BST in, if node’s value is greater than both n1 and n2 then our LCA lies in the left side of the node, if it’s is smaller than both n1 and n2, then LCA lies on the right side. Otherwise, the root is LCA (assuming that both n1 and n2 are present in BST).

Algorithm:

Create a recursive function that takes a node and the two values n1 and n2.
If the value of the current node is less than both n1 and n2, then LCA lies in the right subtree. Call the recursive function for thr right subtree.
If the value of the current node is greater than both n1 and n2, then LCA lies in the left subtree. Call the recursive function for thr left subtree.
If both the above cases are false then return the current node as LCA.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left, *right;
};

/* Function to find LCA of n1 and n2. The function assumes that both
   n1 and n2 are present in BST */
struct node *lca(struct node *root, int n1, int n2)
{
  if (root == NULL)
    return NULL;

  // If both n1 and n2 are smaller than root, then LCA lies in left
  if (root->data > n1 && root->data > n2)
    return lca(root->left, n1, n2);

  // If both n1 and n2 are greater than root, then LCA lies in right
  if (root->data < n1 && root->data < n2)
    return lca(root->right, n1, n2);

  return root;
}

/* Helper function that allocates a new node with the given data.*/
struct node *newNode(int data)
{
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = node->right = NULL;
  return (node);
}

/* Driver program to test lca() */
int main()
{
  // Let us construct the BST shown in the above figure
  struct node *root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(14);

  int n1 = 10, n2 = 14;
  struct node *t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->data);

  n1 = 14, n2 = 8;
  t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->data);

  n1 = 10, n2 = 22;
  t = lca(root, n1, n2);
  printf("LCA of %d and %d is %d \n", n1, n2, t->data);

  getchar();
  return 0;
}
/*Time Complexity: O(h).
The time Complexity of the above solution is O(h), where h is the height of the tree.
Space Complexity: O(h).
If recursive stack space is ignored, the space complexity of the above solution is constant.*/
