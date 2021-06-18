#include <bits/stdc++.h>
using namespace std;
//finding the path of least weight from src to dest with at most k+1 edges

void dfs_with_pruning(vector<vector<pair<int, int>>> &adj, int src, int dst, int K, int &fare, int totalCost, vector<bool> &visited)
{

  if (K < -1)
    return;
  if (src == dst)
  {
    fare = min(fare, totalCost);
    return;
  }

  visited[src] = true;

  for (int i = 0; i < adj[src].size(); i++)
  {
    if (!visited[adj[src][i].first] && (totalCost + adj[src][i].second <= fare))
      dfs_with_pruning(adj, adj[src][i].first, dst, K - 1, fare, totalCost + adj[src][i].second, visited);
  }

  visited[src] = false;
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
  vector<vector<pair<int, int>>> adj(n);

  for (int i = 0; i < flights.size(); i++)
  {
    adj[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
  }

  vector<bool> visited(n + 1); //to break cycles
  int fare = INT_MAX;
  dfs_with_pruning(adj, src, dst, K, fare, 0, visited);

  if (fare == INT_MAX)
    return -1;
  return fare;
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
