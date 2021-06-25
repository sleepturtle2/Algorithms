#include <bits/stdc++.h>
using namespace std;

int tabulation(int n, int r)
{
  int dp[n + 1][r + 1];

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= min(i, r); j++)
    {
      if (j == 0)
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i - 1][j] + j * dp[i - 1][j - 1];

      //p(i,j) = 0 for j>i
      dp[i][j + 1] = 0;
    }
  }
  return dp[n][r];
}

int main()
{
  int n = 10, r = 2;
  cout << tabulation(n, r) << endl;
}
