#include <bits/stdc++.h>
using namespace std;

int countSubsetUtil(int arr[], int n, int sum)
{
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

  for (int j = 0; j <= sum; j++)
    dp[0][j] = 0;
  for (int i = 0; i <= n; i++)
    dp[i][0] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= sum; j++)
    {
      if (arr[i - 1] <= j)
        dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  for (auto i : dp)
  {
    for (auto j : i)
      cout << j << " ";
    cout << endl;
  }
  return dp[n][sum];
}

int countTargetSumCount(int arr[], int n, int target)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];

  int sum1 = (sum + target) / 2; //could also be (sum-target)/2
  return countSubsetUtil(arr, n, sum1);
}

int main()
{
  int arr[] = {1, 1, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 1;
  cout << countTargetSumCount(arr, n, target) << endl;
}
