#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

void bottomView(node *root)
{
  if (!root)
    return;

  int h_dist = 0; //horizontal distance

  map<int, int> Map;       //(horizontal distance, node data)
  queue<node *> queue;     //store level order traversale
  map<node *, int> hd_map; //store the h_dist of each node

  hd_map[root] = h_dist;
  queue.push(root);

  node *temp;
  while (!queue.empty())
  {
    temp = queue.front();
    queue.pop();

    h_dist = hd_map[temp];
    Map[h_dist] = temp->data;

    if (temp->left)
    {
      hd_map[temp->left] = h_dist - 1;
      queue.push(temp->left);
    }

    if (temp->right)
    {
      hd_map[temp->right] = h_dist + 1;
      queue.push(temp->right);
    }
  }
  for (auto i = Map.begin(); i != Map.end(); i++)
    cout << i->second << " ";
}

int main()
{
  node *root = tree();
  bottomView(root);
  return 0;
}
