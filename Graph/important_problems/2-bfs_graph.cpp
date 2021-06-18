#include <bits/stdc++.h>
#include "../graph headers/unweighted_directed.h"
using namespace std;

void BFS(vector<vector<int>> &adj, int V, int source)
{
  vector<bool> visited(V);

  queue<int> queue;

  visited[source] = true;
  queue.push(source);

  while (!queue.empty())
  {
    int u = queue.front();
    cout << u << " ";
    queue.pop();

    for (int v : adj[u])
    {
      if (!visited[v])
      {
        visited[v] = true;
        queue.push(v);
      }
    }
  }
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj;
  int V = adj.size();

  int source = 0;
  cout << "BFS with source " << source << endl;
  BFS(adj, V, source);
}
