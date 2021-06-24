#include <bits/stdc++.h>
using namespace std;

int recursive(vector<int> &coins, int amount, int n)
{
  if (amount == 0)
    return 1;

  if (amount < 1)
    return 0;

  if (amount > 0 && n <= 0)
    return 0;

  return recursive(coins, amount, n - 1) + recursive(coins, amount - coins[n - 1], n);
}

//o(mn), space o(mn)
int tabulation(vector<int> &coins, int amount, int n)
{
  vector<vector<int>> table(amount + 1, vector<int>(n));

  for (int i = 0; i < n; i++)
    table[0][i] = 1;

  //bottom up
  for (int i = 1; i < amount + 1; i++)
  {
    for (int j = 0; j < n; j++)
    {

      //include coins[j]
      int include = (i >= coins[j]) ? table[i - coins[j]][j] : 0;
      int exclude = j >= 1 ? table[i][j - 1] : 0;
      table[i][j] = include + exclude;
    }
  }

  return table[amount][n - 1];
}

int memoization(vector<int> &coins, int amount, int n, vector<int> &dp)
{
  if (amount == 0)
    return dp[amount] = 1;
  if (dp[amount] != -1)
    return dp[amount];

  //recursion
  int ans = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    if (amount >= coins[i])
    {
      int ans2 = memoization(coins, amount - coins[i], n, dp);
      if (ans2 != INT_MAX)
        ans = min(ans, ans2 + 1);
    }
  }
  return dp[amount] = ans;
}

int main()
{
  vector<int> coins = {1, 2, 3};
  int amount = 4;
  int n = coins.size();
  cout << recursive(coins, amount, n) << endl;

  cout << tabulation(coins, amount, n) << endl;

  vector<int> table(amount + 1); //not 2d because it depends on only 1 parameter
  cout << memoization(coins, amount, n, table) << endl;
}

/*

space optimized


int count( int S[], int m, int n )
{
 // table[i] will be storing the number of solutions for
 // value i. We need n+1 rows as the table is constructed
 // in bottom up manner using the base case (n = 0)
 int table[n+1];
 // Initialize all table values as 0
 memset(table, 0, sizeof(table));
 // Base case (If given value is 0)
 table[0] = 1;
 // Pick all coins one by one and update the table[] values
 // after the index greater than or equal to the value of the
 // picked coin
 for(int i=0; i<m; i++)
 for(int j=S[i]; j<=n; j++)
 table[j] += table[j-S[i]];
 return table[n];
}
*/
