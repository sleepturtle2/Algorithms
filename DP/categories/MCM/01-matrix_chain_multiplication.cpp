#include <bits/stdc++.h>
using namespace std;

int recursive(int arr[], int i, int j)
{
  if (i >= j)
    return 0; //i !=j as size cannot be 1

  int min = INT_MAX;
  for (int k = i; k < j; k++)
  {
    int temp_ans = recursive(arr, i, k) + recursive(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

    if (temp_ans < min)
      min = temp_ans;
  }
  return min;
}
int memoization(int arr[], int i, int j, vector<vector<int>> &dp)
{
  if (i >= j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];

  int min = INT_MAX;

  for (int k = i; k < j; k++)
  {
    int temp_ans = memoization(arr, i, k, dp) + memoization(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
  }
  return dp[i][j] = min;
}
int main()
{
  int arr[] = {10, 20, 30, 40, 10, 20};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << recursive(arr, 1, n - 1) << endl;

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  cout << memoization(arr, 1, n - 1, dp) << endl;
}
