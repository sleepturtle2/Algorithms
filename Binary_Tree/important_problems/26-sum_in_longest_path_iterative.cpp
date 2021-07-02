#include <bits/stdc++.h>
#include "../00-binary_tree.h"
using namespace std;

int longestPathSum(node *root)
{

  struct Element
  {
    node *data;
    int level;
    int sum;
  };

  /*
    maxSumLevel stores maximum sum so far in the path
    maxLevel stores maximum level so far
  */
  int maxSumLevel = root->data, maxLevel = 0;

  /* queue to implement level order traversal */

  list<Element> que;
  Element e;

  /* Each element variable stores the current Node, it's level, sum in the path */

  e.data = root;
  e.level = 0;
  e.sum = root->data;

  /* push the root element*/
  que.push_back(e);

  /* do level order traversal on the tree*/
  while (!que.empty())
  {

    Element front = que.front();
    node *curr = front.data;
    que.pop_front();

    /* if the level of current front element is greater than the maxLevel so far then update maxSum*/
    if (front.level > maxLevel)
    {
      maxSumLevel = front.sum;
      maxLevel = front.level;
    }
    /* if another path competes then update if the sum is greater than the previous path of same height*/
    else if (front.level == maxLevel && front.sum > maxSumLevel)
      maxSumLevel = front.sum;

    /* push the left element if exists*/
    if (curr->left)
    {
      e.data = curr->left;
      e.sum = e.data->data;
      e.sum += front.sum;
      e.level = front.level + 1;
      que.push_back(e);
    }
    /*push the right element if exists*/
    if (curr->right)
    {
      e.data = curr->right;
      e.sum = e.data->data;
      e.sum += front.sum;
      e.level = front.level + 1;
      que.push_back(e);
    }
  }

  /*return the answer*/
  return maxSumLevel;
}

int main()
{
  node *root = tree();
  cout << longestPathSum(root) << endl;
  return 0;
}
