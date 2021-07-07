#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

vector<vector<int>> result;

void diagonalPrint(node *root)
{
  if (!root)
    return;

  queue<node *> queue;
  queue.push(root);

  while (!queue.empty())
  {
    int size = queue.size();
    vector<int> answer;

    while (size--)
    {
      node *temp = queue.front();
      queue.pop();

      while (temp)
      {
        answer.push_back(temp->data);
        if (temp->left)
          queue.push(temp->left);

        temp = temp->right;
      }
    }
    result.push_back(answer);
  }
}

int main()
{
  node *root = tree();
  diagonalPrint(root);

  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < result[i].size(); j++)
      cout << result[i][j] << " ";
    cout << endl;
  }
  return 0;
}
//o(n)
/*25 50 70 90
15 22 24 35 44 66
10 12 18 31
4 */
