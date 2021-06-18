//https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<bool>> &graph, vector<int> &color, int c)
{
  for (int i = 0; i < graph.size(); i++)
    if (graph[v][i] && c == color[i])
      return false;
  return true;
}

void printSolution(vector<int> &color, int V)
{
  cout << "Solution exists\n";
  for (int i = 0; i < V; i++)
    cout << color[i] << " ";
  cout << endl;
}

bool graphColoring_Util(vector<vector<bool>> &graph, int V, int m, vector<int> &color, int v)
{

  //if all vertices are assigned to a color
  if (v == V)
    return true;

  //consider this vertex v and try different colors
  for (int c = 1; c <= m; c++)
  {
    //check if assignment of color to v is fine
    if (isSafe(v, graph, color, c))
    {
      color[v] = c;

      //assign color to the rest of the vertices
      if (graphColoring_Util(graph, V, m, color, v + 1))
        return true;

      //if assigning color c doesnt lead to a solution then remove it
      color[v] = 0;
    }
  }
  return false;
}

//prints one of the feasible functions
bool graphColoring(vector<vector<bool>> &graph, int m, int V, vector<int> &color)
{

  //call util method for vertex 0
  if (graphColoring_Util(graph, V, m, color, 0) == false)
  {
    cout << "solution does not exist\n";
    return false;
  }

  printSolution(color, V);
  return true;
}

int main()
{
  vector<vector<bool>> graph = {
      {0, 1, 1, 1},
      {1, 0, 1, 0},
      {1, 1, 0, 1},
      {1, 0, 1, 0},
  };
  int m = 3;
  int V = graph.size();
  vector<int> color(V);

  if (!graphColoring(graph, m, V, color))
    cout << "Solution does not exist\n";
}
