#include <bits/stdc++.h>
using namespace std;
//finding the path of least weight from src to dest with at most k+1 edges

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
  // different with standard bellman ford.
  // To limit the step within k+1 steps, we need to record the states for each steps seperately.
  vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
  dp[0][src] = 0;
  for (int i = 1; i <= k + 1; i++)
  {
    // at each step, the distance to src is 0
    // if src is not set to 0, the previous state will be lost.
    dp[i][src] = 0;
    for (auto f : flights)
    {
      int cur = f[0], next = f[1], cost = f[2];
      dp[i][next] = min(dp[i][next], dp[i - 1][cur] + cost);
    }
  }
  return dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst];
}

int main()
{
  int n = 5; //number of stops
  vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  int src = 0;
  int dst = 2;
  int K = 1;
  cout << findCheapestPrice(n, flights, src, dst, K) << endl;
  return 0;
}
