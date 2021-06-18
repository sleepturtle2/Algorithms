//https://www.geeksforgeeks.org/minimum-edges-reverse-make-path-source-destination/
#include <bits/stdc++.h>
#include "../graph headers/unweighted_directed.h"
using namespace std;

//prints shortest path from source to all other vertices
vector<int> shortestPath(vector<list<pair<int, int>>> &graph, int V, int src)
{

  //set of vertices being processed
  set<pair<int, int>> set;

  vector<int> dist(V, INT_MAX);

  //insert source and initialize distance as 0
  set.insert(make_pair(0, src));
  dist[src] = 0;

  while (!set.empty())
  {
    //minimum distance vertex
    pair<int, int> current = *(set.begin());
    set.erase(set.begin());

    int u = current.second;

    list<pair<int, int>>::iterator it;
    for (it = graph[u].begin(); it != graph[u].end(); it++)
    {
      int v = (*it).first;
      int weight = (*it).second;

      //if there is shorter path to v through u
      if (dist[v] > dist[u] + weight)
      {

        if (dist[v] != INT_MAX)
          set.erase(set.find(make_pair(dist[v], v)));

        dist[v] = dist[u] + weight;
        set.insert(make_pair(dist[v], v));
      }
    }
  }
  return dist;
}

//method adds reverse edge of each original edge in the graph. it gives reverse edge a weight of 1 and all original edges a weight of 0. the length of the shortest path will give us the answer. if shortest path is p, it means we used p reverse edges in the shortest path
vector<list<pair<int, int>>> modelGraphWithEdgeWeight(vector<pair<int, int>> &edges, int E, int V)
{
  vector<list<pair<int, int>>> graph(V);

  for (int i = 0; i < E; i++)
  {
    //original edge weight 0
    graph[edges[i].first].push_back({edges[i].second, 0});

    //reverse edge weight 1
    graph[edges[i].second].push_back({edges[i].first, 1});
  }
  return graph;
}
int getMinEdgeReversal(vector<pair<int, int>> &edges, int E, int V, int src, int dest)
{
  vector<list<pair<int, int>>> graph = modelGraphWithEdgeWeight(edges, E, V);
  vector<int> dist = shortestPath(graph, V, src);

  if (dist[dest] == INT_MAX)
    return -1;
  else
    return dist[dest];
}
int main()
{
  Graph *g = new Graph();
  vector<vector<int>> graph = g->adj;
  //create edges
  vector<pair<int, int>> edges;
  int E = 0;
  set<int> vertices;
  for (int i = 0; i < graph.size(); i++)
    for (int j = 0; j < graph[i].size(); j++)
    {
      edges.push_back({i, j});
      E++;
      vertices.insert(i);
      vertices.insert(j);
    }
  int V = vertices.size();
  int src = 0;
  int dest = 6;
  int minEdgesToReverse = getMinEdgeReversal(edges, E, V, src, dest);

  minEdgesToReverse == -1 ? cout << "Not Possible\n" : cout << minEdgesToReverse << endl;
}
