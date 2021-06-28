#include <bits/stdc++.h>
using namespace std;
bool memoization(int arr[], int n, int sum, vector<vector<int>> &dp)
{
  if (sum == 0)
    return true;
  if (n == 0 || sum < 0)
    return false;
  if (dp[n][sum] != -1)
    return dp[n][sum];

  if (arr[n - 1] <= sum)
    return dp[n][sum] = memoization(arr, n - 1, sum - arr[n - 1], dp) || memoization(arr, n - 1, sum, dp);
  else
    return dp[n][sum] = memoization(arr, n - 1, sum, dp);
}

int tabulation(int arr[], int n, int sum)
{
  vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, -1));

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= sum; j++)
    {
      if (i == 0)
      {
        dp[i][j] = 0;
        continue;
      }
      if (j == 0)
      {
        dp[i][j] = 1;
        continue;
      }

      if (arr[i] <= sum)
        dp[i][j] = (arr[i] + dp[i - 1][j - arr[i - 1]]) || dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j];
    }

    return dp[n][sum];
  }

  return 1;
}

int main()
{
  int arr[] = {2, 3, 7, 8, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  int sum = 11;
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
  cout << memoization(arr, n, sum, dp) << endl;
  cout << tabulation(arr, n, sum) << endl;
}
