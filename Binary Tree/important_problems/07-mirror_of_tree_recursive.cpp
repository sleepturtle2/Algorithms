//https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void inorder(node *root)
{
  if (root == nullptr)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void mirrorTree(node *root, node **mirror)
{
  if (root == nullptr)
  {
    mirror = nullptr;
    return;
  }
  *mirror = new node(root->data);
  mirrorTree(root->left, &((*mirror)->right));
  mirrorTree(root->right, &((*mirror)->left));
}

int main()
{
  node *root = tree();
  cout << "inorder of original tree\n";
  inorder(root);
  cout << endl;
  node *mirror = nullptr;
  mirrorTree(root, &mirror);
  cout << "inorder of mirror tree\n";
  inorder(mirror);
  cout << endl;
  return 0;
}

//o(n)
