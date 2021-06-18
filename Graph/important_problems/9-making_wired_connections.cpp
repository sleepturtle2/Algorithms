//https://www.geeksforgeeks.org/minimize-count-of-connections-required-to-be-rearranged-to-make-all-the-computers-connected/

#include <bits/stdc++.h>
using namespace std;

void DFS(unordered_map<int, vector<int>> &adj, int node, vector<bool> &visited)
{
  if (visited[node])
    return;

  visited[node] = true;

  for (auto x : adj[node])
    if (!visited[x])
      DFS(adj, x, visited);
}

int makeConnectedUtil(int N, vector<vector<int>> &connections, int M)
{

  vector<bool> visited(N);

  //build the adjacency list
  unordered_map<int, vector<int>> adj;

  //store count of edges
  int edges = 0;

  for (int i = 0; i < M; i++)
  {
    //add edges
    adj[connections[i][0]].push_back(connections[i][1]);
    adj[connections[i][1]].push_back(connections[i][0]);

    edges += 1;
  }

  //store count of components
  int components = 0;

  for (int i = 0; i < N; i++)
  {
    if (!visited[i])
    {
      components += 1;
      DFS(adj, i, visited);
    }
  }

  //at least N-1 edges are required
  if (edges < N - 1)
    return -1;

  //count redundant edges
  int redundant = edges - ((N - 1) - (components - 1));

  //check if components can be rearranged with redundant edges
  if (redundant >= (components - 1))
    return components - 1;

  return -1;
}

void makeConnected(int N, vector<vector<int>> &connections, int M)
{

  int minOps = makeConnectedUtil(N, connections, M);

  cout << minOps << endl;
}

int main()
{

  //number of computers
  int N = 4;

  vector<vector<int>> connections = {
      {0, 1}, {0, 2}, {1, 2}};

  int M = connections.size(); //number of connections

  makeConnected(N, connections, M);
  return 0;
}
