//https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/
#include <bits/stdc++.h>
#include "../graph headers/weighted_undirected.h"
using namespace std;

bool pathMoreThanLengthK_Util(vector<vector<pair<int, int>>> &adj, int src, int K, vector<bool> &path)
{

  if (K <= 0)
    return true;

  for (pair<int, int> i : adj[src])
  {
    int v = i.first;
    int w = i.second;

    //if vertex is already there in path, then there is a cycle, ignore it
    if (path[v])
      continue;

    if (w >= K)
      return true;

    //else add to path
    path[v] = true;

    //if adjacent can provide longer path than k return true
    if (pathMoreThanLengthK_Util(adj, v, K - w, path))
      return true;

    //backtrack
    path[v] = false;
  }

  //if no adjacent can produce longer path return false
  return false;
}

bool pathMoreThanLengthK(vector<vector<pair<int, int>>> &adj, int src, int V, int K)
{
  vector<bool> path(V);
  path[src] = 1;

  return pathMoreThanLengthK_Util(adj, src, K, path);
}

int main()
{
  Graph *g = new Graph();
  vector<vector<pair<int, int>>> adj = g->adj;
  int V = adj.size();
  int src = 0;
  int K = 3;

  pathMoreThanLengthK(adj, src, V, K) ? cout << "Yes\n" : cout << "No\n";
}
