//https://www.geeksforgeeks.org/word-wrap-problem-dp-19/
/*
Given a sequence of words, and a limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly. Assume that the length of each word is smaller than the line width.
Find the cost of least space to be used.
each space cost = (no of spaces)^2
*/

#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX

int printSolution(int line_breaks[], int n)
{
  int k;
  if (line_breaks[n] == 1)
    k = 1;
  else
    k = printSolution(line_breaks, line_breaks[n] - 1) + 1;
  cout << "Line number " << k << ": From word no. " << line_breaks[n] << " to " << n << endl;
  return k;
}

void leastCost(int words[], int n, int line_length)
{
  vector<vector<int>> cost(1 + n, vector<int>(n + 1, -1));
  int final_cost[n + 1];
  int line_breaks[n + 1];

  int i, j;

  for (i = 1; i <= n; i++)
  {
    cost[i][i] = line_length - words[i - 1];
    for (j = i + 1; j <= n; j++)
      cost[i][j] = cost[i][j - 1] - words[j - 1] - 1;
  }

  for (i = 1; i <= n; i++)
  {
    for (j = i; j <= n; j++)
    {
      if (cost[i][j] < 0)
        cost[i][j] = inf;
      else if (j == n && cost[i][j] >= 0)
        cost[i][j] = 0;
      else
        cost[i][j] = cost[i][j] * cost[i][j];
    }
  }

  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 1; j <= n; j++)
  //     cout << cost[i][j] << " ";
  //   cout << endl;
  // }

  final_cost[0] = 0;
  for (j = 1; j <= n; j++)
  {
    final_cost[j] = inf;
    for (i = 1; i <= j; i++)
    {
      if (final_cost[i - 1] != inf && cost[i][j] != inf && (final_cost[i - 1] + cost[i][j] < final_cost[j]))
      {
        final_cost[j] = final_cost[i - 1] + cost[i][j];
        line_breaks[j] = i;
      }
    }
  }

  printSolution(line_breaks, n);
}

int main()
{
  int words[] = {3, 2, 2, 5}; //length of each word
  int line_length = 6;
  int n = sizeof(words) / sizeof(words[0]);
  leastCost(words, n, line_length);
}
