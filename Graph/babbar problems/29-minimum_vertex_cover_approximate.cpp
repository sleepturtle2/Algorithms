//https://www.geeksforgeeks.org/vertex-cover-problem-set-1-introduction-approximate-algorithm-2/
#include <bits/stdc++.h>
#include "../graph headers/unweighted_undirected.h"
using namespace std;

void printVertexCover(vector<vector<int>> &adj)
{
  int V = adj.size();
  vector<bool> visited(V);

  for (int u = 0; u < V; u++)
  {
    //edge is only picked when both visited[u] and visited[v] are false
    if (!visited[u])
    {
      //pick an (u,v) from remaining edges
      for (int v : adj[u])
      {
        if (!visited[v])
        {
          //add the vertices(u,v) to the result set
          //we make u-v visited so that all edges from/to them will be ignored
          visited[v] = true;
          visited[u] = true;
          break;
        }
      }
    }
  }

  //print the vertex cover
  for (int i = 0; i < V; i++)
    if (visited[i])
      cout << i << " ";
  cout << endl;
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj;
  printVertexCover(adj);
}
