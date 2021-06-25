#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
  return min(min(x, y), z);
}

int recursive(string s1, string s2, int m, int n)
{
  // If first string is empty, the only option is to
  // insert all characters of second string into first
  if (m == 0)
    return n;

  // If second string is empty, the only option is to
  // remove all characters of first string
  if (n == 0)
    return m;

  // If last characters of two strings are same, nothing
  // much to do. Ignore last characters and get count for
  // remaining strings.
  if (s1[m - 1] == s2[n - 1])
    return recursive(s1, s2, m - 1, n - 1);

  // If last characters are not same, consider all three
  // operations on last character of first string,
  // recursively compute minimum cost for all three
  // operations and take minimum of three values.
  return 1 + min(recursive(s1, s2, m, n - 1), // Insert
                 recursive(s1, s2, m - 1, n), // Remove
                 recursive(s1, s2, m - 1,
                           n - 1) // Replace
             );
}

int tabulation(string s1, string s2, int m, int n)
{
  int dp[m + 1][n + 1];

  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      // If first string is empty, only option is to
      // insert all characters of second string
      if (i == 0)
        dp[i][j] = j; // Min. operations = j

      // If second string is empty, only option is to
      // remove all characters of second string
      else if (j == 0)
        dp[i][j] = i;
      // Min. operations = i
      // If last characters are same, ignore last char
      // and recur for remaining string
      else if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1];

      // If the last character is different, consider
      // all possibilities and find the minimum
      else
        dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
    }
  }
  return dp[m][n];
}

int tabulation_optimized(string s1, string s2)
{
  int len1 = s1.length();
  int len2 = s2.length();

  vector<vector<int>> dp(2, vector<int>(len1 + 1));

  //base condition when second string is empty and we remove all characters
  for (int i = 0; i <= len1; i++)
    dp[0][i] = i;

  // Start filling the DP
  // This loop run for every
  // character in second string
  for (int i = 1; i <= len2; i++)
  {
    // This loop compares the char from
    // second string with first string
    // characters
    for (int j = 0; j <= len1; j++)
    {
      // if first string is empty then
      // we have to perform add character
      // operation to get second string
      if (j == 0)
        dp[i % 2][j] = i;

      // if character from both string
      // is same then we do not perform any
      // operation . here i % 2 is for bound
      // the row number.
      else if (s1[j - 1] == s2[i - 1])
      {
        dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
      }

      // if character from both string is
      // not same then we take the minimum
      // from three specified operation
      else
      {
        dp[i % 2][j] = 1 + min(dp[(i - 1) % 2][j],
                               min(dp[i % 2][j - 1],
                                   dp[(i - 1) % 2][j - 1]));
      }
    }
  }

  // after complete fill the DP array
  // if the len2 is even then we end
  // up in the 0th row else we end up
  // in the 1th row so we take len2 % 2
  // to get row
  return dp[len2 % 2][len1];
}

int memoization(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
  // If any string is empty,
  // return the remaining characters of other string

  if (n == 0)
    return m;
  if (m == 0)
    return n;

  if (dp[n][m] != -1)
    return dp[n][m];

  if (s1[n - 1] == s2[m - 1])
  {
    if (dp[n - 1][m - 1] == -1)
    {
      return dp[n][m] = memoization(s1, s2, n - 1, m - 1, dp);
    }
    else
      return dp[n][m] = dp[n - 1][m - 1];
  }
  // If characters are nt equal, we need to

  // find the minimum cost out of all 3 operations.
  else
  {

    int m1, m2, m3; //temp variables

    if (dp[n - 1][m] != -1)
    {
      m1 = dp[n - 1][m];
    }
    else
    {
      m1 = memoization(s1, s2, n - 1, m, dp);
    }

    if (dp[n][m - 1] != -1)
    {
      m2 = dp[n][m - 1];
    }
    else
    {
      m2 = memoization(s1, s2, n, m - 1, dp);
    }

    if (dp[n - 1][m - 1] != -1)
    {
      m3 = dp[n - 1][m - 1];
    }
    else
    {
      m3 = memoization(s1, s2, n - 1, m - 1, dp);
    }

    return dp[n][m] = 1 + min(m1, min(m2, m3));
  }
}
int main()
{
  string s1 = "sunday";
  string s2 = "saturday";

  cout << recursive(s1, s2, s1.length(), s2.length()) << endl; //o(3^m)

  //o(mn), o(mn)
  cout << tabulation(s1, s2, s1.length(), s2.length()) << endl;

  //o(mn), o(m)
  cout << tabulation_optimized(s1, s2) << endl;

  vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
  cout << memoization(s1, s2, s1.length(), s2.length(), dp) << endl;
}
