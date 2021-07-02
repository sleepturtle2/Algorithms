/*We can also find the inorder successor and inorder predecessor using inorder traversal . Check if the current node is smaller than the given key for predecessor and for successor, check if it is greater than the given key. If it is greater than the given key then, check if it is smaller than the already stored value in successor then, update it. At last, get the predecessor and successor stored in q(successor) and p(predecessor).

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
  int data;
  Node *left, *right;
};

// Function to return data
Node *getnode(int info)
{
  Node *p = (Node *)malloc(sizeof(Node));
  p->data = info;
  p->right = NULL;
  p->left = NULL;
  return p;
}

/*
since inorder traversal results in
ascending order visit to node , we
can store the values of the largest
no which is smaller than a (predecessor)
and smallest no which is large than
a (successor) using inorder traversal
*/
void find_p_s(Node *root, int a,
              Node **p, Node **q)
{
  // If root is null return
  if (!root)
    return;

  // traverse the left subtree
  find_p_s(root->left, a, p, q);

  // root data is greater than a
  if (root && root->data > a)
  {

    // q stores the node whose data is greater
    // than a and is smaller than the previously
    // stored data in *q which is successor
    if ((!*q) || (*q) && (*q)->data > root->data)
      *q = root;
  }

  // if the root data is smaller than
  // store it in p which is predecessor
  else if (root && root->data < a)
  {
    *p = root;
  }

  // traverse the right subtree
  find_p_s(root->right, a, p, q);
}

// Driver code
int main()
{
  Node *root1 = getnode(50);
  root1->left = getnode(20);
  root1->right = getnode(60);
  root1->left->left = getnode(10);
  root1->left->right = getnode(30);
  root1->right->left = getnode(55);
  root1->right->right = getnode(70);
  Node *p = NULL, *q = NULL;

  find_p_s(root1, 55, &p, &q);

  if (p)
    cout << p->data;
  if (q)
    cout << " " << q->data;
  return 0;
}
