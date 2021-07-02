#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

node *buildTree(char in[], char pre[], int inStart,
                int inEnd, unordered_map<char, int> &map)
{
  static int preIndex = 0;

  if (inStart > inEnd)
    return NULL;

  /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
  char curr = pre[preIndex++];
  node *tNode = new node(curr);

  /* If this node has no children then return */
  if (inStart == inEnd)
    return tNode;

  /* Else find the index of this node in Inorder traversal */
  int inIndex = map[curr];

  /* Using index in Inorder traversal, construct left and
    right subtress */
  tNode->left = buildTree(in, pre, inStart, inIndex - 1, map);
  tNode->right = buildTree(in, pre, inIndex + 1, inEnd, map);

  return tNode;
}

node *buildTreeWrap(char in[], char pre[], int len)
{
  // Store indexes of all items so that we
  // we can quickly find later
  unordered_map<char, int> map;
  for (int i = 0; i < len; i++)
    map[in[i]] = i;

  return buildTree(in, pre, 0, len - 1, map);
}

void printInorder(node *node)
{
  if (node == NULL)
    return;
  printInorder(node->left);
  cout << (char)node->data << " ";
  printInorder(node->right);
}

int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in) / sizeof(in[0]);

  node *root = buildTreeWrap(in, pre, len);

  printInorder(root);

  return 0;
}
