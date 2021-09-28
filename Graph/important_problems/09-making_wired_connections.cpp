//https://www.geeksforgeeks.org/minimize-count-of-connections-required-to-be-rearranged-to-make-all-the-computers-connected/
/*
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 


Intuition: 
We know that there are n-1 edges in an MST. Now lets assume there are n-1 edges but the no of components is greater, ie, there are redundant edges in the same component 
but not enough to connect all components. Therefore, if edges >= n-1, the number of edges needed from that component, or all other components combined must be Components-1 (To
connect all components). 

Now if edges are a lot more than that, the redundant edges must be -> ( edges - ((N-1) - (Components - 1)) ) (Think about this!) 
*/
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
