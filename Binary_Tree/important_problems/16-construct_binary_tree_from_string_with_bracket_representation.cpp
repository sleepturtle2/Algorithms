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

int findIndex(string str, int start, int end)
{
  if (start > end)
    return -1;

  stack<char> stack;
  for (int i = start; i <= end; i++)
  {
    //if open paranthesis, push it
    if (str[i] == '(')
      stack.push(str[i]);
    //if close parenthesis
    else if (str[i] == ')')
    {
      if (stack.top() == '(')
      {
        stack.pop();
        //if stack is empty, this is the required index
        if (stack.empty())
          return i;
      }
    }
  }
  //if not found, return -1
  return -1;
}

node *treeFromString(string str, int start, int end)
{
  if (start > end)
    return nullptr;

  node *root = new node(str[start] - '0');
  int index = -1;

  //if next character is (, find the index of its complement )
  if (start + 1 <= end && str[start + 1] == '(')
    index = findIndex(str, start + 1, end);

  //if index found
  if (index != -1)
  {
    //call for left subtree
    root->left = treeFromString(str, start + 2, index - 1);

    //call for right subtree
    root->right = treeFromString(str, index + 2, end - 1);
  }
  return root;
}

int main()
{
  string str = "4(2(3)(1))(6(5))";
  node *root = treeFromString(str, 0, str.length() - 1);
  preOrder(root);
  return 0;
}
/*
Time Complexity: O(N2)
Auxiliary Space: O(N)
*/
