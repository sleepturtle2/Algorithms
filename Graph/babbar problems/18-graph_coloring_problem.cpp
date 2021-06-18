//https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/
#include <bits/stdc++.h>
#include "../graph headers/unweighted_undirected.h"
using namespace std;

//assign colors(starting from 0) to all vertices and prints the assignment of colors
void greedyColoring(vector<vector<int>> &adj, int V)
{
  vector<int> result(V, -1); //initialize vertices as unassigned

  //assign the first color to first vertex
  result[0] = 0;

  //temp array to store the available colors
  //true value of available[cr] would mean the color cr is assigned to one of its adjacent vertices
  vector<bool> available(V);

  //assign colors to remaining V-1 vertices
  for (int u = 1; u < V; u++)
  {
    //process all adjacent vertices and flag their colors as unavailable
    for (int i : adj[u])
      if (result[i] != -1)
        available[result[i]] = true;

    //find the first available color
    int color;
    for (color = 0; color < V; color++)
      if (available[color] == false)
        break;

    result[u] = color; //assign found color

    //reset the values back to false for the next iteration
    for (int i : adj[u])
      if (result[i] != -1)
        available[result[i]] = false;
  }

  //print result
  for (int u = 0; u < V; u++)
    cout << "Vertex " << u << " --> Color " << result[u] << endl;
}

int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj;
  int V = adj.size();
  cout << "Coloring of graph\n";
  greedyColoring(adj, V);
}
