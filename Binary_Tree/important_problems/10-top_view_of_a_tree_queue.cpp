//practice link
//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void topView(node *root)
{
  if (!root)
    return;
  queue<node *> queue;
  map<int, int> Map;
  int h_dist = 0; //horizontal distance, (check vertical order traversal)
  map<node *, int> hd_map;
  hd_map[root] = h_dist;

  queue.push(root);
  cout << "Top view of the tree\n";

  while (queue.size())
  {
    h_dist = hd_map[root];

    if (Map.count(h_dist) == 0)
      Map[h_dist] = root->data;

    if (root->left)
    {
      hd_map[root->left] = h_dist - 1;
      queue.push(root->left);
    }
    if (root->right)
    {
      hd_map[root->right] = h_dist + 1;
      queue.push(root->right);
    }

    queue.pop();
    root = queue.front();
  }

  for (auto it = Map.begin(); it != Map.end(); it++)
    cout << it->second << " ";
}

int main()
{
  node *root = tree();
  topView(root);
  return 0;
}
