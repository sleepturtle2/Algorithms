#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

node *concatenate(node *leftList, node *rightList)
{
  // If either of the list is empty
  // then return the other list
  if (leftList == NULL)
    return rightList;
  if (rightList == NULL)
    return leftList;

  // Store the last Node of left List
  node *leftLast = leftList->left;

  // Store the last Node of right List
  node *rightLast = rightList->left;

  // Connect the last node of Left List
  // with the first Node of the right List
  leftLast->right = rightList;
  rightList->left = leftLast;

  // Left of first node points to
  // the last node in the list
  leftList->left = rightLast;

  // Right of last node refers to the first
  // node of the List
  rightLast->right = leftList;

  return leftList;
}

node *binTreeToCList(node *root)
{
  if (root == NULL)
    return NULL;

  // Recursively convert left and right subtrees
  node *left = binTreeToCList(root->left);
  node *right = binTreeToCList(root->right);

  // Make a circular linked list of single node
  // (or root). To do so, make the right and
  // left pointers of this node point to itself
  root->left = root->right = root;

  // Step 1 (concatenate the left list with the list
  //         with single node, i.e., current node)
  // Step 2 (concatenate the returned list with the
  //         right List)
  return concatenate(concatenate(left, root), right);
}
void displayCList(node *head)
{
  cout << "Circular Linked List is :\n";
  node *itr = head;
  do
  {
    cout << itr->data << " ";
    itr = itr->right;
  } while (head != itr);
  cout << "\n";
}

int main()
{
  node *root = tree();
  node *head = binTreeToCList(root);
  displayCList(head);
  return 0;
}
