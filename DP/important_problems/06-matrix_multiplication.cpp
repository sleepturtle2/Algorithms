#include <bits/stdc++.h>
using namespace std;

int recursive(int sizes[], int start, int end)
{
  if (start == end)
    return 0;

  int min = INT_MAX;
  int count;

  for (int k = start; k < end; k++)
  {
    count = recursive(sizes, start, k) + recursive(sizes, k + 1, end) + sizes[start - 1] * sizes[k] * sizes[end];

    if (count < min)
      min = count;
  }
  return min;
}

int tabulation(int sizes[], int n)
{
  int dp[n][n];

  /* m[i, j] = Minimum number of scalar
    multiplications needed to compute the
    matrix A[i]A[i+1]...A[j] = A[i..j] where
    dimension of A[i] is p[i-1] x p[i] */

  //0 cost when multiplying 1 matrix
  for (int i = 1; i < n; i++)
    dp[i][i] = 0;

  //L is chain length
  for (int L = 2; L < n; L++)
  {
    for (int i = 1; i < n - L + 1; i++)
    {
      int j = i + L - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k <= j; k++)
      {
        //q = cost/scalar multiplication
        int q = dp[i][k] + dp[k + 1][j] + sizes[i - 1] * sizes[k] * sizes[j];
        if (q < dp[i][j])
          dp[i][j] = q;
      }
    }
  }
  return dp[1][n - 1];
}

int memoization(int sizes[], int start, int end, vector<vector<int>> &dp)
{
  if (start == end)
    return 0;
  if (dp[start][end] != -1)
    return dp[start][end];

  dp[start][end] = INT_MAX;

  for (int k = start; k < end; k++)
  {
    dp[start][end] = min(dp[start][end], memoization(sizes, start, k, dp) + memoization(sizes, k + 1, end, dp) + (sizes[start - 1] * sizes[k] * sizes[end]));
  }
  return dp[start][end];
}

int main()
{
  int sizes[] = {1, 2, 3, 4, 3};
  int n = sizeof(sizes) / sizeof(sizes[0]);

  cout << recursive(sizes, 1, n - 1) << endl;

  cout << tabulation(sizes, n) << endl; //o(n3)

  vector<vector<int>> dp(n, vector<int>(n, -1));
  cout << memoization(sizes, 1, n - 1, dp) << endl; //o(n3)
}
