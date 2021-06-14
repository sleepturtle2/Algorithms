//https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/

#include <bits/stdc++.h>
#include "./graph headers/weighted_directed.h"
using namespace std;

//returns true if there is path from source s to sink t in residual graph. also fills parent[] to store the path
bool bfs(vector<vector<int>> &rGraph, int V, int s, int t, vector<int> &parent)
{
  //create a visited array and mark all vertices as not visited
  vector<bool> visited(V);

  //create a queue, enqueue source vertex and mark source vertex as visited
  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  //standard bfs loop
  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (int v = 0; v < V; v++)
    {
      if (!visited[v] && rGraph[u][v] > 0)
      {
        //if we find a connection to the sink node, then there is no point in BFS anymore. we just have to set its parent and can return true

        if (v == t)
        {
          parent[v] = u;
          return true;
        }

        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }
  //we did not reach sink in bfs, starting from source, so return false
  return false;
}

//max flow from s to t
int fordFulkerson(vector<vector<int>> &graph, int V, int s, int t)
{
  int u, v;

  //residual graph and make it equal to original graph
  vector<vector<int>> rGraph = graph;

  //array filled by bfs and to store the path
  vector<int> parent(V);

  int max_flow = 0; //no flow initially

  //augment flow while there is path from source to sink
  while (bfs(rGraph, V, s, t, parent))
  {
    //find residual capacity of the edges along the path filled by bfs. or we can say find the maximum fow through the path found
    int path_flow = INT_MAX;
    for (v = t; v != s; v = parent[v])
    {
      u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }

    //update residual capacities of the edges and reverse edges along the path
    for (v = t; v != s; v = parent[v])
    {
      u = parent[v];
      rGraph[u][v] -= path_flow;
      rGraph[v][u] += path_flow;
    }

    //add path flow to overall flow
    max_flow += path_flow;
  }
  //return the overall flow
  return max_flow;
}

int main()
{
  Graph *g = new Graph();
  vector<vector<pair<int, int>>> adj = g->adj2;
  int V = adj.size();

  vector<vector<int>> graph(V, vector<int>(V, 0));

  //create flow graph
  for (int i = 0; i < V; i++)
    for (pair<int, int> j : adj[i])
      graph[i][j.first] = j.second;
  cout << "The maximum possible flow is: " << fordFulkerson(graph, V, 0, V) << endl;
}
