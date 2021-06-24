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
node *mirrorTree(node *root)
{
  if (root == nullptr)
    return root;

  node *temp = root->left;
  root->left = root->right;
  root->right = temp;

  if (root->left)
    mirrorTree(root->left);

  if (root->right)
    mirrorTree(root->right);

  return root;
}

int main()
{
  node *root = tree();
  cout << "inorder of the original tree\n";
  inorder(root);
  cout << endl;
  mirrorTree(root);

  cout << "inorder of the mirror tree\n";
  inorder(root);
  cout << endl;
  return 0;
}
//o(n)
