#include <bits/stdc++.h>
#include "../graph headers/unweighted_undirected.h"
using namespace std;

bool dfs_helper(vector<vector<int>> &adj, int v, vector<bool> &visited, int parent)
{
  visited[v] = true;

  //recur for all adjacent vertices
  for (int i : adj[v])
  {
    if (!visited[i])
    {
      if (dfs_helper(adj, i, visited, v))
        return true;
    }

    //if adjacent vertex is visited and is not parent of current vertex, then there exists a cycle
    else if (i != parent)
      return true;
  }
  return false;
}

bool isCyclic(vector<vector<int>> &adj, int V)
{
  vector<bool> visited(V);

  //detect cycle in different dfs trees
  for (int u = 0; u < V; u++)
  {
    if (!visited[u])
      if (dfs_helper(adj, u, visited, -1))
        return true;
  }
  return false;
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj6;
  int V = adj.size();
  isCyclic(adj, V) ? cout << "Graph contains cycle\n" : cout << "Graph does not contain cycle\n";
  return 0;
}
