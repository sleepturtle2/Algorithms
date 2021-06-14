//https://www.geeksforgeeks.org/bipartite-graph/
#include <bits/stdc++.h>
#include "./graph headers/unweighted_directed.h"
using namespace std;

bool isBipartite(vector<vector<int>> &adj, int V)
{
  //vector to store color of vertex
  //assigning all to -1, ie uncolored
  //uncolored vertices will be colored either 0 or 1
  vector<int> color(V, -1);

  //queue for bfs storing {vertex, color}
  queue<pair<int, int>> q;

  //loop in case graph is not connected
  for (int i = 0; i < V; i++)
  {
    //if not colored
    if (color[i] == -1)
    {
      //coloring with 0
      q.push({i, 0});
      color[i] = 0;
    }

    while (!q.empty())
    {
      pair<int, int> p = q.front();
      q.pop();

      //current vertex
      int v = p.first;
      //color of current vertex
      int c = p.second;

      //traversing vertices connected to current vertex
      for (int j : adj[v])
      {
        //if already colored with parent vertex color then bipartite graph is not possible
        if (color[j] == c)
          return false;
        //if uncolored
        if (color[j] == -1)
        {
          //coloring with opposite color of parent
          color[j] = c ? 0 : 1;
          q.push({j, color[j]});
        }
      }
    }
  }
  //if all vertices are colored such that no two connected vertices have same colors
  return true;
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj;
  int V = adj.size();
  isBipartite(adj, V) ? cout << "Yes\n" : cout << "No\n";
}
