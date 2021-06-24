#include <bits/stdc++.h>
using namespace std;

//o(2^n)
int recursive(int weight, vector<int> &weights, vector<int> &values, int n)
{

  if (n == 0 || weight == 0)
    return 0;

  if (weights[n - 1] > weight)
    return recursive(weight, weights, values, n - 1);

  else
    return max(values[n - 1] + recursive(weight - weights[n - 1], weights, values, n - 1), recursive(weight, weights, values, n - 1));
}

//o(mn)
int tabulation(int weight, vector<int> &weights, vector<int> &values, int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(weight + 1));

  for (int i = 0; i < n + 1; i++)
  {
    for (int w = 0; w <= weight; w++)
    {
      if (i == 0 || w == 0)
        dp[i][w] = 0;
      else if (weights[i - 1] <= w)
        dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);

      else
        dp[i][w] = dp[i - 1][w];
    }
  }
  return dp[n][weight];
}

//o(nm)
int memoization(int weight, vector<int> &weights, vector<int> &values, int n, vector<vector<int>> &dp)
{

  if (n < 0)
    return 0;
  if (dp[n][weight] != -1)
    return dp[n][weight];
  if (weights[n] > weight)
  {
    dp[n][weight] = memoization(weight, weights, values, n - 1, dp);
    return dp[n][weight];
  }
  else
  {
    dp[n][weight] = max(values[n] + memoization(weight - weights[n], weights, values, n - 1, dp), memoization(weight, weights, values, n - 1, dp));

    return dp[n][weight];
  }
}
int main()
{
  vector<int> values = {60, 100, 120};
  vector<int> weights = {10, 20, 30};
  int weight = 50;
  int n = 3;

  cout << recursive(weight, weights, values, n) << endl;
  cout << tabulation(weight, weights, values, n) << endl;
  vector<vector<int>> dp(n, vector<int>(weight + 1, -1));
  cout << memoization(weight, weights, values, n - 1, dp) << endl;
}
