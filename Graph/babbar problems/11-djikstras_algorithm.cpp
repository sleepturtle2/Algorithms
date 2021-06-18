//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/

#include <bits/stdc++.h>
#include "../graph headers/weighted_directed.h"
using namespace std;

void shortestPath(vector<vector<pair<int, int>>> &adj, int V, int source)
{

  //set of vertices being processed
  set<pair<int, int>> set; //(distance, vertex) format

  //vector for distances from source
  vector<int> dist(V, INT_MAX);

  //insert source in set and set distance to 0
  set.insert(make_pair(0, source));
  dist[source] = 0;

  //looping till all shortest distances are finalized then set will be empty
  while (!set.empty())
  {
    //first vertex in set is the minimum distance vertex
    pair<int, int> current = *(set.begin());
    set.erase(set.begin());

    int u = current.second;

    for (pair<int, int> i : adj[u])
    {
      int v = i.first;
      int weight = i.second;

      //if there is shorter path to v through u
      if (dist[v] > dist[u] + weight)
      {

        /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here.  */
        if (dist[v] != INT_MAX)
          set.erase(set.find(make_pair(dist[v], v)));

        //updating distance of v
        dist[v] = dist[u] + weight;
        set.insert(make_pair(dist[v], v));
      }
    }
  }

  //print shortest distances stored in dist[]
  cout << "Shortest distances from source " << source << ":" << endl;
  for (int d : dist)
    cout << d << " ";
  cout << endl;
}

int main()
{
  Graph *g = new Graph();
  vector<vector<pair<int, int>>> adj = g->adj;
  int V = adj.size();
  int source = 0;
  shortestPath(adj, V, source);
}
