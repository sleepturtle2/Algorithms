#include <bits/stdc++.h>
#include "00-binary_tree.h"
using namespace std;

int diameter(node *root, int &res)
{

  //base condition
  if (root == nullptr)
    return 0;

  //hypothesis step
  int left = diameter(root->left, res);
  int right = diameter(root->right, res);

  //induction step
  int exclude_itself = max(left, right) + 1;
  int include_itself = 1 + left + right;
  res = max(max(exclude_itself, include_itself), res);

  //return excluding itself, cause if the ans includes this, it has already been stored in res
  return exclude_itself;
}

int main()
{
  node *root = tree();
  int dia = 0;
  cout << diameter(root, dia) << endl;
}
