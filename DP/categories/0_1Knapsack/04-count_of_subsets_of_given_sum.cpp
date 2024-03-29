//practice link
//https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

int countOfSum(int arr[], int n, int sum)
{
  int mod = 1000000007;

  vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= sum; j++)
    {
      if (i == 0 && j != 0)
        dp[i][j] = 0;
      else if (j == 0)
        dp[i][j] = 1;
      else
      {
        if (arr[i - 1] <= j)
          dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
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
