#include <bits/stdc++.h>
using namespace std;

int countSubsetsUtil(int arr[], int n, int sum)
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
  return dp[n][sum];
}

int countOfSubsets(int arr[], int n, int diff)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];

  int sum1 = (sum + diff) / 2;
  int sum2 = (sum - diff) / 2;

  int ans1 = countSubsetsUtil(arr, n, sum1);
  int ans2 = countSubsetsUtil(arr, n, sum2);

  //both ans1 and ans2 will be same
  //find out any one and output it
  return ans1;
}

int main()
{
  int arr[] = {1, 2, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int diff = 1;
  cout << countOfSubsets(arr, n, diff) << endl;
}
