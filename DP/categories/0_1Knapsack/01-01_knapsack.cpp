#include <bits/stdc++.h>
using namespace std;

int recursive(int weight[], int value[], int W, int n)
{
  if (n == 0 || W == 0)
    return 0;
  if (weight[n - 1] <= W)
    return max(value[n - 1] + recursive(weight, value, W - weight[n - 1], n - 1), recursive(weight, value, W, n - 1));
  else
    return recursive(weight, value, W, n - 1);
}

int memoization(int weight[], int value[], int W, int n, vector<vector<int>> &dp)
{
  if (n == 0 || W == 0)
    return 0;
  if (dp[n][W] != -1)
    return dp[n][W];

  if (weight[n - 1] <= W)
    return dp[n][W] = max(value[n - 1] + memoization(weight, value, W - weight[n - 1], n - 1, dp), memoization(weight, value, W, n - 1, dp));
  else
    return dp[n][W] = memoization(weight, value, W, n - 1, dp);
}

int tabulation(int weight[], int value[], int W, int n)
{
  int dp[n + 1][W + 1];
  memset(dp, -1, sizeof(dp));

  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;
  for (int j = 0; j <= W; j++)
    dp[0][j] = 0;
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < W + 1; j++)
    {

      if (weight[i - 1] <= j)
        dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][W];
}

int main()
{
  int value[] = {60, 100, 120};
  int weight[] = {10, 20, 30};

  int n = sizeof(weight) / sizeof(weight[0]);
  int W = 50;
  cout << recursive(weight, value, W, n) << endl;
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
  cout << memoization(weight, value, W, n, dp) << endl;

  cout << tabulation(weight, value, W, n) << endl;
}
