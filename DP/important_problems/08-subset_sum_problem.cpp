#include <bits/stdc++.h>
using namespace std;

bool recursion(int set[], int n, int sum)
{
  if (sum == 0)
    return true;

  if (n == 0)
    return false;

  if (set[n - 1] > sum)
    return recursion(set, n - 1, sum);

  return recursion(set, n - 1, sum) || recursion(set, n - 1, sum - set[n - 1]);
}

bool tabulation(int set[], int n, int sum)
{
  // The value of dp[i][j] will be true if
  // there is a subset of set[0..j-1] with sum
  // equal to i
  bool dp[n + 1][sum + 1];

  for (int i = 0; i <= n; i++)
    dp[i][0] = true;

  for (int i = 1; i <= sum; i++)
    dp[0][i] = false;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= sum; j++)
    {
      if (j < set[i - 1])
        dp[i][j] = dp[i - 1][j];
      if (j >= set[i - 1])
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
    }
  }
  return dp[n][sum];
}

int memoization(int set[], int n, int sum, vector<vector<int>> &dp)
{
  if (sum == 0)
    return 1;
  if (n <= 0)
    return 0;

  if (dp[n - 1][sum] != -1)
    return dp[n - 1][sum];

  if (set[n - 1] > sum)
    return dp[n - 1][sum] = memoization(set, n - 1, sum, dp);
  else
  {
    return dp[n - 1][sum] = memoization(set, n - 1, sum, dp) || memoization(set, n - 1, sum - set[n - 1], dp);
  }
}

int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set) / sizeof(set[0]);

  recursion(set, n, sum) ? cout << "true\n" : cout << "false\n"; //exponential, np complete

  tabulation(set, n, sum) ? cout << "true\n" : cout << "false\n";

  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
  memoization(set, n, sum, dp) ? cout << "true\n" : cout << "false\n";
}
