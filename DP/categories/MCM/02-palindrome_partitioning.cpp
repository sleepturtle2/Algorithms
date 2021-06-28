#include <bits/stdc++.h>
using namespace std;
//find min number of partitions in a string to make each string a palindrome
//eg nitin. ans = 2 -> n, iti, n

bool isPalindrome(string s, int start, int end)
{
  while (start <= end)
  {
    if (s[start++] != s[end--])
      return false;
  }
  return true;
}

int minimumPartitions(string s, int i, int j, vector<vector<int>> &dp)
{

  if (i >= j) //0 partitions for string size 1 (i=j), 0 or other invalid options
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  if (isPalindrome(s, i, j))
    return 0;
  int ans = INT_MAX;
  for (int k = i; k < j; k++)
  {
    int left, right;
    if (dp[i][k] != -1)
      left = dp[i][k];
    else
    {
      left = minimumPartitions(s, i, k, dp);
      dp[i][k] = left;
    }

    if (dp[k + 1][j] != -1)
      right = dp[k + 1][j];
    else
    {
      right = minimumPartitions(s, k + 1, j, dp);
      dp[k + 1][j] = right;
    }

    int temp = right + left + 1;
    ans = min(ans, temp);
  }
  return dp[i][j] = ans;
}

int main()
{
  string s = "nitiny";
  int l = s.length();
  vector<vector<int>> dp(l + 1, vector<int>(l + 1, -1));
  cout << minimumPartitions(s, 0, s.length() - 1, dp) << endl;
}
