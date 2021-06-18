#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

void floydWarshall(vector<vector<int>> &graph)
{
  vector<vector<int>> dist = graph; //shortest distance matrix
  int i, j, k;
  int V = graph.size();

  for (k = 0; k < V; k++)
  {
    for (i = 0; i < V; i++)
      for (j = 0; j < V; j++)
        if ((dist[i][j] > (dist[i][k] + dist[k][j])) && dist[i][k] != INF && dist[k][j] != INF)
          dist[i][j] = dist[i][k] + dist[k][j];
  }

  //print solution
  for (i = 0; i < V; i++)
  {

    for (j = 0; j < V; j++)
    {
      if (dist[i][j] == INF)
        cout << "INF"
             << " ";
      else
        cout << dist[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  vector<vector<int>> graph = {{0, 5, INF, 10},
                               {INF, 0, 3, INF},
                               {INF, INF, 0, 1},
                               {INF, INF, INF, 0}};
  floydWarshall(graph);
}
