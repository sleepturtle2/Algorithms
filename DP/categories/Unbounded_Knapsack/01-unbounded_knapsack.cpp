#include <bits/stdc++.h>
using namespace std;

int tabulation(int value[], int weight[], int n, int W)
{
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      if (weight[i - 1] <= j)
        dp[i][j] = max(value[i - 1] + dp[i][j - weight[i - 1]], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][W];
}

int memoization(int value[], int weight[], int n, int W, vector<vector<int>> &dp)
{
  if (n == 0 || W <= 0)
    return 0;
  if (dp[n][W] != -1)
    return dp[n][W];

  if (weight[n - 1] <= W)
    return dp[n][W] = max(value[n - 1] + memoization(value, weight, n, W - weight[n - 1], dp), memoization(value, weight, n - 1, W, dp));
  else
    return dp[n][W] = memoization(value, weight, n - 1, W, dp);
}

int main()
{
  int W = 100;
  int value[] = {10, 30, 20};
  int weight[] = {5, 10, 15};
  int n = sizeof(weight) / sizeof(weight[0]);
  cout << tabulation(value, weight, n, W) << endl;

  vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
  cout << memoization(value, weight, n, W, dp) << endl;
}
