#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
public:
  map<T, bool> visited;
  map<T, list<int>> adj;

  void addEdge(T u, T v, bool bidirectional = 1) //undirected by default
  {
    adj[u].push_back(v);

    if (bidirectional)
      adj[v].push_back(u);
  }

  void DFS(T v)
  {
    visited[v] = true;
    cout << v << " ";

    for (auto vertex : adj[v])
      if (!visited[vertex])
        DFS(vertex);
  }
};

int main()
{
  Graph<int> g;

  g.addEdge(0, 1);
  g.addEdge(0, 9);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(9, 3);

  int source = 2;
  cout << "DFS starting from " << source << endl;
  g.DFS(source);
  cout << endl;

  return 0;
}
