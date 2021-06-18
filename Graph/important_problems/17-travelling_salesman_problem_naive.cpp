#include <bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>> &graph, int source)
{
  int V = graph.size();
  vector<int> vertex; //store all but the source vertex
  for (int i = 0; i < V; i++)
    if (i != source)
      vertex.push_back(i);

  //store minimum weight hamiltonian cycle
  int min_path = INT_MAX;
  do
  {
    //store current path weight(cost)
    int current_pathweight = 0;

    //compute current path weight
    int k = source;
    for (int i = 0; i < vertex.size(); i++)
    {
      current_pathweight += graph[k][vertex[i]];
      k = vertex[i];
    }
    current_pathweight += graph[k][source];

    //update minimum
    min_path = min(min_path, current_pathweight);
  } while (next_permutation(vertex.begin(), vertex.end()));

  return min_path;
}

int main()
{
  vector<vector<int>> graph = {{0, 10, 15, 20},
                               {10, 0, 35, 25},
                               {15, 35, 0, 30},
                               {20, 25, 30, 0}};
  int source = 0;
  cout << tsp(graph, source) << endl;
}
