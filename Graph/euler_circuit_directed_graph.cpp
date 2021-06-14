//https://www.geeksforgeeks.org/euler-circuit-directed-graph/
#include <bits/stdc++.h>
#include "./graph headers/unweighted_directed.h"
using namespace std;

void DFSUtil(vector<vector<int>> &adj, int V, int v, vector<bool> &visited)
{
  visited[v] = true;

  for (int i : adj[v])
    if (!visited[i])
      DFSUtil(adj, V, i, visited);
}

//returns transpose of the graph
vector<vector<int>> getTranspose(vector<vector<int>> &adj, vector<int> &in, int V)
{

  vector<vector<int>> new_adj(V);

  for (int i = 0; i < V; i++)
    for (int j : adj[i])
    {
      new_adj[j].push_back(i);
      in[i]++;
    }
  return new_adj;
}

//returns true if all non-zero degree vertices of graph are strongly connected
bool isSC(vector<vector<int>> &adj, int V, vector<int> &in)
{
  vector<bool> visited(V);

  //find first vertex with non-zero degree
  int start;
  for (start = 0; start < V; start++)
    if (adj[start].size())
      break;

  //do DFS traversal starting from first non-zero degree vertex
  DFSUtil(adj, V, start, visited);

  //if dfs traverasl does not visit all vertices, return false;
  for (int i = 0; i < V; i++)
    if (adj[i].size() && !visited[i])
      return false;

  vector<vector<int>> new_adj = getTranspose(adj, in, V);

  //mark all vertices as not visited for the second dfs
  visited.assign(V, false);

  //do dfs for reversed graph starting from first vertex
  //start point must be same as first dfs
  DFSUtil(new_adj, V, start, visited);

  //if all vertices are not visited in the second dfs, return false
  for (int i = 0; i < V; i++)
    if (adj[i].size() && !visited[i])
      return false;

  return true;
}

bool isEulerianCycle(vector<vector<int>> &adj, int V)
{
  vector<int> in(V);
  //check if all non-zero degree vertices are connected
  if (isSC(adj, V, in) == false)
    return false;

  //check if indegree and outdegree of every vertex is same
  for (int i = 0; i < V; i++)
    if (adj[i].size() != in[i])
      return false;

  return true;
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj1 = g->adj5;
  int V = adj1.size();
  isEulerianCycle(adj1, V) ? cout << "Eulerian Graph\n" : cout << "Not an Eulerian Graph\n";

  vector<vector<int>> adj2 = g->adj;
  int V2 = adj2.size();
  isEulerianCycle(adj2, V2) ? cout << "Eulerian Graph\n" : cout << "Not an Eulerian Graph\n";
  return 0;
}
