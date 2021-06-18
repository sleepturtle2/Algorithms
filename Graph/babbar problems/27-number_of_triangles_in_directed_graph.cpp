//https://www.geeksforgeeks.org/number-of-triangles-in-directed-and-undirected-graphs/
#include <bits/stdc++.h>
#include "../graph headers/unweighted_directed.h"
using namespace std;

int countTriangles(vector<vector<int>> &graph, bool isDirected)
{
  int count_triangle = 0;

  int V = graph.size();

  //count every possible triplet of edges in the graph
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      for (int k = 0; k < V; k++)
      {
        //check if triplet satisfies the condition
        if (graph[i][j] && graph[j][k] && graph[k][i])
          count_triangle++;
      }
    }
  }

  //if directed graph, 3 vertices can form 3 triangles
  //if undirected graph, 3 vertices can form 6 triangles
  isDirected ? count_triangle /= 3 : count_triangle /= 6;

  return count_triangle;
}

int main()
{
  vector<vector<int>> undirected_graph = {{0, 1, 1, 0},
                                          {1, 0, 1, 1},
                                          {1, 1, 0, 1},
                                          {0, 1, 1, 0}};
  vector<vector<int>> directed_graph = {{0, 0, 1, 0},
                                        {1, 0, 0, 1},
                                        {0, 1, 0, 0},
                                        {0, 0, 1, 0}};
  cout << "Number of triangles in the undirected graph: " << countTriangles(undirected_graph, false) << endl;
  cout << "Number of triangles in the directed graph: " << countTriangles(directed_graph, true) << endl;
}
