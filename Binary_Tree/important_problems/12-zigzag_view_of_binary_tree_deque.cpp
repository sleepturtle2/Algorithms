#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

vector<int> zigzagtraversal(node *root)
{
  deque<node *> dq;
  vector<int> ans;
  dq.push_back(root);
  ans.push_back(root->data);
  node *temp;

  int level = 1;
  while (!dq.empty())
  {
    int n = dq.size();
    for (int i = 0; i < n; i++)
    {
      //popping mechanism
      if (level % 2 == 0)
      {
        temp = dq.back();
        dq.pop_back();
      }
      else
      {
        temp = dq.front();
        dq.pop_front();
      }

      //pushing mechanism
      if (level % 2 != 0)
      {
        if (temp->right)
        {
          dq.push_back(temp->right);
          ans.push_back(temp->right->data);
        }
        if (temp->left)
        {
          dq.push_back(temp->left);
          ans.push_back(temp->left->data);
        }
      }

      else if (level % 2 == 0)
      {
        if (temp->left)
        {
          dq.push_front(temp->left);
          ans.push_back(temp->left->data);
        }
        if (temp->right)
        {
          dq.push_front(temp->right);
          ans.push_back(temp->right->data);
        }
      }
    }
    level++;
  }
  return ans;
}

int main()
{
  node *root = tree();
  vector<int> res = zigzagtraversal(root);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
