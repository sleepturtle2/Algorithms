//https://www.geeksforgeeks.org/biconnected-components/

#include <bits/stdc++.h>
#include "./graph headers/unweighted_undirected.h"
using namespace std;
#define mp make_pair

int count = 0;

void BiConnectedComponentsUtil(vector<vector<int>> &adj, int u, vector<int> &disc, vector<int> &low, list<pair<int, int>> &edge_stack, vector<int> &parent, int &count)
{
  static int time = 0;

  disc[u] = low[u] = ++time;
  int children = 0;

  //all adjacent vertices
  for (int v : adj[u])
  {

    //recur for unvisited vertices
    if (disc[v] == -1)
    {
      children++;
      parent[v] = u;

      //store edge in Stack
      edge_stack.push_back(mp(u, v));
      BiConnectedComponentsUtil(adj, v, disc, low, edge_stack, parent, count);

      //check if subtree rooted with v has a connection to one of the ancestors of u
      low[u] = min(low[u], low[v]);

      //if u is an articulation point, pop all edges from stack till u-v
      if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u]))
      {
        while (edge_stack.back() == mp(u, v) || edge_stack.back() == mp(v, u))
        {
          cout << edge_stack.back().first << " " << edge_stack.back().second;
          edge_stack.pop_back();
        }

        cout << edge_stack.back().first << " " << edge_stack.back().second;
        edge_stack.pop_back();
        cout << endl;
        count++;
      }
    }

    //update low value of u only if v is still in stack (ie it is a back edge, not a cross edge)

    else if (v != parent[u])
    {
      low[u] = min(low[u], disc[v]);
      if (disc[v] < disc[u])
      {
        edge_stack.push_back(mp(u, v));
      }
    }
  }
}

void BiConnectedComponents(vector<vector<int>> &adj, list<pair<int, int>> &edge_stack, int V)
{
  vector<int> disc(V, -1);
  vector<int> low(V, -1);
  vector<int> parent(V, -1);

  int count = 0;
  for (int i = 0; i < V; i++)
  {
    if (disc[i] == -1)
      BiConnectedComponentsUtil(adj, i, disc, low, edge_stack, parent, count);

    int j = 0;
    //if stack is not empty, pop all edges from stack
    while (edge_stack.size())
    {
      j = 1;
      cout << edge_stack.back().first << "--" << edge_stack.back().second << " ";
      edge_stack.pop_back();
    }
    if (j == 1)
    {
      cout << endl;
      count++;
    }
  }
}
int main()
{
  Graph *g = new Graph();
  vector<vector<int>> adj = g->adj3;
  int V = adj.size();
  list<pair<int, int>> edges = g->edges3;
  BiConnectedComponents(adj, edges, V);
  return 0;
}
