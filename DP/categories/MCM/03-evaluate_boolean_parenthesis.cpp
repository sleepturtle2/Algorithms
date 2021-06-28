#include <bits/stdc++.h>
using namespace std;
//boolean exp with T, F, &, |, ^
//number of ways of putting brackets such that expression evaluates to true

int numOfParenthesis(string s, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp)
{
  if (i > j)
    return false;

  if (i == j)
  {
    if (isTrue)
      return s[i] == 'T';
    else
      return s[i] == 'F';
  }

  if (dp[i][j][isTrue] != -1)
    return dp[i][j][isTrue];

  int ans = 0;
  for (int k = i + 1; k <= j; k += 2)
  {
    int leftF, leftT, rightT, rightF;

    if (dp[i][k - 1][1] == -1)
    {
      leftT = numOfParenthesis(s, i, k - 1, 1, dp);
    }
    else
    {
      leftT = dp[i][k - 1][1];
    }

    if (dp[k + 1][j][1] == -1)
    {
      rightT = numOfParenthesis(s, k + 1, j, 1, dp);
    }
    else
    {
      rightT = dp[k + 1][j][1];
    }
    if (dp[i][k - 1][0] == -1)
    {
      leftF = numOfParenthesis(s, i, k - 1, 0, dp);
    }
    else
    {
      leftF = dp[i][k - 1][0];
    }
    if (dp[k + 1][j][0] == -1)
    {
      rightF = numOfParenthesis(s, k + 1, j, 0, dp);
    }
    else
    {
      rightF = dp[k + 1][j][0];
    }
    if (s[k] == '&')
    {
      if (isTrue)
        ans += leftT * rightT;
      else
        ans += leftF * rightF + leftT * rightF + leftF * rightT;
    }
    else if (s[k] == '|')
    {
      if (isTrue)
        ans += leftT * rightT + leftT * rightF + leftF * rightT;
      else
        ans += leftF * rightF;
    }
    else if (s[k] == '^')
    {
      if (isTrue)
        ans += leftF * rightT + leftT * rightF;
      else
        ans += leftT * rightT + leftF * rightF;
    }

    dp[i][j][isTrue] = ans;
  }
  return ans;
}
int main()
{
  string exp = "T|T&F^T";
  vector<vector<vector<int>>> dp(exp.length() + 1, vector<vector<int>>(exp.length() + 1, vector<int>(2, -1)));
  cout << numOfParenthesis(exp, 0, exp.length() - 1, true, dp) << endl;
}
