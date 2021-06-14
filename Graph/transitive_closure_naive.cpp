//https://www.geeksforgeeks.org/transitive-closure-of-a-graph/
#include <bits/stdc++.h>
#include "unweighted_directed.h"
using namespace std;

//O(V^3)

void print(vector<vector<int>> &adj)
{
  cout << "Transitive closure\n";

  for (int i = 0; i < adj.size(); i++)
  {
    for (int j = 0; j < adj[i].size(); j++)
    {
      if (i == j)
        cout << "1 ";
      else
        cout << adj[i][j] << " ";
    }

    cout << "\n";
  }
}

//uses floyd warshall algorithm
void transitiveClosure(vector<vector<int>> &adj_mat, int V)
{

  //shortest distances between every pair of vertices
  //initialize it as input matrix
  vector<vector<int>> reach = adj_mat;

  for (int k = 0; k < V; k++)
  {
    //pick all vertices as source one by one
    for (int i = 0; i < V; i++)
    {
      //pick all vertices as destination for the above picked source
      for (int j = 0; j < V; j++)
      {
        //if vertex k is on a path from i to j, then make sure the value of reach[i][j] is 1
        reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
      }
    }
  }

  //print solution matrix
  print(reach);
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj3;
  int V = adj.size();
  vector<vector<int>> adj_mat(V, vector<int>(V));

  //create the adjacency matrix (directed)
  for (int i = 0; i < V; i++)
    for (int v : adj[i])
      adj_mat[i][v] = 1;

  // for (int i = 0; i < V; i++)
  // {
  //   for (int j = 0; j < V; j++)
  //     cout << adj_mat[i][j] << " ";
  //   cout << "\n";
  // }

  transitiveClosure(adj_mat, V);
  return 0;
}
