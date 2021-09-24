//https://www.geeksforgeeks.org/two-clique-problem-check-graph-can-divided-two-cliques/
#include <bits/stdc++.h>
using namespace std;

//graph can be divided into two cliques if its complement graph is bipartite

bool isBipartiteUtil(vector<vector<int>> &graph, int src, vector<int> &color)
{
  color[src] = 1;

  queue<int> queue;
  queue.push(src);

  while (!queue.empty())
  {
    int u = queue.front();
    queue.pop();

    for (int v = 0; v < graph.size(); v++)
    {
      //edge from u to v exists and destination is not colored
      if (graph[u][v] && color[v] == -1)
      {
        //assign alternate color as that of adjacent
        color[v] = 1 - color[u];
        queue.push(v);
      }

      //edge from u to v exists and destination v is colored with same color as u
      else if (graph[u][v] && color[v] == color[u])
        return false;
    }
  }
  //all adjacent vertices can be colored with alternate color
  return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
  vector<int> color(graph.size(), -1);

  //check not yet colored vertices
  for (int i = 0; i < graph.size(); i++)
    if (color[i] == -1)
      if (!isBipartiteUtil(graph, i, color))
        return false;

  return true;
}

bool canBeDividedInTwoCliques(vector<vector<int>> &graph)
{
  int V = graph.size();

  //complement of graph
  //all values are complemented except diagonal ones
  vector<vector<int>> graph_c(V, vector<int>(V));
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      graph_c[i][j] = (i != j) ? !graph[i][j] : 0;

  //return true if complement is bipartite
  return isBipartite(graph_c);
}

int main()
{
  vector<vector<int>> graph = {{0, 1, 1, 1, 0},
                               {1, 0, 1, 0, 0},
                               {1, 1, 0, 0, 0},
                               {0, 1, 0, 0, 1},
                               {0, 0, 0, 1, 0}};
  int n; 
  cin>>n; 
  cout<<n; 
  canBeDividedInTwoCliques(graph) ? cout << "Yes\n" : cout << "No\n";
}
