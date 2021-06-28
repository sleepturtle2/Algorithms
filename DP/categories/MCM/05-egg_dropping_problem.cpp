#include <bits/stdc++.h>
using namespace std;

int eggDrop(int e, int f, vector<vector<int>> &dp)
{
  if (f == 0 || f == 1)
    return f;
  if (e == 1)
    return f;
  if (dp[e][f] != -1)
    return dp[e][f];

  int mn = INT_MAX;
  for (int k = 1; k <= f; k++)
  {
    int low, high;
    if (dp[e - 1][k - 1] != -1)
      low = dp[e - 1][k - 1];
    else
      low = eggDrop(e - 1, k - 1, dp);
    if (dp[e][f - k] != -1)
      high = dp[e][f - k];
    else
      high = eggDrop(e, f - k, dp);

    int temp = 1 + max(low, high);
    mn = min(mn, temp);
  }
  return dp[e][f] = mn;
}

int main()
{
  int e = 10;
  int f = 50;
  vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
  cout << eggDrop(e, f, dp) << endl;
}
