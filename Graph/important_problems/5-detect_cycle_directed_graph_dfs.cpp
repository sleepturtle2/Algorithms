#include <bits/stdc++.h>
#include "../graph headers/unweighted_directed.h"
using namespace std;

bool dfs_helper(vector<vector<int>> &adj, int v, vector<bool> &visited, vector<bool> &recStack)
{
  if (!visited[v])
  {
    visited[v] = true;
    recStack[v] = true;

    //recur for adjacent vertices
    for (int i : adj[v])
    {
      if (!visited[i] && dfs_helper(adj, i, visited, recStack))
        return true;
      else if (recStack[i])
        return true;
    }
  }
  recStack[v] = false;
  return false;
}

bool isCyclic(vector<vector<int>> &adj, int V)
{
  vector<bool> visited(V);
  vector<bool> recStack(V);

  //detect cycle in different dfs trees
  for (int i = 0; i < V; i++)
    if (dfs_helper(adj, i, visited, recStack))
      return true;

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
