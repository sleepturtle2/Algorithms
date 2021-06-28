#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node *left;
  node *right;
  node(int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

node *tree()
{
  node *root = new node(25);

  root->left = new node(15);
  root->right = new node(50);

  root->left->left = new node(10);
  root->left->right = new node(22);

  root->right->left = new node(35);
  root->right->right = new node(70);

  root->left->left->left = new node(4);
  root->left->left->right = new node(12);

  root->left->right->left = new node(18);
  root->left->right->right = new node(24);

  root->right->left->left = new node(31);
  root->right->left->right = new node(44);

  root->right->right->left = new node(66);
  root->right->right->right = new node(90);
  return root;
}
