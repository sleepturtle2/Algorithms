#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

//d is distance of current line from rightmost-topmost slope
void diagonalPrintUtil(node *root, int d, map<int, vector<int>> &diagPrint)
{
  if (!root)
    return;

  diagPrint[d].push_back(root->data);

  //increase the vertical distance if left child
  diagonalPrintUtil(root->left, d + 1, diagPrint);

  //vertical distance remains same for right child
  diagonalPrintUtil(root->right, d, diagPrint);
}

void diagonalPrint(node *root)
{
  map<int, vector<int>> diagPrint;
  diagonalPrintUtil(root, 0, diagPrint);

  for (auto it : diagPrint)
  {
    vector<int> v = it.second;
    for (auto it : v)
      cout << it << " ";
    cout << endl;
  }
}

int main()
{
  node *root = tree();
  diagonalPrint(root);
  return 0;
}
/*
25 50 70 90
15 22 24 35 44 66
10 12 18 31
4

o(n)
*/
