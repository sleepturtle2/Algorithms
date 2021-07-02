//https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void preOrder(node *root)
{
  if (!root)
    return;

  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

// Below function accepts sttring and a pointer variable as
// an argument
// and draw the tree. Returns the root of the tree
node *constructTree(string s, int *start)
{
  //assuming no negative character in the string
  if (s.size() == 0 || *start >= s.size())
    return nullptr;

  //constructing a number from the continuous digits
  int num = 0;
  while (*start < s.size() && s[*start] != '(' && s[*start] != ')')
  {
    int num_here = (int)(s[*start] - '0');
    num = num * 10 + num_here;
    *start = *start + 1;
  }

  //creating a node from the constructed number from above loop
  node *root = new node(num);

  //check if start has reached the end of the string
  if (*start >= s.size())
    return root;

  // As soon as we see first right parenthesis from the
  // current node we start to construct the tree in the
  // left
  if (*start < s.size() && s[*start] == '(')
  {
    *start = *start + 1;
    root->left = constructTree(s, start);
  }
  if (*start < s.size() && s[*start] == ')')
    *start = *start + 1;

  // As soon as we see second right parenthesis from the
  // current node we start to construct the tree in the
  // right
  if (*start < s.size() && s[*start] == '(')
  {
    *start = *start + 1;
    root->right = constructTree(s, start);
  }
  if (*start < s.size() && s[*start] == ')')
    *start = *start + 1;
  return root;
}

int main()
{
  string s = "4(2(3)(1))(6(5))";
  int start = 0;
  node *root = constructTree(s, &start);
  preOrder(root);
  return 0;
}
//4 2 3 1 6 5
