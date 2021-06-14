//https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
#include <bits/stdc++.h>
#include "./graph headers/unweighted_directed.h"
using namespace std;

bool isCyclicUtil(vector<vector<int>> &adj, int v, vector<bool> &visited, vector<bool> &recStack)
{
  if (!visited[v])
  {
    visited[v] = true;
    recStack[v] = true;

    for (int i : adj[v])
    {
      if (!visited[i] && isCyclicUtil(adj, i, visited, recStack))
        return true;
      else if (recStack[i])
        return true;
    }
  }
  recStack[v] = false; //remove the vertex from the recursion stack
  return false;
}

bool isCyclic(vector<vector<int>> &adj, int V)
{

  vector<bool> visited(V);
  vector<bool> recStack(V);

  for (int i = 0; i < V; i++)
    if (isCyclicUtil(adj, i, visited, recStack))
      return true;

  return false;
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj;
  int V = adj.size();
  isCyclic(adj, V) ? cout << "Contains cycle" : cout << "Does not contain cycle\n";
  return 0;
}
