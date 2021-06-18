//https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
#include <bits/stdc++.h>
using namespace std;

class node
{
  //stores color and edges connected to the node
public:
  int color = 1;
  set<int> edges;
};

bool graphColoring(vector<node> &nodes, int V, int m)
{

  vector<bool> visited(V + 1);
  //maxColors used till now is 1 as all nodes are painted color 1
  int maxColors = 1;

  //bfs traversal from all unvisited starting points
  for (int start = 1; start <= V; start++)
  {
    if (visited[start])
      continue;

    visited[start] = true;
    queue<int> queue;
    queue.push(start);

    while (!queue.empty())
    {
      int top = queue.front();
      queue.pop();

      for (auto it = nodes[top].edges.begin(); it != nodes[top].edges.end(); it++)
      {
        //if color of the adjacent node is same, increase it by 1
        if (nodes[top].color == nodes[*it].color)
          nodes[*it].color += 1;

        maxColors = max(maxColors, max(nodes[top].color, nodes[*it].color));
        if (maxColors > m)
          return false;

        //if adjacent is not visited, mark it visited and push it to queue
        if (!visited[*it])
        {
          visited[*it] = true;
          queue.push(*it);
        }
      }
    }
  }
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
  vector<node> nodes(V + 1);

  //add edges to node
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (graph[i][j])
      {
        //connect undirected graph
        nodes[i].edges.insert(j);
        nodes[j].edges.insert(i);
      }
    }
  }

  graphColoring(nodes, V, m) ? cout << "Possible\n" : cout << "Not Possible\n";
}
