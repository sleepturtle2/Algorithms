//https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<int> &color, int V)
{
  cout << "Solution exists\n";
  for (int i = 0; i < V; i++)
    cout << " " << color[i];
  cout << "\n";
}

//check if colored graph is safe or not
bool isSafe(vector<vector<bool>> &graph, vector<int> &color, int V)
{
  //check every edge
  for (int i = 0; i < V; i++)
    for (int j = i + 1; j < V; j++)
      if (graph[i][j] && color[j] == color[i])
        return false;

  return true;
}

//may be more solutions. this just prints one of the solutions
bool graphColoring(vector<vector<bool>> &graph, int V, int m, int i, vector<int> &color)
{
  //if current index reached end
  if (i == V)
  {
    //if coloring is safe
    if (isSafe(graph, color, V))
    {
      printSolution(color, V);
      return true;
    }
    return false;
  }

  //assign each color from 1 to m
  for (int j = 1; j <= m; j++)
  {
    color[i] = j;

    //recur for the rest of the vertices
    if (graphColoring(graph, V, m, i + 1, color))
      return true;
  }
  return false;
}
int main()
{
  vector<vector<bool>> graph = {
      {0, 1, 1, 1},
      {1, 0, 1, 0},
      {1, 1, 0, 1},
      {1, 0, 1, 0},
  };
  int m = 3; //number of colors
  int V = graph.size();
  vector<int> color(V);
  if (!graphColoring(graph, V, m, 0, color))
    cout << "Solution does not exist\n";
  return 0;
}
