#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

//prints in order

void topView(node *root)
{
  //store nodes and their horizontal distance from the root node
  queue<pair<node *, int>> queue;
  queue.push(make_pair(root, 0));

  int h_dist = 0; //horizontal distance
  int l_min = 0;  //current left min horizonral distance
  int r_max = 0;  //current right max horizontal distance

  //hold left node's data because they will appear in reverse order
  stack<int> left;
  vector<int> right;

  node *node;

  while (queue.size())
  {
    node = queue.front().first;
    h_dist = queue.front().second;

    if (h_dist < l_min)
    {
      left.push(node->data);
      l_min = h_dist;
    }
    else if (h_dist > r_max)
    {
      right.push_back(node->data);
      r_max = h_dist;
    }

    if (node->left)
      queue.push(make_pair(node->left, h_dist - 1));
    if (node->right)
      queue.push(make_pair(node->right, h_dist + 1));

    queue.pop();
  }

  while (left.size())
  {
    cout << left.top() << " ";
    left.pop();
  }

  cout << root->data << " ";

  for (int x : right)
    cout << x << " ";
}

int main()
{
  node *root = tree();
  topView(root);
  return 0;
}
