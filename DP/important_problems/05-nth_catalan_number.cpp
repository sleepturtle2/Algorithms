#include <bits/stdc++.h>
using namespace std;

unsigned long int recursive(unsigned int n)
{
  if (n <= 1)
    return 1;

  unsigned long int res = 0;
  for (int i = 0; i < n; i++)
    res += recursive(i) * recursive(n - i - 1);

  return res;
}

unsigned long int tabulation(unsigned int n)
{
  unsigned long int dp[n + 1];

  dp[0] = dp[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    dp[i] = 0;

    for (int j = 0; j < i; j++)
      dp[i] += dp[j] * dp[i - j - 1];
  }
  return dp[n];
}

int main()
{
  for (int i = 0; i < 10; i++)
    cout << recursive(i) << " ";
  cout << endl;

  for (int i = 0; i < 10; i++)
    cout << tabulation(i) << " ";
  cout << endl;
}
