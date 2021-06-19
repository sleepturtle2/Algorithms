#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void bottomViewUtil(node *root, int curr, int h_dist, map<int, pair<int, int>> &map)
{
  if (!root)
    return;
  if (map.find(h_dist) == map.end())
    map[h_dist] = make_pair(root->data, curr);
  else
  {
    pair<int, int> p = map[h_dist];
    if (p.second <= curr)
    {
      map[h_dist].second = curr;
      map[h_dist].first = root->data;
    }
  }

  bottomViewUtil(root->left, curr + 1, h_dist - 1, map);
  bottomViewUtil(root->right, curr + 1, h_dist + 1, map);
}

void bottomView(node *root)
{
  map<int, pair<int, int>> map;
  bottomViewUtil(root, 0, 0, map);

  for (auto it = map.begin(); it != map.end(); it++)
  {
    cout << it->second.first << " ";
  }
  cout << endl;
}

int main()
{
  node *root = tree();
  bottomView(root);
  return 0;
}
