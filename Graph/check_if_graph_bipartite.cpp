//https://www.geeksforgeeks.org/bipartite-graph/
/*
Algorithm to check if a graph is Bipartite: 
One approach is to check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem. 
Following is a simple algorithm to find out whether a given graph is Bipartite or not using Breadth First Search (BFS). 
1. Assign RED color to the source vertex (putting into set U). 
2. Color all the neighbors with BLUE color (putting into set V). 
3. Color all neighbor’s neighbor with RED color (putting into set U). 
4. This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2. 
5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite) 
*/
#include <bits/stdc++.h>
#include "./graph_headers/unweighted_directed.h"
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
