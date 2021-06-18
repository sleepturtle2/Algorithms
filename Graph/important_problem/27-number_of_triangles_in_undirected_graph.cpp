//https://www.geeksforgeeks.org/number-of-triangles-in-a-undirected-graph/
#include <bits/stdc++.h>
#include "../graph headers/unweighted_undirected.h"
using namespace std;

void multiply(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &c)
{
  int V = a.size();
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
    {
      c[i][j] = 0;
      for (int k = 0; k < V; k++)
        c[i][j] += a[i][k] * b[k][j];
    }
}

//sum of diagonal elements
int getTrace(vector<vector<int>> &graph)
{
  int V = graph.size();
  int trace = 0;
  for (int i = 0; i < V; i++)
    trace += graph[i][i];
  return trace;
}

int trianglesInGraph(vector<vector<int>> &graph)
{
  int V = graph.size();
  vector<vector<int>> aux2(V, vector<int>(V));
  vector<vector<int>> aux3(V, vector<int>(V));

  multiply(graph, graph, aux2); //to calculate graph^2
  multiply(graph, aux2, aux3);  //to calculate graph^3

  int trace = getTrace(aux3);

  return trace / 6; //because 3 vertices can be considered in 6 different ways
}

int main()
{
  vector<vector<int>> graph = {{0, 1, 1, 0},
                               {1, 0, 1, 1},
                               {1, 1, 0, 1},
                               {0, 1, 1, 0}};
  cout << "Total number of triangles in the graph\n";
  cout << trianglesInGraph(graph) << endl;
}
