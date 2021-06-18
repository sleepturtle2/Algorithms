#include <bits/stdc++.h>
#include "../graph headers/unweighted_undirected.h"
using namespace std;

void bridgeUtil(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent)
{
  static int time = 0;
  visited[u] = true;

  disc[u] = low[u] = ++time;

  for (int v : adj[u])
  {

    if (!visited[v])
    {
      parent[v] = u;
      bridgeUtil(adj, v, visited, disc, low, parent);

      //check if subtree rooted with v has a connection to one of the ancestors
      low[u] = min(low[u], low[v]);

      //if the lowest vertex reachable from subtree under v is below u in dfs tree, then u-v is a bridge
      if (low[v] > disc[u])
        cout << u << " " << v << endl;
    }

    //update low value of u for parent function calls
    else if (v != parent[u])
      low[u] = min(low[u], disc[v]);
  }
}

void bridge(vector<vector<int>> &adj, int V)
{
  vector<bool> visited(V);
  vector<int> disc(V);
  vector<int> low(V);
  vector<int> parent(V, -1);

  //dfs to find bridges in dfs tree rooted in i
  for (int i = 0; i < V; i++)
    if (visited[i] == false)
      bridgeUtil(adj, i, visited, disc, low, parent);
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj7;
  int V = adj.size();
  bridge(adj, V);
}
