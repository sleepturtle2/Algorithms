//practice link
//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
#include <bits/stdc++.h>
using namespace std;
int arrSum(int arr[], int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  return sum;
}
int minSubsetSumDiff(int arr[], int n)
{
  int sum = arrSum(arr, n);
  vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

  for (int j = 0; j <= sum; j++)
    dp[0][j] = 0;
  for (int i = 0; i <= n; i++)
    dp[i][0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= sum; j++)
    {
      if (arr[i - 1] <= j)
        dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  int mn = INT_MAX;

  for (int j = sum / 2; j >= 0; j--)
  {
    if (dp[n][j])
    {
      mn = sum - 2 * j;
      break;
    }
  }
  return mn;
}

int main()
{
  int arr[] = {1, 2, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << minSubsetSumDiff(arr, n) << endl;
}
