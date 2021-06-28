#include <bits/stdc++.h>
using namespace std;

int tabulation(int price[], int length[], int N)
{
  vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

  for (int i = 1; i <= N; i++)
  {
    for (int j = 0; j <= N; j++)
    {
      if (length[i - 1] <= j)
        dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[N][N];
}

int memoization(int price[], int length[], int i, int j, vector<vector<int>> &dp)
{
  if (i == 0 || j <= 0)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (length[i - 1] <= j)
    return dp[i][j] = max(price[i - 1] + memoization(price, length, i, j - length[i - 1], dp), memoization(price, length, i - 1, j, dp));
  else
    return dp[i][j] = memoization(price, length, i - 1, j, dp);
}

int main()
{
  int N = 8;
  int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int length[] = {1, 2, 3, 4, 5, 6, 7, 8};

  cout << tabulation(price, length, N) << endl;

  vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
  cout << memoization(price, length, N, N, dp) << endl;
}
