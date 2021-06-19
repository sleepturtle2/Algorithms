#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void fillmap(node *root, int dist, int level, map<int, pair<int, int>> &map)
{
  if (!root)
    return;

  if (map.count(dist) == 0)
    map[dist] = make_pair(root->data, level);

  else if (map[dist].second > level)
    map[dist] = make_pair(root->data, level);

  fillmap(root->left, dist - 1, level + 1, map);
  fillmap(root->right, dist + 1, level + 1, map);
}

void topView(node *root)
{
  //map to store the pair of node value and its level with respect to the vertical distance from root
  map<int, pair<int, int>> map;
  //fillmap(root, vertical distance from root, level of node, map)
  fillmap(root, 0, 0, map);

  for (auto it = map.begin(); it != map.end(); it++)
  {
    cout << it->second.first << " ";
  }
}

int main()
{
  node *root = tree();
  topView(root);
  return 0;
}
