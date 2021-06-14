//https://www.geeksforgeeks.org/eulerian-path-and-circuit/

#include <bits/stdc++.h>
#include "./graph headers/unweighted_undirected.h"
using namespace std;

void DFSUtil(vector<vector<int>> &adj, int u, vector<bool> &visited)
{
  visited[u] = true;

  for (int v : adj[u])
    if (!visited[v])
      DFSUtil(adj, v, visited);
}

bool isConnected(vector<vector<int>> &adj, int V)
{
  vector<bool> visited(V);

  int i;
  //find a vertex with non-zero degree
  for (i = 0; i < V; i++)
    if (adj[i].size() != 0)
      break;

  //if no edges in the graph, return true
  if (i == V)
    return true;

  //start DFS traversal from a verte
  DFSUtil(adj, i, visited);

  //check if all non-zero degree vertices are visited
  for (i = 0; i < V; i++)
    if (!visited[i] && adj[i].size() > 0)
      return false;
  return true;
}

int isEulerian(vector<vector<int>> &adj, int V)
{
  if (!isConnected(adj, V))
    return 0;

  int odd_count = 0; //count of vertices with odd degree

  for (int i = 0; i < V; i++)
    if (adj[i].size() & 1)
      odd_count++;

  //graph is not eulerian
  if (odd_count > 2)
    return 0;

  //if count is 2, semi-eulerian
  //if count is 0, eulerian
  //note that count can never be 1 for undirected graph
  return odd_count ? 1 : 2;
}

void test(vector<vector<int>> &adj, int V)
{
  int res = isEulerian(adj, V);
  if (res == 0)
    cout << "Graph is not Eulerian\n";
  else if (res == 1)
    cout << "Graph has an Euler path\n";
  else
    cout << "Graph has an Euler cycle\n";
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj1 = g->adj;
  int V1 = adj1.size();
  test(adj1, V1); // not Eulerian

  vector<vector<int>> adj2 = g->adj5;
  int V2 = adj2.size();
  test(adj2, V2); //has an Eulerian cycle

  vector<vector<int>> adj3 = g->adj4;
  int V3 = adj3.size();
  test(adj3, V3); // has an Eulerian path
  return 0;
}
