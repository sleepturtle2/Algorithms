#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int n, int sum)
{
  int dp[n + 1][sum + 1];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= sum; j++)
    {
      dp[i][j] = -1;
      if (i == 0)
        dp[i][j] = 0;
      if (j == 0)
        dp[i][j] = 1;
    }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= sum; j++)
    {
      if (arr[i - 1] <= sum)
        dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  return dp[n][sum];
}

bool findPartition(int arr[], int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];

  if (sum & 1)
    return false;
  else
    return subsetSum(arr, n, sum / 2);
}
int main()
{
  int arr[] = {1, 5, 11, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << findPartition(arr, n) << endl;
}
