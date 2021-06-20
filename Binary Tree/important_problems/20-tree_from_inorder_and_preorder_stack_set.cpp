#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

set<node *> s;
stack<node *> st;

node *buildTree(int preorder[], int inorder[], int n)
{

  node *root = NULL;
  for (int pre = 0, in = 0; pre < n;)
  {

    node *Node = NULL;
    do
    {
      Node = new node(preorder[pre]);
      if (root == NULL)
      {
        root = Node;
      }
      if (st.size() > 0)
      {
        if (s.find(st.top()) != s.end())
        {
          s.erase(st.top());
          st.top()->right = Node;
          st.pop();
        }
        else
        {
          st.top()->left = Node;
        }
      }
      st.push(Node);
    } while (preorder[pre++] != inorder[in] && pre < n);

    Node = NULL;
    while (st.size() > 0 && in < n &&
           st.top()->data == inorder[in])
    {
      Node = st.top();
      st.pop();
      in++;
    }

    if (Node != NULL)
    {
      s.insert(Node);
      st.push(Node);
    }
  }

  return root;
}

void printInorder(node *node)
{
  if (node == NULL)
    return;

  /* first recur on left child */
  printInorder(node->left);

  /* then print the data of node */
  cout << node->data << " ";

  /* now recur on right child */
  printInorder(node->right);
}

int main()
{
  int in[] = {9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7};
  int pre[] = {1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13};
  int len = sizeof(in) / sizeof(int);

  node *root = buildTree(pre, in, len);

  printInorder(root);

  return 0;
}
