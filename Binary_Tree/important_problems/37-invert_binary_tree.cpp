/*Given the root of a binary tree, invert the tree, and return its root.
*/

#include<bits/stdc++.h>
using namespace std;
#include "../00-binary_tree.h"

//interative
//o(n)
node* invertTree2(node* root){
  if( !root) return root;

  stack<node*>stack;

  stack.push(root);
  while(!stack.empty()){
    node* curr = stack.top();
    stack.pop();

    node* temp = curr->left;
    curr->left = curr->right;
    curr->right = temp;

    if(curr->left) stack.push(curr->left);
    if(curr->right) stack.push(curr->right);
  }

  return root;
}

//recursive
//o(n)
node* invertTree(node* root){
  if(!root) return root;

  node* right = invertTree(root->right);
  node* left = invertTree(root->left);

  root->left = right;
  root->right = left;

  return root;
}

void print(node* root){
  if(!root) return ;

  cout<<root->data<<" ";
  print(root->left);
  print(root->right);
}

int main(){
  node* root1 = tree();

  print(invertTree(tree()));
  cout<<endl;
  //print(invertTree2(tree()));
  //cout<<endl;
}
