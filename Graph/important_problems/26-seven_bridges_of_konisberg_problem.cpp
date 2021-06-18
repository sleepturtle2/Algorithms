//https://www.geeksforgeeks.org/paths-travel-nodes-using-edgeseven-bridges-konigsberg/

//if there is any eulerian path in the graph, solution exists
//print euler tour

#include <bits/stdc++.h>
#include "../graph headers/unweighted_undirected.h"
using namespace std;

//dfs function to count reachable vertices from v
int DFSCount(vector<vector<int>> &adj, int u, vector<bool> &visited)
{
  visited[u] = true;
  int count = 1;

  for (int v : adj[u])
    if (v != -1 && !visited[v])
      count += DFSCount(adj, v, visited);

  return count;
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void removeEdge(vector<vector<int>> &adj, int u, int v)
{
  //find adj of u and replace with -1
  vector<int>::iterator it = find(adj[u].begin(), adj[u].end(), v);
  *it = -1;
}

//function to check if edge u-v can be considered as next edge in euler tour
bool isValidNextEdge(vector<vector<int>> &adj, int V, int u, int v)
{
  //valid under 2 conditions:

  //1- if v is the only adjacent of u
  int count = 0;
  for (int i : adj[u])
    if (i != -1)
      count++;

  if (count == 1)
    return true;

  //2- u-v is not a bridge (for multiple adjacents of u)

  //steps to check if u-v is a bridge
  //2-a - count of vertices reachable from u
  vector<bool> visited(V, false);
  int count1 = DFSCount(adj, u, visited);

  //2-b - remove edge(u,v) and after removing count vertices reachable from u
  removeEdge(adj, u, v);
  visited.assign(V, false);
  int count2 = DFSCount(adj, u, visited);

  //2-c- add edge back to the graph
  addEdge(adj, u, v);

  //2-d- if count1 > count2 , edge(u,v) is a bridge
  // if it is a bridge, v cannot be the next edge
  return (count1 > count2) ? false : true;
}

//print euler tour starting from vertex v
void printEulerUtil(vector<vector<int>> &adj, int V, int u)
{
  for (int v : adj[u])
  {

    //if edge u-v is not removed and it is a valid next edge
    if (v != -1 && isValidNextEdge(adj, V, u, v))
    {
      cout << u << "-" << v << " ";
      removeEdge(adj, u, v);
      printEulerUtil(adj, V, v);
    }
  }
}

//function to print eulerian trail
//first finds an odd degree vertex(if any) and then calls printEulerUtil()
void printEulerTour(vector<vector<int>> &adj, int V)
{
  //find a vertex with odd degree
  int u = 0;

  for (int i = 0; i < V; i++)
    if (adj[i].size() & 1)
    {
      u = i;
      break;
    }

  //print tour starting from the odd vertex
  printEulerUtil(adj, V, u);
  cout << endl;
}
int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj8;
  int V = adj.size();
  printEulerTour(adj, V);
  return 0;
}
