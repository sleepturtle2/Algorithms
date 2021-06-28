#include <bits/stdc++.h>
using namespace std;

int memoization(int coins[], int n, int sum, vector<vector<int>> &dp)
{
  if (sum == 0)
    return 0;
  if (dp[n][sum] != -1)
    return dp[n][sum];

  int res = INT_MAX;

  for (int i = 0; i < n; i++)
  {
    if (coins[i] <= sum)
    {
      int sub_res = 1 + memoization(coins, n, sum - coins[i], dp);
      if (sub_res < res)
        res = sub_res;
    }
  }
  return dp[n][sum] = res;
}

int tabulation(int coins[], int n, int sum)
{

  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX));
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;
  int mn = INT_MAX;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= sum; j++)
    {
      if (coins[i - 1] <= j)
        dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  // for (int i = 0; i <= n; i++)
  // {
  //   for (int j = 0; j <= sum; j++)
  //   {
  //     if (dp[i][j] == INT_MAX)
  //       cout << "- ";
  //     else
  //       cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  for (int i = 1; i <= n; i++)
    mn = dp[i][sum] != -1 ? min(mn, dp[i][sum]) : mn;
  return mn;
}

int main()
{
  int coins[] = {1, 2, 3};
  int n = sizeof(coins) / sizeof(coins[0]);
  int sum = 4;
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

  cout << memoization(coins, n, sum, dp) << endl;
  cout << tabulation(coins, n, sum) << endl;
}
