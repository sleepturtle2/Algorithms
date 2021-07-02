/*Given an array of integers, replace every element with the least greater element on its right side in the array. If there are no greater elements on the right side, replace it with -1.

Input: [8, 58, 71, 18, 31, 32, 63, 92,
         43, 3, 91, 93, 25, 80, 28]
Output: [18, 63, 80, 25, 32, 43, 80, 93,
         80, 25, 93, -1, 28, -1, -1]

A naive method is to run two loops. The outer loop will one by one pick array elements from left to right. The inner loop will find the smallest element greater than the picked element on its right side. Finally, the outer loop will replace the picked element with the element found by inner loop. The time complexity of this method will be O(n2).

A tricky solution would be to use Binary Search Trees. We start scanning the array from right to left and insert each element into the BST. For each inserted element, we replace it in the array by its inorder successor in BST. If the element inserted is the maximum so far (i.e. its inorder successor doesn’t exist), we replace it by -1.
*/

#include <bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node
{
  int data;
  Node *left, *right;
};

// A utility function to create a new BST node
Node *newNode(int item)
{
  Node *temp = new Node;
  temp->data = item;
  temp->left = temp->right = NULL;

  return temp;
}

/* A utility function to insert a new node with
   given data in BST and find its successor */
Node *insert(Node *node, int data, Node *&succ)
{

  /* If the tree is empty, return a new node */
  if (node == NULL)
    return node = newNode(data);

  // If key is smaller than root's key, go to left
  // subtree and set successor as current node
  if (data < node->data)
  {
    succ = node;
    node->left = insert(node->left, data, succ);
  }

  // go to right subtree
  else if (data > node->data)
    node->right = insert(node->right, data, succ);
  return node;
}

// Function to replace every element with the
// least greater element on its right
void replace(int arr[], int n)
{
  Node *root = NULL;

  // start from right to left
  for (int i = n - 1; i >= 0; i--)
  {
    Node *succ = NULL;

    // insert current element into BST and
    // find its inorder successor
    root = insert(root, arr[i], succ);

    // replace element by its inorder
    // successor in BST
    if (succ)
      arr[i] = succ->data;
    else // No inorder successor
      arr[i] = -1;
  }
}

// Driver Program to test above functions
int main()
{
  int arr[] = {8, 58, 71, 18, 31, 32, 63, 92,
               43, 3, 91, 93, 25, 80, 28};
  int n = sizeof(arr) / sizeof(arr[0]);

  replace(arr, n);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}

/*
18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1
The worst-case time complexity of the above solution is also O(n2) as it uses BST. The worst-case will happen when array is sorted in ascending or descending order. The complexity can easily be reduced to O(nlogn) by using balanced trees like red-black trees.*/
