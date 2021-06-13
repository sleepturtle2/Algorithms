//https://www.geeksforgeeks.org/biconnectivity-in-a-graph/

#include <bits/stdc++.h>
#include "./graph headers/unweighted_undirected.h"
using namespace std;

bool isBiConnectedUtil(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent)
{
  static int time = 0;
  int children = 0;

  visited[u] = true;

  disc[u] = low[u] = ++time;

  for (int v : adj[u])
  {
    if (!visited[v])
    {
      children++;
      parent[v] = u;

      //check if subgraph rooted with v has an articulation point
      if (isBiConnectedUtil(adj, v, visited, disc, low, parent))
        return true;

      //check if subtree rooted with v has a connection to one of the ancestors of u
      low[u] = min(low[u], low[v]);

      //u is articulation point in the following cases:

      //u is a root of DFS tree and has two or more children
      if (parent[u] == -1 && children > 1)
        return true;

      //if u is not root and low value of one of it children is more than discovery value of u
      if (parent[u] != -1 && low[v] >= disc[u])
        return true;
    }

    //update low value of u for parent function calls
    else if (v != parent[u])
      low[u] = min(low[u], disc[v]);
  }
  return false;
}

bool isBiConnected(vector<vector<int>> &adj, int V)
{
  vector<bool> visited(V);
  vector<int> disc(V);
  vector<int> low(V);
  vector<int> parent(V, -1);

  //check for articulation points. do dfs traversal starting from vertex 0
  if (isBiConnectedUtil(adj, 0, visited, disc, low, parent))
    return false;

  //check if given graph is connected. any undirected graph is connected if all vertices are reachable from any point (we take 0 as starting point)
  for (int i = 0; i < V; i++)
    if (!visited[i])
      return false;

  return true;
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj1 = g->adj;
  vector<vector<int>> adj2 = g->adj2;

  int V1 = adj1.size();
  int V2 = adj2.size();

  isBiConnected(adj1, V1) ? cout << "Yes\n" : cout << "No\n";
  isBiConnected(adj2, V2) ? cout << "Yes\n" : cout << "No\n";

  return 0;
}

/* Output
Yes
No
*/
