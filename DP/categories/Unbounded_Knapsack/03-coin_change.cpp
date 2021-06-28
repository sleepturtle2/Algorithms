#include <bits/stdc++.h>
using namespace std;

int tabulation(int coins[], int n, int sum)
{
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= sum; j++)
    {
      if (j == 0)
      {
        dp[i][j] = 1;
        continue;
      }
      if (coins[i - 1] <= j)
        dp[i][j] = (dp[i][j - coins[i - 1]] + dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  return dp[n][sum];
}

int memoization(int coins[], int n, int sum, vector<vector<int>> &dp)
{
  if (sum == 0)
    return 1;

  if (n == 0 || sum < 0)
    return 0;

  if (coins[n - 1] <= sum)
    return memoization(coins, n, sum - coins[n - 1], dp) + memoization(coins, n - 1, sum, dp);
  else
    return memoization(coins, n - 1, sum, dp);
}

int main()
{
  int coins[] = {1, 2, 3};
  int n = sizeof(coins) / sizeof(coins[0]);
  int sum = 5;
  cout << tabulation(coins, n, sum) << endl;
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
  cout << memoization(coins, n, sum, dp) << endl;
}
