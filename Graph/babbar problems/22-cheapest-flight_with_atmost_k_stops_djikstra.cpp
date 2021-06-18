#include <bits/stdc++.h>
using namespace std;
//finding the path of least weight from src to dest with at most k+1 edges

//k-step djikstra algorithm

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
  vector<vector<tuple<int, int>>> adj(n + 3);
  for (auto f : flights)
    adj[f[0]].push_back({f[1], f[2]}); //src : (dst, dis)

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
  //we need to record the shortest distance to each node using k' (0<=k'<=k+1) steps
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  pq.emplace(0, 0, src); //distance, step count, node

  while (!pq.empty())
  {
    int dis = get<0>(pq.top());
    int step = get<1>(pq.top());
    int node = get<2>(pq.top());
    pq.pop();

    if (node == dst)
      return dis;

    //skip if step >= k+1
    if (step >= k + 1)
      continue;
    if (dp[node][step] != -1)
      continue;

    dp[node][step] = dis;

    for (auto next : adj[node])
    {
      int next_node = get<0>(next);
      int d = get<1>(next);
      pq.emplace(dis + d, step + 1, next_node);
    }
  }
  return -1;
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
