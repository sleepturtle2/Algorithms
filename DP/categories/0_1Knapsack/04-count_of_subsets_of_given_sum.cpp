#include <bits/stdc++.h>
using namespace std;

int countOfSum(int arr[], int n, int sum)
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
      if (arr[i - 1] <= sum)
        dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][sum];
}

int main()
{
  int arr[] = {2, 3, 5, 6, 8, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << countOfSum(arr, n, 10) << endl;
}
