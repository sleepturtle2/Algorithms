#include <bits/stdc++.h>
using namespace std;

string X = "AGGT12";
string Y = "12TXAYB";
string Z = "12XBA";

int dp[100][100][100];

/* Returns length of LCS for X[0..m-1], Y[0..n-1]
and Z[0..o-1] */
int memo(int i, int j, int k)
{
  if (i == -1 || j == -1 || k == -1)
    return 0;
  if (dp[i][j][k] != -1)
    return dp[i][j][k];

  if (X[i] == Y[j] && Y[j] == Z[k])
    return dp[i][j][k] = 1 + memo(i - 1, j - 1, k - 1);
  else
    return dp[i][j][k] = max(max(memo(i - 1, j, k),
                                 memo(i, j - 1, k)),
                             memo(i, j, k - 1));
}

int tab(string X, string Y, string Z, int m,
        int n, int o)
{
  int L[m + 1][n + 1][o + 1];

  /* Following steps build L[m+1][n+1][o+1] in
       bottom up fashion. Note that L[i][j][k]
       contains length of LCS of X[0..i-1] and
       Y[0..j-1]  and Z[0.....k-1]*/
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      for (int k = 0; k <= o; k++)
      {
        if (i == 0 || j == 0 || k == 0)
          L[i][j][k] = 0;

        else if (X[i - 1] == Y[j - 1] && X[i - 1] == Z[k - 1])
          L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;

        else
          L[i][j][k] = max(max(L[i - 1][j][k],
                               L[i][j - 1][k]),
                           L[i][j][k - 1]);
      }
    }
  }

  /* L[m][n][o] contains length of LCS for
      X[0..n-1] and Y[0..m-1] and Z[0..o-1]*/
  return L[m][n][o];
}
// Driver code
int main()
{
  memset(dp, -1, sizeof(dp));
  int m = X.length();
  int n = Y.length();
  int o = Z.length();

  cout << "Length of LCS is " << memo(m - 1, n - 1, o - 1) << endl;
  cout << "Length of LCS is " << tab(X, Y, Z, m, n, o) << endl;
}
