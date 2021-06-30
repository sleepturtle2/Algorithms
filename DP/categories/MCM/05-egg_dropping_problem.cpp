//https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
/*
The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.
Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing. We make a few assumptions:
…..An egg that survives a fall can be used again.
…..A broken egg must be discarded.
…..The effect of a fall is the same for all eggs.
…..If an egg breaks when dropped, then it would break if dropped from a higher floor.
…..If an egg survives a fall then it would survive a shorter fall.
…..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.
If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way. Drop the egg from the first-floor window; if it survives, drop it from the second-floor window. Continue upward until it breaks. In the worst case, this method may require 36 droppings. Suppose 2 eggs are available. What is the least number of egg-droppings that is guaranteed to work in all cases?
The problem is not actually to find the critical floor, but merely to decide floors from which eggs should be dropped so that the total number of trials are minimized.
*/

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

int tabulation(int e, int f)
{

  int dp[e + 1][f + 1]; //dp[i][j] represents min trials needed for i eggs and j floors

  int res;

  //1 trial for 1 floor and 0 trials for 0 floors
  for (int i = 1; i <= e; i++)
  {
    dp[i][1] = 1;
    dp[i][0] = 0;
  }

  //j trials for 1 egg and j floors
  for (int j = 1; j <= f; j++)
    dp[1][j] = j;

  for (int i = 2; i <= e; i++)
  {
    for (int j = 2; j <= f; j++)
    {
      dp[i][j] = INT_MAX;
      for (int k = 1; k <= j; k++)
      {
        res = 1 + max(dp[i - 1][k - 1], dp[i][j - k]);
        if (res < dp[i][j])
          dp[i][j] = res;
      }
    }
  }
  return dp[e][f];
}
int main()
{
  int e = 10;
  int f = 50;
  vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
  cout << eggDrop(e, f, dp) << endl;

  cout << tabulation(e, f) << endl;
}
//o(e*f*f)
//o(e*f) space
