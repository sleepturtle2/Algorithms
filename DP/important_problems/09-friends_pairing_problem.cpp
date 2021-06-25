#include <bits/stdc++.h>
using namespace std;

int recursive(int n)
{
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  return recursive(n - 1) + (n - 1) * recursive(n - 2);
}

int tabulation(int n)
{
  int dp[n + 1];

  for (int i = 0; i <= n; i++)
  {
    if (i <= 2)
      dp[i] = i;
    else
      dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
  }
  return dp[n];
}

int memoization(int n, vector<int> &dp)
{
  if (dp[n] != -1)
    return dp[n];
  if (n > 2)
    return dp[n] = memoization(n - 1, dp) + (n - 1) * memoization(n - 2, dp);
  else
    return dp[n] = n;
}

int main()
{
  int n = 4;

  cout << recursive(n) << endl;
  cout << tabulation(n) << endl;
  vector<int> dp(n + 1, -1);
  cout << memoization(n, dp) << endl;
}
