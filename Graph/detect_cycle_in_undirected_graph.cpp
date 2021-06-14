//https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
#include <bits/stdc++.h>
#include "./graph headers/unweighted_undirected.h"
using namespace std;

bool isCyclicUtil(vector<vector<int>> &adj, int v, vector<bool> &visited, int parent)
{
  visited[v] = true;

  for (int i : adj[v])
  {

    //recur if adjacent is not visited
    if (!visited[i])
    {
      if (isCyclicUtil(adj, i, visited, v))
        return true;
    }

    //if adjacent vertex is visited and is not parent of current vertex, there exists a cycle in the graph
    else if (i != parent)
      return true;
  }
  return false;
}

bool isCyclic(vector<vector<int>> &adj, int V)
{
  vector<bool> visited(V);

  for (int u = 0; u < V; u++)
  {
    if (!visited[u])
      if (isCyclicUtil(adj, u, visited, -1))
        return true;
  }

  return false;
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj;
  int V = adj.size();
  isCyclic(adj, V) ? cout << "Graph contains a cycle\n" : cout << "Graph does not contain a cycle\n";
  return 0;
}
