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

  int mn = INT_MAX;

  for (int k = i; k < j; k++)
  {
    int temp_ans = memoization(arr, i, k, dp) + memoization(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
    mn = min(mn, temp_ans);
  }
  return dp[i][j] = mn;
}

int tabulation(int arr[], int n)
{
  int dp[n][n];
  /* m[i, j] = Minimum number of scalar
    multiplications needed to compute the
    matrix A[i]A[i+1]...A[j] = A[i..j] where
    dimension of A[i] is p[i-1] x p[i] */

  // cost is zero when multiplying
  // one matrix.
  for (int i = 1; i < n; i++)
    dp[i][i] = 0;

  //L is chain length
  for (int L = 2; L < n; L++)
  { //select the starting point
    for (int i = 1; i < n - L + 1; i++)
    {
      //select the ending point
      int j = i + L - 1;
      dp[i][j] = INT_MAX;
      //selects the partition between i and j
      for (int k = i; k <= j - 1; k++)
      {
        // mn = cost/scalar multiplications
        int mn = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
        if (mn < dp[i][j])
          dp[i][j] = mn;
      }
    }
  }

  return dp[1][n - 1];
}
int main()
{
  int arr[] = {10, 20, 30, 40, 10, 20};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << recursive(arr, 1, n - 1) << endl;

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  cout << memoization(arr, 1, n - 1, dp) << endl;

  cout << tabulation(arr, n) << endl;
}
//o(n3)
