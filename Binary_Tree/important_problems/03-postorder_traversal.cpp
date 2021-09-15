//practice link
//https://practice.geeksforgeeks.org/problems/postorder-traversal/1

#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void postorder_recursive(node *root)
{
  if (root == NULL)
    return;

  postorder_recursive(root->left);
  postorder_recursive(root->right);
  cout << root->data << " ";
}

void postorder_iterative(node *root)
{
  //stack to push the root node
  stack<node *> Stack;
  Stack.push(root);

  //to store postorder traversal
  stack<int> out;

  while (!Stack.empty())
  {
    node *curr = Stack.top();
    Stack.pop();

    out.push(curr->data);

    if (curr->left)
      Stack.push(curr->left);

    if (curr->right)
      Stack.push(curr->right);
  }

  //print postorder
  while (!out.empty())
  {
    cout << out.top() << " ";
    out.pop();
  }
}

int main()
{
  node *root = tree();
  cout << "Recursive\n";
  postorder_recursive(root);
  cout << endl;
  cout << "Iterative\n";
  postorder_iterative(root);
  cout << endl;
}
//ouput
//4 12 10 18 24 22 15 31 44 35 66 90 70 50 25
/*
Recursion:
Time Complexity: O(n)
Let us see different corner cases.
Complexity function T(n) — for all problem where tree traversal is involved — can be defined as:
T(n) = T(k) + T(n – k – 1) + c
Where k is the number of nodes on one side of root and n-k-1 on the other side.
Let’s do an analysis of boundary conditions
Case 1: Skewed tree (One of the subtrees is empty and other subtree is non-empty )
k is 0 in this case.
T(n) = T(0) + T(n-1) + c
T(n) = 2T(0) + T(n-2) + 2c
T(n) = 3T(0) + T(n-3) + 3c
T(n) = 4T(0) + T(n-4) + 4c
…………………………………………
………………………………………….
T(n) = (n-1)T(0) + T(1) + (n-1)c
T(n) = nT(0) + (n)c
Value of T(0) will be some constant say d. (traversing a empty tree will take some constants time)
T(n) = n(c+d)
T(n) = Θ(n) (Theta of n)
Case 2: Both left and right subtrees have equal number of nodes.
T(n) = 2T(|_n/2_|) + c
This recursive function is in the standard form (T(n) = aT(n/b) + (-)(n) ) for master method http://en.wikipedia.org/wiki/Master_theorem. If we solve it by master method we get (-)(n)
Auxiliary Space : If we don’t consider size of stack for function calls then O(1) otherwise O(h) where h is the height of the tree.

Iteration:
Time Complexity: O(n)
*/
