#include <bits/stdc++.h>
using namespace std;

//optimal substructure
//c(n,r) = c(n-1, r-1) + c(n-1, r)

int recursive(int n, int r)
{
  if (r > n)
    return 0;
  if (r == 0 || n == 0)
    return 1;
  return recursive(n - 1, r - 1) + recursive(n - 1, r);
}

int tabulation(int n, int r)
{
  vector<vector<int>> dp(n + 1, vector<int>(r + 1));

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= min(i, r); j++)
    {
      if (j == 0 || j == i)
        dp[i][j] = 1;

      else
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
  }
  return dp[n][r];
}

int memoization(int n, int r, vector<vector<int>> &dp)
{
  if (dp[n][r] != -1)
    return dp[n][r];
  if (r == 0)
    return dp[n][r] = 1;
  if (n == r)
    return dp[n][r] = 1;
  return dp[n][r] = memoization(n - 1, r - 1, dp) + memoization(n - 1, r, dp);
}
int main()
{
  int n = 5, r = 2;
  cout << recursive(n, r) << endl;
  cout << tabulation(n, r) << endl;
  vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
  cout << memoization(n, r, dp) << endl;
}
