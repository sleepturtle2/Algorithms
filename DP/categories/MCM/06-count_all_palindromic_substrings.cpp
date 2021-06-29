#include <bits/stdc++.h>
using namespace std;

int countPS(string s, int n)
{
  vector<vector<int>> dp(n, vector<int>(n));
  vector<vector<bool>> palindrome(n, vector<bool>(n));

  //single length
  for (int i = 0; i < n; i++)
    palindrome[i][i] = true;

  //palindrome of length 2
  for (int i = 0; i < n - 1; i++)
  {
    if (s[i] == s[i + 1])
    {
      palindrome[i][i + 1] = true;
      dp[i][i + 1] = 1;
    }
  }

  // Palindromes of length more than 1. This loop is
  // similar to Matrix Chain Multiplication. We start with
  // a gap of length 1 and fill the DP table in a way that
  // gap between starting and ending indexes increases one
  // by one by outer loop.
  for (int gap = 2; gap < n; gap++)
  {
    //pick starting point
    for (int i = 0; i < n - gap; i++)
    {

      //set ending point
      int j = gap + i;

      //if(current string is palindrome)
      if (s[i] == s[j] && palindrome[i + 1][j - 1])
        palindrome[i][j] = true;

      //add palindrome substring (+1)
      //and rest of the palindrome substring (dp[i][j-1] + dp[i+1][j])
      //remove common palindrome (-dp[i+1][j-1])
      dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]; //this is common to both palindrome and non palindrome

      if (palindrome[i][j])
        dp[i][j] += 1; //add one for palindrome i,j
    }
  }
  return dp[0][n - 1] + n;
}

int main()
{
  string s = "abaab";
  int n = s.size();
  cout << countPS(s, n) << endl;
}
